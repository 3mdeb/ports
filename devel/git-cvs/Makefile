# $OpenBSD: Makefile,v 1.12 2021/02/23 19:39:15 sthen Exp $

COMMENT =	import changesets from CVS into Git

MODPY_EGG_VERSION = 0.1.0
REVISION =	2

DISTNAME =	git-cvs-${MODPY_EGG_VERSION}
DISTFILES =	${DISTNAME}{${MODPY_EGG_VERSION}}.tar.gz
CATEGORIES =	devel

HOMEPAGE =	https://github.com/ustuehler/git-cvs

# BSD
PERMIT_PACKAGE = Yes

MASTER_SITES =	https://github.com/ustuehler/git-cvs/archive/

MODULES =	lang/python
MODPY_VERSION =	${MODPY_DEFAULT_VERSION_2}

MODPY_SETUPTOOLS = Yes

MODPY_ADJ_FILES = scripts/git-cvs

BUILD_DEPENDS =	devel/py-nose
RUN_DEPENDS=	devel/git \
		devel/py-rcsparse
TEST_DEPENDS=	${BUILD_DEPENDS}

# for regression tests:
# cvs(1) insists on doing a chdir(2) to HOME before checkout
PORTHOME =	${WRKDIR}

.include <bsd.port.mk>
