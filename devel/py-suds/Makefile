# $OpenBSD: Makefile,v 1.7 2021/02/23 19:39:19 sthen Exp $

COMMENT =		lightweight python SOAP client

MODPY_EGG_VERSION =	0.4
DISTNAME =		suds-${MODPY_EGG_VERSION}
PKGNAME =		py-${DISTNAME}
REVISION=		1

CATEGORIES =		devel

HOMEPAGE =		https://fedorahosted.org/suds/

MAINTAINER =		Christian Rueger <cr+openbsd@rueger-net.de>

# GPLv3
PERMIT_PACKAGE =		Yes

MODPY_PI =		Yes

MODULES =		lang/python
MODPY_VERSION =	${MODPY_DEFAULT_VERSION_2}

MODPY_SETUPTOOLS =	Yes

.include <bsd.port.mk>
