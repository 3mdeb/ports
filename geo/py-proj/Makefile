# $OpenBSD: Makefile,v 1.28 2021/03/17 18:43:34 landry Exp $

COMMENT =		Pyrex generated python interface to PROJ.4 library

MODPY_EGG_VERSION =	3.0.1
DISTNAME =		pyproj-${MODPY_EGG_VERSION}
PKGNAME =		${DISTNAME:S/py/py-/:S/.post/pl/}

CATEGORIES =		geo

HOMEPAGE =		https://github.com/jswhit/pyproj

MAINTAINER =		Benoit Lecocq <benoit@openbsd.org>

# MIT
PERMIT_PACKAGE =	Yes

WANTLIB += ${MODPY_WANTLIB} proj pthread

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_PYTEST =		Yes
MODPY_TEST_DIR =	${WRKSRC}/test

FLAVORS =		python3
FLAVOR =		python3

MODPY_SETUPTOOLS =	Yes

BUILD_DEPENDS +=	${RUN_DEPENDS}
TEST_DEPENDS =		${BUILD_PKGPATH} \
			devel/py-mock${MODPY_FLAVOR}
RUN_DEPENDS +=		devel/proj>=6.0 \
			lang/cython${MODPY_FLAVOR} \
			math/py-numpy${MODPY_FLAVOR}
TEST_ENV =	PROJ_NETWORK=OFF

.include <bsd.port.mk>
