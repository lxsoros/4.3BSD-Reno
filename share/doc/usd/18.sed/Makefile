#	@(#)Makefile	5.1 (Berkeley) 6/30/90

DIR=	usd/18.sed
SRCS=	sed
MACROS=	-msU

paper.${PRINTER}: ${SRCS}
	${ROFF} ${SRCS} > ${.TARGET}

.include <bsd.doc.mk>
