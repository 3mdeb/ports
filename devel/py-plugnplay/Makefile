# $OpenBSD: Makefile,v 1.5 2020/11/21 14:46:07 benoit Exp $

COMMENT =	a generic plug-in system for python

MODPY_EGG_VERSION =	0.5.4
DISTNAME =	plugnplay-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME}

CATEGORIES =	devel

HOMEPAGE =	https://github.com/daltonmatos/plugnplay

# GPLv2
PERMIT_PACKAGE =	Yes

MODULES =	lang/python
MODPY_SETUPTOOLS = Yes
MODPY_PI =	Yes

FLAVORS =	python3
FLAVOR ?=

.include <bsd.port.mk>
