# $OpenBSD: Makefile,v 1.5 2021/02/19 23:13:05 sthen Exp $

COMMENT=		client for the whois.cymru.com service

MODPY_EGG_VERSION=	1.6
DISTNAME=		cymruwhois-${MODPY_EGG_VERSION}
PKGNAME=		py-${DISTNAME}
REVISION=		2

CATEGORIES=		net

MAINTAINER=		Denis Fondras <denis@openbsd.org>

# MIT
PERMIT_PACKAGE=	Yes

MODULES=		lang/python
MODPY_PI=		Yes
MODPY_SETUPTOOLS=	Yes
MODPY_ADJ_FILES=	cymruwhois.py

FLAVORS =		python3
FLAVOR ?=

TEST_DEPENDS =		devel/py-nose${MODPY_FLAVOR}

post-install:
	mv ${PREFIX}/bin/cymruwhois ${PREFIX}/bin/cymruwhois${MODPY_BIN_SUFFIX}

.include <bsd.port.mk>
