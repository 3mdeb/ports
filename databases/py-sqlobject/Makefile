# $OpenBSD: Makefile,v 1.26 2021/02/19 23:13:00 sthen Exp $

COMMENT =		Object Relational Manager

MODPY_EGG_VERSION =	3.9.0
DISTNAME =		SQLObject-${MODPY_EGG_VERSION}
PKGNAME =		py-sqlobject-${MODPY_EGG_VERSION}
REVISION =		0

CATEGORIES =		databases

HOMEPAGE =		http://www.sqlobject.org/

# LGPL
PERMIT_PACKAGE =	Yes

FLAVORS =		python3
FLAVOR =		python3

MODPY_PI =		Yes
MODPY_PYTEST =		Yes

MODULES =		lang/python
RUN_DEPENDS =		www/py-formencode${MODPY_FLAVOR} \
			devel/py-dispatcher${MODPY_FLAVOR}
TEST_DEPENDS =		devel/py-nose${MODPY_FLAVOR} \
			devel/py-py${MODPY_FLAVOR} \
			${BASE_PKGPATH}${MODPY_FLAVOR}=${MODPY_EGG_VERSION}

MODPY_SETUPTOOLS =	Yes

post-install:
	mv ${PREFIX}/bin/sqlobject-admin ${PREFIX}/bin/sqlobject-admin${MODPY_BIN_SUFFIX}
	mv ${PREFIX}/bin/sqlobject-convertOldURI ${PREFIX}/bin/sqlobject-convertOldURI${MODPY_BIN_SUFFIX}


do-test:
	cd ${WRKSRC}/sqlobject/tests && ${LOCALBASE}/bin/py.test${MODPY_BIN_SUFFIX}

.include <bsd.port.mk>
