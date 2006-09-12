
/*
 * ITVal: The IPTables Firewall Validator Copyright (C) 2004 Robert
 * Marmorstein
 * 
 * This program is free software; you can redistribute it and/or modify it 
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along 
 * with this program; if not, write to the Free Software Foundation, Inc., 
 * 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. A full-text
 * version is located in the LICENSE file distributed with this utility.
 * 
 * You may contact the author at rmmarm@wm.edu or by sending mail to:
 * 
 * Robert Marmorstein Department of Computer Science College of William
 * and Mary Williamsburg, VA 23185 
 */

/* rule_file should be generated by iptables -L -n so 
 * that it generates numeric addresses and port numbers.
 */

//#define DEBUG

#include <unistd.h>
#include <stdio.h>

#ifndef HAVE_GETLINE
ssize_t getline(char **, size_t *, FILE *);
#endif

#include <errno.h>

#include "rule_parser.h"
#include "rules.h"
#include "nat.h"
#include "ranges.h"
#include "iface.h"
#include "chains.h"
#include "debug.h"
#include "firewall.h"

// Read the name of a Chain from the rule file
void Firewall::ReadChain(char *line, ssize_t length, chain * newChain)
{
   char dummy[8];                         // The word CHAIN 
   char name[257];                        // The name of the chain

   char spam[257];                        // Dummy characters that surround

   // the default policy.

   sscanf(line, "%7s %256s %7s %256s", dummy, name, dummy, spam);

   strncpy(newChain->name, name, 256);
   newChain->Default = 0;       // Assume PASS if no default is specified.

   // The default policy can only be "ACCEPT" or "DROP".
   if (strncmp(&dummy[1], "policy", 6) == 0) {
      if (spam[0] == 'D')
         newChain->Default = 1; // DROP
      else if (spam[0] == 'A')
         newChain->Default = 3; // ACCEPT
      else {
         printf("Chain %s has invalid default policy %s\n", name, spam);
         exit(-1);
      }
   }
}

// Construct two MDDs from the firewall ruleset.  The first, outputMDD,
// represents the set of accepted packets.  The second, Logged,
// represents the set of packets that MAY be logged.

