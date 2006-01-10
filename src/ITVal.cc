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

#define SYNTAX "Syntax: ITVal [options]\n   Options:\n      -q <queryfile> :\
Specify the query file. <REQUIRED>\n      -t <topology file> : Specify the \
topology file.\n      -F or -f <rulefile> : Append a filter rule set file. \
<REQUIRED>\n      -N or -n <natfile> : Append a NAT rule set file.\n\n"

#include <stdio.h>
#include "structures.h"
#include "firewall.h"
#include <FDDL/mdd.h>
#include "parser_interface.hh"
#include "topology.h"


typedef struct filename_node{
   int verbose_input;
   char filterName[256];
   char natName[256];
   char topName[256];
   filename_node* next;
}filename_node;

/* Create a META-Firewall from all the independent firewalls.*/
Firewall *MergeFWs (fw_fddl_forest * FWForest, Firewall ** fws, int num_fws);

/* Free group and service declarations, plus MDDs. */
void DoCleanup ();

/* Main Routine.  Syntax: ITVal <query file> {<filter1> <nat1> ...} */
int
main (int argc, char **argv)
{
  int i;
  char queryName[256];
  parser_interface pi;
  Firewall **fws;		/* Array of independent firewalls   */
  int num_fws=0;			/* Number of firewalls in the array */
  Topology* top = NULL;
  filename_node* fileList = NULL;
  char flag;

  fw_fddl_forest *FWForest;
  Firewall *metaFirewall;

  filename_node* fn;

  int ranges[23] = { 256,	/* Target Chain                 */
    1, 1, 1, 1, 1, 1,		/* Flags (FIN, SYN, RST, PSH, ACK, URG) */
    3,				/* Connection State             */
    255, 255,		        /* Output and Input Interface   */
    255, 255,			/* Destination Port             */
    255, 255,			/* Source Port                  */
    2,				/* Protocol                     */
    255, 255, 255, 255,		/* Destination Address          */
    255, 255, 255, 255		/* Source Address               */
  };
  
  FWForest = new fw_fddl_forest (23, ranges);
  FWForest->ToggleSparsity (false);	/* @BUG@: Sparse nodes don't work. */

  strncpy(queryName, "NOQUERY", 7);
  
  if (argc < 2){
    printf (SYNTAX);
    return 1;
  }
  
  for (i=1;i<argc;i+=2){
     if (strlen(argv[i])<2){
        printf(SYNTAX);
        return 1;
     }
     flag = argv[i][1];
     switch (flag){
        default:
        printf(SYNTAX);
	return 1;
	case 'q':
	   if (i+1>=argc){
	      printf("Error: Flag -q requires an argument!\n");
              return 1;
	   }
	   strncpy(queryName, argv[i+1], 256);
        break;
	case 't':
	   if (i+1>=argc){
	      printf("Error: Flag -t requires an argument!\n");
              return 1;
	   }
           if (!fileList){
	      printf("Error: Topology file %s precedes filter file!\n", argv[i+1]);
              return 1;
	   }
	   if (strncmp(fn->topName, "NOTOP", 5) != 0){
              printf("Warning: Topology file %s overrides Topology file %s for filter %s.\n",argv[i+1], fileList->topName, fileList->filterName);
	   }
	   strncpy(fileList->topName, argv[i+1],256);
        break;
	case 'F':
	case 'f':
	   if (i+1>=argc){
	      printf("Error: Flag -f requires an argument!\n");
              return 1;
	   }
	   fn = new filename_node;
	   strncpy(fn->filterName, argv[i+1],256);
	   strncpy(fn->natName, "NONAT", 5);
	   strncpy(fn->topName, "NOTOP", 5);
	   fn->verbose_input = 0;
	   fn->next = fileList;
	   fileList = fn;
	   num_fws++;
	break;
	case 'N':
	case 'n':
	   if (i+1>=argc){
	      printf("Error: Flag -n requires an argument!\n");
              return 1;
	   }
           if (!fileList){
	      printf("Error: NAT file %s precedes filter files!\n", argv[i+1]);
              return 1;
	   }
	   if (strncmp(fn->natName, "NONAT", 5) != 0){
              printf("Warning: NAT file %s overrides NAT file %s for filter %s.\n",argv[i+1], fileList->natName, fileList->filterName);
	   }
	   strncpy(fileList->natName, argv[i+1],256);
        break;
     }
     if (flag == 'F')
	     fileList->verbose_input = 1;
     if (flag == 'N' && fileList->verbose_input == 0){
	     printf("Error: NAT and filter files must match in type.\n");
	     return 1;
     }
  }

  if (!strncmp(queryName, "NOQUERY", 7)){
	  printf("Error: No query file specified!\n");
	  return 1;
  }
  
  /* Initialize the firewall array */
  fws = new Firewall *[num_fws];

  /* Read each firewall and store it in the array. */
  
  i = 0;
  while (fileList != NULL){
     filename_node* del;
     if (top != NULL)
        delete top;
     if (strncmp(fileList->topName, "NOTOP",5) != 0){
        top = new Topology(fileList->topName);
	     top->PrintMapping();
     }
     else{
        top = NULL;
     }
     if (fileList->verbose_input == 1)
        fws[i] = new Firewall (fileList->filterName, fileList->natName, FWForest, top, 1);
     else
        fws[i] = new Firewall (fileList->filterName, fileList->natName, FWForest, top);
     i = i + 1;
     del = fileList;
     fileList = fileList->next;
     delete del;
  }

  /* Create the meta firewall. */
  metaFirewall = MergeFWs (FWForest, fws, num_fws); //@Need Topology here?@


  for (int i = 0; i < num_fws; i++)
  {
    delete fws[i];
  }
  delete[]fws;

  if (!metaFirewall)
  {
    printf ("No firewalls to merge!\nAborting.\n");
    return 2;
  }

  /* Connect the Forest to the Query Engine. */
  InitializeStructures (metaFirewall, top);

  /* Parse and Analyze query file */
  pi.parse (queryName);

  DoCleanup ();
  if (top != NULL)
     delete top;
  delete metaFirewall;
  delete FWForest;

  return 0;
}

