/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "@(#)crt0.c	5.3 (Berkeley) 3/9/86";
#endif LIBC_SCCS and not lint

/*
 *	C start up routine.
 *	Robert Henry, UCB, 20 Oct 81
 *
 *	We make the following (true) assumptions:
 *	1) when the kernel calls start, it does a jump to location 2,
 *	and thus avoids the register save mask.  We are NOT called
 *	with a calls!  see sys1.c:setregs().
 *	2) The only register variable that we can trust is sp,
 *	which points to the base of the kernel calling frame.
 *	Do NOT believe the documentation in exec(2) regarding the
 *	values of fp and ap.
 *	3) We can allocate as many register variables as we want,
 *	and don't have to save them for anybody.
 *	4) Because of the ways that asm's work, we can't have
 *	any automatic variables allocated on the stack, because
 *	we must catch the value of sp before any automatics are
 *	allocated.
 */

char **environ = (char **)0;
static int fd;

asm("#define _start start");
asm("#define _eprol eprol");

#ifdef hp300
asm("#define link .long 0; linkw");	/* Yuk!! */
#endif

extern	unsigned char	etext;
extern	unsigned char	eprol;
start()
{
	struct kframe {
		int	kargc;
		char	*kargv[1];	/* size depends on kargc */
		char	kargstr[1];	/* size varies */
		char	kenvstr[1];	/* size varies */
	};
	/*
	 *	ALL REGISTER VARIABLES!!!
	 */
	register int d7;		/* needed for init (this will be
					   a problem with GCC) */
	register struct kframe *kfp;	/* PCC a5 */
	register char **targv;
	register char **argv;
	extern int errno;

#ifdef lint
	kfp = 0;
	initcode = initcode = 0;
#else not lint
#ifdef __GNUC__
	asm("lea a6@(4),%0" : "=r" (kfp));	/* catch it quick */
#else
	asm("	lea	a6@(4),a5");	/* catch it quick */
#endif
#endif not lint
	for (argv = targv = &kfp->kargv[0]; *targv++; /* void */)
		/* void */ ;
	if (targv >= (char **)(*argv))
		--targv;
	environ = targv;
asm("eprol:");

#ifdef paranoid
	/*
	 * The standard I/O library assumes that file descriptors 0, 1, and 2
	 * are open. If one of these descriptors is closed prior to the start 
	 * of the process, I/O gets very confused. To avoid this problem, we
	 * insure that the first three file descriptors are open before calling
	 * main(). Normally this is undefined, as it adds two unnecessary
	 * system calls.
	 */
	do	{
		fd = open("/dev/null", 2);
	} while (fd >= 0 && fd < 3);
	close(fd);
#endif paranoid

#ifdef MCRT0
	monstartup(&eprol, &etext);
#endif MCRT0
	errno = 0;
	exit(main(kfp->kargc, argv, environ));
}
asm("#undef link");
asm("#undef _start");
asm("#undef _eprol");

#ifdef MCRT0
/*ARGSUSED*/
exit(code)
	register int code;	/* PCC d7 */
{
	monitor(0);
	_cleanup();
#ifdef __GNUC__
	asm("movl %1,sp@-" : "=m" (*(char *)0) : "r" (code));
#else
	asm("	movl d7,sp@-");
#endif
	asm("	subql #4,sp");
	asm("	movl #1,d0");
	asm("	trap #0");
}
#endif MCRT0

#ifdef CRT0
/*
 * null mcount and moncontrol,
 * just in case some routine is compiled for profiling
 */
moncontrol(val)
	int val;
{

}
asm("	.globl	mcount");
asm("mcount:	rts");
#endif CRT0
