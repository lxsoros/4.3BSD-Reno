#	@(#)Makefile	5.2 (Berkeley) 6/8/90

FILES=	3101 aa aed512 beehive diablo dtc382 hp700-wy ibm3101 std stdcrt \
	tandem653 teleray vt100 wyse-adds xerox1720 xerox1730 xerox1730-lm \
	zenith29
NOOBJ=	noobj

all clean cleandir depend lint tags:

install:
	install -c -o ${BINOWN} -g ${BINGRP} -m 444 ${FILES} \
	    ${DESTDIR}${BINDIR}/tabset

.include <bsd.prog.mk>