void Firewall::BuildFWRules(char *fname)
{
   FILE *ruleFile;
   char *line;                            // Current line of input
   char *oldLine;                         // Placeholder so that we can free the

   // line

   // After we've modified it.

   ssize_t length;                        // Length of the input line
   size_t bufsize;

   rule *cur;                             // Current rule to process
   processed_rule *pcur;                  // Current expanded rule

   chain *newChain;                       // Current Chain to build
   int current_chain;                     // Index (in the chain_array) of the
   // chain. 

   rule_parser *rp;

   int lineNo;

   int i;

   lineNo = 0;
   num_chains = 0;

   ruleFile = fopen(fname, "r");
   if (!ruleFile) {
      perror("ITVal: Opening Filter Rules");
      exit(errno);
   }

   line = NULL;
   oldLine = NULL;
   current_chain = -1;
   newChain = NULL;
   phead = NULL;

   rp = new rule_parser(T);

   // First, parse the rule file into rule structs.
   cur = new rule;
   length = getline(&line, &bufsize, ruleFile);
   lineNo++;
   oldLine = line;
   if (line == NULL || strstr(line, "Chain") < 0) {
      printf("File <%s> is not a valid rule file.\n", fname);
      exit(-1);
   }

   while (length != -1) {
      // Consume Whitespace
      while (length > 0 && (*line == '\n')) {
         line++;
         length--;
      }
      // if (line[0]=='#') //If the line is a comment, ignore.
      // break;

      if (length == 0) {        // If the line is empty, ignore.
         free(oldLine);
         line = NULL;
         length = getline(&line, &bufsize, ruleFile);
         lineNo++;
         oldLine = line;
         if (length == -1)      // If at the end of the file, done.
            break;
         continue;              // Skip processing the line.
      }
      // If the line defines a new chain

      if (strncmp(line, "Chain", 5) == 0) {
         // Delete the empty rule 
         // (We always create one more than we need)
         // delete cur;

         // Allocate a new chain 
         newChain = new chain(fname);

         // Grab its name from the input line
         ReadChain(line, length, newChain);

#ifdef DEBUG
         if (newChain == NULL) {
            printf("%d: Bad chain definition\n", lineNo);
            exit(-1);
         }
         printf("%d: Chain %s[%d]\n", lineNo, newChain->name,newChain->id);
#endif

         current_chain++;
         // Set number of chains
         num_chains = current_chain + 1;

         chain_array[current_chain] = newChain;
         cur->chain_id = chain_array[current_chain]->id;

         // Allocate the first rule
         // cur = new rule;

         // Consume the "header display" line
         free(oldLine);
         line = NULL;
         length = getline(&line, &bufsize, ruleFile);
         lineNo++;
         oldLine = line;

         // Priming read
         free(oldLine);
         line = NULL;
         length = getline(&line, &bufsize, ruleFile);
         lineNo++;
         oldLine = line;

         if (length == -1)      // IF EOF, done.
            break;
      }
      else {
         // Read the next rule
         if (rp->ReadRule(cur, line, length) >= 0)      //Normal input
         {
            // Append to the linked list for the current chain
            cur->next = chain_array[current_chain]->rules;
            chain_array[current_chain]->rules = cur;

            cur->id = chain_array[current_chain]->numRules;
            chain_array[current_chain]->numRules++;

            // Allocate next rule
            cur = new rule;
	    cur->chain_id = chain_array[current_chain]->id;
         }
         // Do priming read
         free(oldLine);
         line = NULL;
         length = getline(&line, &bufsize, ruleFile);
         lineNo++;
         oldLine = line;
      }
   }
   free(oldLine);

   // We always create one more than we need, so free.
   delete cur;

   cur = NULL;
   fclose(ruleFile);
   ruleFile = NULL;


   // For every rule of every chain, we break the net/mask 
   // pairs into linked lists of integer ranges.  We also parse
   // the port and state information out of each rule.  The result
   // is stored in a processed_rule struct.

   i = 0;
   while (i < num_chains) {     // For each chain
      newChain = chain_array[i];
#ifdef DEBUG
      printf("Chain: %s\n", newChain->name);
#endif
      cur = newChain->rules;

      //If empty target, ignore the rule.
      while (cur && cur->target[0] == '\0') {
         cur = cur->next;
      }

      phead = NULL;

      // Allocate a processed_rule
      while (cur) {
#ifdef DEBUG
         PrintRule(*cur);
#endif
         // Convert cur to a processed_rule, storing it in pcur.
         pcur = new processed_rule;
         ProcessRule(cur, pcur, rp, T);

#ifdef DEBUG
         printf("=======\n");
         PrintProcessedRule(pcur);
         printf("*******\n");
#endif
         // Push onto head of the list
         pcur->next = phead;
         phead = pcur;

         // Allocate next rule
         cur = cur->next;

         //If empty target, ignore the rule.
         while (cur && cur->target[0] == '\0') {
            cur = cur->next;
         }
      }

      // Store the linked list of processedRules in the chain struct.
      newChain->newRules = phead;

      // Now convert the processed rules into vector tuples suitable
      // for insertion into the MDDs

      newChain->tup = NULL;     // <----- A very important step.
      BuildRules(phead, newChain->tup);
      i++;
      // Free the processed rules, since we don't need 'em anymore.
      while (newChain->newRules != NULL) {
         pcur = newChain->newRules;
         newChain->newRules = newChain->newRules->next;
         delete pcur;

         pcur = NULL;
      }
   }
   delete rp;
}

