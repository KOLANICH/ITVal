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

#include <string.h>
#include "rules.h"
#include <stdlib.h>

void ProcessInfo(char *info, processed_rule * p)
{
	char    port[4096];			  // String representation of the port
	char    which[4096];			  // Which protocol the port is for

	// (tcp, udp, or icmp)
	int     port_val;				  // Integer representation of the port 

	port_range *newPort;			  // Temporary range to be added to the rule 

	port_range *sports;			  // List of ranges for the source ports
	port_range *dports;			  // List of ranges for the destination

	// ports

	int     state;					  // States to match

	char    word1[4096];			  // Key name
	char    word2[4096];			  // Value 

	int     flags[6];				  // Which TCP flags to match

	int     length;				  // Length of the info string

	int     i;

	// Initially, the port lists are empty, all states match, and the
	// no flags are considered.
	sports = NULL;
	dports = NULL;
	state = 0;
	for (i = 0; i < 6; i++)
		flags[i] = (-1);

	length = strlen(info);
	while (length - 1 > 0) {
		// Consume whitespace
		while (strlen(info) - 1 > 0 && (*info == ' ' || *info == '\t')) {
			info++;
		}
		// Read the first word (the key)
		if (sscanf(info, "%4096s", word1) != EOF) {
			info += strlen(word1);
			// If it's tcp or udp, scan in a port.
			if (!strncmp(word1, "tcp", 4096)
				 || !strncmp(word1, "udp", 4096)) {
				// Read the port number into word2
				if (sscanf(info, "%4096s", word2) != EOF) {
					info += strlen(word2);
					// Convert the string into an integer
					BreakPort(word2, which, port);
					// If it's a destination port, put it in the dports
					// list.  If it's a source port, put it in the sports
					// list.
					if (!strncmp(which, "dpt", 4096)) {
						newPort = new port_range;
						newPort->next = dports;
						port_val = atoi(port);
						newPort->port1 = port_val / 256;
						newPort->port2 = port_val % 256;
						dports = newPort;
					}
					else if (!strncmp(which, "spt", 4096)) {
						newPort = new port_range;
						newPort->next = sports;
						port_val = atoi(port);
						newPort->port1 = port_val / 256;
						newPort->port2 = port_val % 256;
						sports = newPort;
					}
				}
				// If the keyword is "state", then parse the state
				// information.
			}
			else if (!strncmp(word1, "state", 4096)) {
				if (sscanf(info, "%4096s", word2) != EOF) {
					info += strlen(word2);
					BreakState(word2, &state);
				}
				// If it's "flags", parse the flag information.
			}
			else if (!strncmp(word1, "flags:", 6)) {
				BreakFlags(word1, flags);
			}
		}
		length = strlen(info);
	}
	// Store the results in the processed_rule
	p->sports = sports;
	p->dports = dports;
	p->state = state;
	for (i = 0; i < 6; i++) {
		p->flags[i] = flags[i];
	}
}

// Convert an unprocessed rule r into a processed_rule p.
void ProcessRule(rule * r, processed_rule * p)
{
	// Munge the source and destination addresses
	ConvertARange(r->source, p->from);
	ConvertARange(r->dest, p->to);

	// The protocol
	p->protocol = r->protocol[0];

	// The target
	strncpy(p->target, r->target, 256);

	// And everything else
	ProcessInfo(r->info, p);
}