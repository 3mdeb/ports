# $OpenBSD: Makefile,v 1.30 2021/03/25 14:58:29 sthen Exp $

COMMENT =	correct and clean up HTML and XML

GH_ACCOUNT =	htacg
GH_PROJECT =	tidy-html5
GH_TAGNAME =	5.7.28
PKGNAME =	${DISTNAME:S/-html5//}
EPOCH=		0

SHARED_LIBS +=  tidy                      2.0 # 5.6

CATEGORIES =	www devel
HOMEPAGE =	https://www.html-tidy.org/

# BSD-like, badly worded, defined in include/tidy.h
PERMIT_PACKAGE =	Yes

WANTLIB += c

MODULES =	devel/cmake
NO_TEST =	Yes

BUILD_DEPENDS =	textproc/libxslt

CONFIGURE_ARGS +=	-DMAN_INSTALL_DIR=${PREFIX}/man/man1

.include <bsd.port.mk>