void Firewall::BuildVerboseFWRules(char *fname)
{
   FILE *ruleFile;
   char *line;                            // Current line of input
   char *oldLine;                         // Placeholder so that we can free the
   // line

   // After we've modified it.

   ssize_t length;                        // Length of the input line
   size_t bufsize;

   rule *cur;                             // Current rule to process
   processed_rule *pcur;                  // Current expanded rule

   chain *newChain;                       // Current Chain to build
   int current_chain;                     // Index (in the chain_array) of the
   // chain. 

   rule_parser *rp;

   int i;
   int lineNo;

   num_chains = 0;
   lineNo = 0;

   ruleFile = fopen(fname, "r");
   if (!ruleFile) {
      perror("ITVal: Opening Filter Rules");
      exit(errno);
   }

   line = NULL;
   oldLine = NULL;
   current_chain = -1;
   newChain = NULL;
   phead = NULL;

   rp = new rule_parser(T);

   // First, parse the rule file into rule structs.
   cur = new rule;
   length = getline(&line, &bufsize, ruleFile);
   lineNo++;
   oldLine = line;
   if (line == NULL || strstr(line, "Chain") < 0) {
      printf("File <%s> is not a valid rule file.\n", fname);
      exit(-1);
   }

   while (length != -1) {
      // Consume Whitespace
      while (length > 0 && (*line == '\n')) {
         line++;
         length--;
      }
      // if (line[0]=='#') //If the line is a comment, ignore.
      // break;

      if (length == 0) {        // If the line is empty, ignore.
         free(oldLine);
         line = NULL;
         length = getline(&line, &bufsize, ruleFile);
         lineNo++;
         oldLine = line;
         if (length == -1)      // If at the end of the file, done.
            break;
         continue;              // Skip processing the line.
      }
      // If the line defines a new chain

      if (strncmp(line, "Chain", 5) == 0) {
         // Delete the empty rule 
         // (We always create one more than we need)
         // delete cur;

         // Allocate a new chain 
         newChain = new chain(fname);

         // Grab its name from the input line
         ReadChain(line, length, newChain);

#ifdef DEBUG
         if (newChain == NULL) {
            printf("%d: Bad chain definition\n", lineNo);
            exit(-1);
         }
         printf("%d: Chain %s[%d]\n", lineNo, newChain->name,newChain->id);
#endif

         current_chain++;
         // Set number of chains
         num_chains = current_chain + 1;

         chain_array[current_chain] = newChain;
         cur->chain_id = chain_array[current_chain]->id;

         // Allocate the first rule
         // cur = new rule;

         // Consume the "header display" line
         free(oldLine);
         line = NULL;
         length = getline(&line, &bufsize, ruleFile);
         lineNo++;
         oldLine = line;

         // Priming read
         free(oldLine);
         line = NULL;
         length = getline(&line, &bufsize, ruleFile);
         lineNo++;
         oldLine = line;

         if (length == -1)      // IF EOF, done.
            break;
      }
      else {
         // Read the next rule
         if (rp->ReadVerboseRule(cur, line, length) >= 0)       // Verbose Input
         {
            // Append to the linked list for the current chain
            cur->next = chain_array[current_chain]->rules;
            chain_array[current_chain]->rules = cur;

	    cur->id = chain_array[current_chain]->numRules;
	    chain_array[current_chain]->numRules++;
#ifdef DEBUG
	    PrintRule(*cur);
#endif 

            // Allocate next rule
            cur = new rule;
	    cur->chain_id = chain_array[current_chain]->id;
         }
         // Do priming read
         free(oldLine);
         line = NULL;
         length = getline(&line, &bufsize, ruleFile);
         lineNo++;
         oldLine = line;
      }
   }
   free(oldLine);

   // We always create one more than we need, so free.
   delete cur;

   cur = NULL;
   fclose(ruleFile);
   ruleFile = NULL;


   // For every rule of every chain, we break the net/mask 
   // pairs into linked lists of integer ranges.  We also parse
   // the port and state information out of each rule.  The result
   // is stored in a processed_rule struct.

   i = 0;
   while (i < num_chains) {     // For each chain
      newChain = chain_array[i];
#ifdef DEBUG
      printf("Chain: %s\n", newChain->name);
#endif
      cur = newChain->rules;

      //If empty target, ignore the rule.
      while (cur && cur->target[0] == '\0') {
         cur = cur->next;
      }

      phead = NULL;

      // Allocate a processed_rule
      while (cur) {
#ifdef DEBUG
         PrintRule(*cur);
#endif
         // Convert cur to a processed_rule, storing it in pcur.
         pcur = new processed_rule;
         ProcessRule(cur, pcur, rp, T);

#ifdef DEBUG
         printf("=======\n");
         PrintProcessedRule(pcur);
         printf("*******\n");
#endif
         // Push onto head of the list
         pcur->next = phead;
         phead = pcur;

         // Allocate next rule
         cur = cur->next;

         //If empty target, ignore the rule.
         while (cur && cur->target[0] == '\0') {
            cur = cur->next;
         }
      }

      // Store the linked list of processedRules in the chain struct.
      newChain->newRules = phead;

      // Now convert the processed rules into vector tuples suitable
      // for insertion into the MDDs

      newChain->tup = NULL;     // <----- A very important step.
      BuildRules(phead, newChain->tup);
      i++;
      // Free the processed rules, since we don't need 'em anymore.
      while (newChain->newRules != NULL) {
         pcur = newChain->newRules;
         newChain->newRules = newChain->newRules->next;
         delete pcur;
         pcur = NULL;
      }
   }
   delete rp;
}

