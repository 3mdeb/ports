# $OpenBSD: Makefile,v 1.37 2021/02/27 18:45:33 sthen Exp $

COMMENT =		tool for installing Python packages

MODPY_EGG_VERSION =	20.3.4
DISTNAME =		pip-${MODPY_EGG_VERSION}
PKGNAME =		py-${DISTNAME}
CATEGORIES =		devel

HOMEPAGE =		https://pip.pypa.io/en/stable/

# MIT
PERMIT_PACKAGE =	Yes

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes

FLAVORS =		python3
FLAVOR ?=

# No test suites in pypi tarball
NO_TEST =		Yes

.include <bsd.port.mk>
