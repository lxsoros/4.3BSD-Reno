#	@(#)Makefile	5.1 (Berkeley) 6/19/90

# -DSLOWSYS	invoke xread() for system time quirk on PDP, others?
# -DNOKANJI	default is for Japanese Unix.  undef only for raw
#		parity-marked search capability, not standard w/grep.
# -DCHINESE	for systems using EUC Chinese2 codes
# -Dstrrchr=rindex, -Dstrchr=index	as necessary

PROG=	egrep
CFLAGS+=-Dstrrchr=rindex -Dstrchr=index -DNOKANJI
MAN1=	grep.0
LINKS=	${BINDIR}/egrep ${BINDIR}/grep ${BINDIR}/egrep ${BINDIR}/fgrep
MLINKS=	grep.1 egrep.1 grep.1 fgrep.1

.include "../../Makefile.inc"
.include <bsd.prog.mk>
