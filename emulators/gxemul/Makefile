# $OpenBSD: Makefile,v 1.50 2021/02/26 03:03:53 daniel Exp $

COMMENT=		ARM/M88k/MIPS/PowerPC/SuperH machines emulator

DISTNAME =		gxemul-0.6.3.1

CATEGORIES=		emulators

HOMEPAGE=		http://gavare.se/gxemul/

# BSD
PERMIT_PACKAGE=	Yes

MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gxemul/}

WANTLIB =		c m ${COMPILER_LIBCXX}

COMPILER =		base-clang ports-gcc base-gcc

CONFIGURE_ARGS +=	--disable-valgrind \
			--disable-doxygen
CONFIGURE_STYLE=	simple

FLAVORS=		no_x11
FLAVOR?=

.if ${FLAVOR:Mno_x11}
CONFIGURE_ARGS+=	--disable-x
.else
WANTLIB+=		X11
.endif

NO_TEST=		Yes

INSTALL_STRIP=

.include <bsd.port.mk>
