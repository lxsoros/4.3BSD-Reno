/*
 * Copyright (c) 1988, 1989, 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Adam de Boor.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that: (1) source distributions retain this entire copyright
 * notice and comment, and (2) distributions including binaries display
 * the following acknowledgement:  ``This product includes software
 * developed by the University of California, Berkeley and its contributors''
 * in the documentation or other materials provided with the distribution
 * and in all advertising materials mentioning features or use of this
 * software. Neither the name of the University nor the names of its
 * contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef lint
static char sccsid[] = "@(#)lstDeQueue.c	5.3 (Berkeley) 6/1/90";
#endif /* not lint */

/*-
 * LstDeQueue.c --
 *	Remove the node and return its datum from the head of the list
 */

#include	"lstInt.h"

/*-
 *-----------------------------------------------------------------------
 * Lst_DeQueue --
 *	Remove and return the datum at the head of the given list.
 *
 * Results:
 *	The datum in the node at the head or (ick) NIL if the list
 *	is empty.
 *
 * Side Effects:
 *	The head node is removed from the list.
 *
 *-----------------------------------------------------------------------
 */
ClientData
Lst_DeQueue (l)
    Lst	    	  l;
{
    ClientData	  rd;
    register ListNode	tln;
    
    tln = (ListNode) Lst_First (l);
    if (tln == NilListNode) {
	return ((ClientData) NIL);
    }
    
    rd = tln->datum;
    if (Lst_Remove (l, (LstNode)tln) == FAILURE) {
	return ((ClientData) NIL);
    } else {
	return (rd);
    }
}

