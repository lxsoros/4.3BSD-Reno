/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Edward Wang at The University of California, Berkeley.
 *
 * Redistribution and use in source and binary forms are permitted provided
 * that: (1) source distributions retain this entire copyright notice and
 * comment, and (2) distributions including binaries display the following
 * acknowledgement:  ``This product includes software developed by the
 * University of California, Berkeley and its contributors'' in the
 * documentation or other materials provided with the distribution and in
 * all advertising materials mentioning features or use of this software.
 * Neither the name of the University nor the names of its contributors may
 * be used to endorse or promote products derived from this software without
 * specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef lint
static char sccsid[] = "@(#)char.c	3.7 (Berkeley) 6/6/90";
#endif /* not lint */

#include "char.h"

char _cmap[] = {
	_C|_U,		_C|_U,		_C|_U,		_C|_U,	/* ^@ - ^C */
	_C|_U,		_C|_U,		_C|_U,		_C|_U,	/* ^D - ^G */
	_C,		_C|_P,		_C,		_C|_U,	/* ^H - ^K */
	_C|_U,		_C,		_C|_U,		_C|_U,	/* ^L - ^O */
	_C|_U,		_C|_U,		_C|_U,		_C|_U,	/* ^P - ^S */
	_C|_U,		_C|_U,		_C|_U,		_C|_U,	/* ^T - ^W */
	_C|_U,		_C|_U,		_C|_U,		_C|_U,	/* ^U - ^[ */
	_C|_U,		_C|_U,		_C|_U,		_C|_U,	/* ^\ - ^_ */

	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,

	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,

	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_C|_U,

	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,

	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,

	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,

	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U
};

char *_unctrl[] = {
	"^@",	"^A",	"^B",	"^C",	"^D",	"^E",	"^F",	"^G",
	"^H",	"^I",	"^J",	"^K",	"^L",	"^M",	"^N",	"^O",
	"^P",	"^Q",	"^R",	"^S",	"^T",	"^U",	"^V",	"^W",
	"^X",	"^Y",	"^Z",	"^[",	"^\\",	"^]",	"^^",	"^_",
	" ",	"!",	"\"",	"#",	"$",	"%",	"&",	"'",
	"(",	")",	"*",	"+",	",",	"-",	".",	"/",
	"0",	"1",	"2",	"3",	"4",	"5",	"6",	"7",
	"8",	"9",	":",	";",	"<",	"=",	">",	"?",
	"@",	"A",	"B",	"C",	"D",	"E",	"F",	"G",
	"H",	"I",	"J",	"K",	"L",	"M",	"N",	"O",
	"P",	"Q",	"R",	"S",	"T",	"U",	"V",	"W",
	"X",	"Y",	"Z",	"[",	"\\",	"]",	"^",	"_",
	"`",	"a",	"b",	"c",	"d",	"e",	"f",	"g",
	"h",	"i",	"j",	"k",	"l",	"m",	"n",	"o",
	"p",	"q",	"r",	"s",	"t",	"u",	"v",	"w",
	"x",	"y",	"z",	"{",	"|",	"}",	"~",	"^?",
	"\\200","\\201","\\202","\\203","\\204","\\205","\\206","\\207",
	"\\210","\\211","\\212","\\213","\\214","\\215","\\216","\\217",
	"\\220","\\221","\\222","\\223","\\224","\\225","\\226","\\227",
	"\\230","\\231","\\232","\\233","\\234","\\235","\\236","\\237",
	"\\240","\\241","\\242","\\243","\\244","\\245","\\246","\\247",
	"\\250","\\251","\\252","\\253","\\254","\\255","\\256","\\257",
	"\\260","\\261","\\262","\\263","\\264","\\265","\\266","\\267",
	"\\270","\\271","\\272","\\273","\\274","\\275","\\276","\\277",
	"\\300","\\301","\\302","\\303","\\304","\\305","\\306","\\307",
	"\\310","\\311","\\312","\\313","\\314","\\315","\\316","\\317",
	"\\320","\\321","\\322","\\323","\\324","\\325","\\326","\\327",
	"\\330","\\331","\\332","\\333","\\334","\\335","\\336","\\337",
	"\\340","\\341","\\342","\\343","\\344","\\345","\\346","\\347",
	"\\350","\\351","\\352","\\353","\\354","\\355","\\356","\\357",
	"\\360","\\361","\\362","\\363","\\364","\\365","\\366","\\367",
	"\\370","\\371","\\372","\\373","\\374","\\375","\\376","\\377"
};
