/*
 * Copyright (c) 1985 The Regents of the University of California.
 * All rights reserved.
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
static char sccsid[] = "@(#)dbm.c	5.5 (Berkeley) 6/1/90";
#endif /* not lint */

#include	"dbm.h"

#define	NODB	((DBM *)0)

static DBM *cur_db = NODB;

static char no_db[] = "dbm: no open database\n";

dbminit(file)
	char *file;
{
	if (cur_db != NODB)
		dbm_close(cur_db);

	cur_db = dbm_open(file, 2, 0);
	if (cur_db == NODB) {
		cur_db = dbm_open(file, 0, 0);
		if (cur_db == NODB)
			return (-1);
	}
	return (0);
}

long
forder(key)
datum key;
{
	if (cur_db == NODB) {
		printf(no_db);
		return (0L);
	}
	return (dbm_forder(cur_db, key));
}

datum
fetch(key)
datum key;
{
	datum item;

	if (cur_db == NODB) {
		printf(no_db);
		item.dptr = 0;
		return (item);
	}
	return (dbm_fetch(cur_db, key));
}

delete(key)
datum key;
{
	if (cur_db == NODB) {
		printf(no_db);
		return (-1);
	}
	if (dbm_rdonly(cur_db))
		return (-1);
	return (dbm_delete(cur_db, key));
}

store(key, dat)
datum key, dat;
{
	if (cur_db == NODB) {
		printf(no_db);
		return (-1);
	}
	if (dbm_rdonly(cur_db))
		return (-1);

	return (dbm_store(cur_db, key, dat, DBM_REPLACE));
}

datum
firstkey()
{
	datum item;

	if (cur_db == NODB) {
		printf(no_db);
		item.dptr = 0;
		return (item);
	}
	return (dbm_firstkey(cur_db));
}

datum
nextkey(key)
datum key;
{
	datum item;

	if (cur_db == NODB) {
		printf(no_db);
		item.dptr = 0;
		return (item);
	}
	return (dbm_nextkey(cur_db, key));
}