// Perform NAT on the Filter and LOG MDDs.

void Firewall::BuildNATRules(char *fname)
{
   FILE *natFile;
   char *line;                            // Current line of input
   char *oldLine;                         // Placeholder so that we can free the

   // line

   // After we've modified it.

   ssize_t length;                        // Length of the input line
   size_t bufsize;

   rule *cur;                             // Current rule to process
   processed_nat_rule *pcur;              // Current expanded rule

   nat_chain *newNATChain;                // Current Chain to build
   nat_chain *curNATChain;                // Chain of NAT rules to build
   int current_nchain;                    // Index (in nat_chains) of the
   // chain. 

   rule_parser *rp;

   int i;

   int lineNo;

   num_nat_chains = 0;
   lineNo = 0;

   natFile = fopen(fname, "r");
   if (!natFile) {
      perror("ITVal: Opening NAT rules");
      exit(errno);
   }

   line = NULL;
   oldLine = NULL;
   current_nchain = -1;
   newNATChain = NULL;
   natHead = NULL;

   rp = new rule_parser(T);

   // First, parse the rule file into rule structs.
   cur = new rule;
   length = getline(&line, &bufsize, natFile);
   lineNo++;
   oldLine = line;
   while (length != -1) {

      // Consume Whitespace
      while (length > 0 && (*line == '\n')) {
         line++;
         length--;
      }

      if (length == 0) {        // If the line is empty, ignore.
         free(oldLine);
         line = NULL;
         length = getline(&line, &bufsize, natFile);
         lineNo++;
         oldLine = line;
         if (length == -1)      // If at the end of the file, done.
            break;
         continue;              // Skip the line.
      }
      // If the line defines a new chain

      if (strncmp(line, "Chain", 5) == 0) {
#ifdef DEBUG
         PrintChain(nat_chains[current_nchain]);
#endif
         // Delete the empty rule 
         // (We always create one more than we need)
         delete cur;

         // Allocate a new chain 
         newNATChain = new nat_chain(fname);

         // Grab its name from the input line
         ReadChain(line, length, newNATChain);

         current_nchain++;
         nat_chains[current_nchain] = newNATChain;
         // Set number of chains
         num_nat_chains++;

         // Allocate the first rule
         cur = new rule;
	 cur->chain_id = nat_chains[current_nchain]->id;

         // Consume the "header display" line
         free(oldLine);
         line = NULL;
         length = getline(&line, &bufsize, natFile);
         lineNo++;
         oldLine = line;

         // Priming read
         free(oldLine);
         line = NULL;
         length = getline(&line, &bufsize, natFile);
         lineNo++;
         oldLine = line;

         if (length == -1)      // IF EOF, done.
            break;
      }
      // Set number of chains
      // num_nat_chains = current_nchain + 1;

      // Read the next rule
      if (rp->ReadRule(cur, line, length) >= 0) {

         // Append to the linked list for the current chain
         cur->next = nat_chains[current_nchain]->rules;
         nat_chains[current_nchain]->rules = cur;

         cur->id = nat_chains[current_nchain]->numRules;
	 nat_chains[current_nchain]->numRules++;


         // Allocate next rule
         cur = new rule;
	 cur->chain_id = nat_chains[current_nchain]->id;
      }
      // Do priming read
      free(oldLine);
      line = NULL;
      length = getline(&line, &bufsize, natFile);
      lineNo++;
      oldLine = line;
   }
   free(oldLine);
   // We always create one more than we need, so free.
   delete cur;

   fclose(natFile);
   natFile = NULL;


   // For every rule of every chain, we break the net/mask 
   // pairs into linked lists of integer ranges.  We also parse
   // the port and state information out of each rule.  The result
   // is stored in a processed_rule struct.

   i = 0;
   curNATChain = NULL;
   while (i < num_nat_chains) { // For each chain
      curNATChain = nat_chains[i];
#ifdef DEBUG
      printf("NAT_Chain[%s]: %s\n", fname, curNATChain->name);
#endif
      cur = curNATChain->rules;
      natHead = NULL;           // Linked list of nat rules is initially
      // NULL

      // Allocate a processed_rule
      while (cur) {
#ifdef DEBUG
         PrintRule(*cur);
#endif
         // Convert cur to a processed_rule, storing it in pcur.
         pcur = new processed_nat_rule;
         ProcessNATRule(cur, pcur, this, rp);

#ifdef DEBUG
         printf("=======\n");
         PrintProcessedNATRule(pcur);
         printf("*******\n");
#endif
         // Push onto head of the list
         pcur->next = natHead;
         natHead = pcur;

         // Allocate next rule
         cur = cur->next;
      }

      // Store the linked list of processedRules in the chain struct.
      curNATChain->natRules = natHead;

      i++;
   }

   /*
    * //Free the processed nat rules, since we don't need 'em anymore.
    * while (natHead != NULL){ pcur = natHead; natHead = natHead->next;
    * free(pcur); pcur = NULL; } 
    */
   delete rp;
}