/* Create a Meta-Firewall */
/* Need to do something about Topologies, here. */
Firewall *
MergeFWs (fw_fddl_forest * FWForest, Firewall ** fws, int n)
{
  Firewall *f;
  int prerouting, postrouting;

  int i;

  if (n == 0)
    return NULL;

  f = new Firewall (FWForest);

  prerouting = fws[0]->FindNATChain ("Prerouting");
  postrouting = fws[0]->FindNATChain ("Postrouting");

  if (prerouting >= 0)
  {
    fws[0]->NATChains (postrouting, fws[0]->Forward, f->Forward,
		       f->ForwardLog);
    fws[0]->NATChains (postrouting, fws[0]->Input, f->Input, f->InputLog);
    fws[0]->NATChains (postrouting, fws[n - 1]->Output, f->Output,
		       f->OutputLog);
  }
  else
  {
    FWForest->Attach (f->Forward, fws[0]->Forward.index);
    FWForest->Attach (f->ForwardLog, fws[0]->ForwardLog.index);

    FWForest->Attach (f->Input, fws[0]->Input.index);
    FWForest->Attach (f->InputLog, fws[0]->InputLog.index);

    FWForest->Attach (f->Output, fws[n - 1]->Output.index);
    FWForest->Attach (f->OutputLog, fws[n - 1]->OutputLog.index);
  }

  for (i = 1; i < n; i++)
  {
    FWForest->Min (f->Forward, fws[i]->Forward, f->Forward);
    FWForest->Min (f->Input, fws[i]->Forward, f->Forward);
    FWForest->Min (f->Output, fws[(n - 1) - i]->Forward, f->Forward);

    prerouting = fws[i]->FindNATChain ("Prerouting");
    postrouting = fws[i - 1]->FindNATChain ("Postrouting");

    /* SNAT the chains (and postrouting NETMAP them) */
    if (postrouting >= 0)
    {
      fws[i]->NATChains (postrouting, f->Forward, f->Forward, f->ForwardLog);
      fws[i]->NATChains (postrouting, f->Input, f->Input, f->InputLog);
    }
    /* DNAT the chains and (Prerouting NETMAP them) */
    if (prerouting >= 0)
    {
      fws[i]->NATChains (prerouting, f->Forward, f->Forward, f->ForwardLog);
      fws[i]->NATChains (prerouting, f->Input, f->Input, f->InputLog);
    }

    prerouting = fws[(n - 1) - i]->FindNATChain ("Prerouting");
    postrouting = fws[n - i]->FindNATChain ("Postrouting");
    if (postrouting >= 0)
    {
      fws[n - i]->NATChains (postrouting, f->Output, f->Output, f->OutputLog);
    }
    if (prerouting >= 0)
    {
      fws[n - i]->NATChains (prerouting, f->Output, f->Output, f->OutputLog);
    }
  }
  return f;
}