// Build outputMDD, storing the set of all accepted packets
// and Logged, an MDD storing the set of logged packets.
void Firewall::BuildChains(int input_chain, mdd_handle & outputMDD,
                           mdd_handle & Logged, mdd_handle & outHistMDD)
{
   AssembleChains(chain_array, chain_array[input_chain], outputMDD, Logged, outHistMDD);
}

// Find, by sequential search, chain <name>.
// Return its index in the chain array, or -1 if no such chain can be
// found.

int Firewall::FindChain(char *name)
{
   int i;

   if (strncmp(name, "TCPMSS", 6) == 0)
      return -2;

   if (strncmp(name, "BALANCE", 7) == 0)
      return -2;

   if (strncmp(name, "CLASSIFY", 8) == 0)
      return -2;

   if (strncmp(name, "CLUSTERIP", 9) == 0)
      return -2;

   if (strncmp(name, "CONNMARK", 8) == 0)
      return -2;

   if (strncmp(name, "DSCP", 4) == 0)
      return -2;

   if (strncmp(name, "ECN", 3) == 0)
      return -2;

   if (strncmp(name, "MARK", 4) == 0)
      return -2;

   if (strncmp(name, "MIRROR", 6) == 0)
      return -2;

   if (strncmp(name, "NOTRACK", 7) == 0)
      return -2;

   if (strncmp(name, "REDIRECT", 8) == 0)
      return -2;

   if (strncmp(name, "ROUTE", 5) == 0)
      return -2;

   if (strncmp(name, "SET", 3) == 0)
      return -2;

   if (strncmp(name, "TOS", 3) == 0)
      return -2;

   if (strncmp(name, "TRACE", 5) == 0)
      return -2;

   if (strncmp(name, "TTL", 3) == 0)
      return -2;

   if (strncmp(name, "ULOG", 4) == 0)
      return -2;

   if (strncmp(name, "MASQUERADE", 4) == 0)
      return -2;

   if (strncmp(name, "QUEUE", 4) == 0)
      return -2;

   if (strncmp(name, "REDIRECT", 4) == 0)
      return -2;

   for (i = 0; i < num_chains; i++) {
      if (strncmp(name, chain_array[i]->name, 256) == 0)
         return i;
   }
   return -1;
}

int Firewall::FindNATChain(char *name)
{
   int i;

   for (i = 0; i < num_nat_chains; i++) {
      if (strncmp(name, nat_chains[i]->name, 256) == 0)
         return i;
   }
   return -1;
}
