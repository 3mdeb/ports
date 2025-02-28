# $OpenBSD: Makefile,v 1.39 2021/04/02 14:42:28 sthen Exp $

COMMENT=		Python Imaging Library (maintained fork of PIL)

MODPY_EGG_VERSION=	8.2.0
DISTNAME=		Pillow-${MODPY_EGG_VERSION}
PKGNAME=		py-${DISTNAME}
CATEGORIES=		graphics

HOMEPAGE=		https://python-pillow.org/

# PIL Software License
# Permission to use, copy, modify and distribute freely.
PERMIT_PACKAGE=	Yes

WANTLIB += freetype jpeg lcms2 openjp2 pthread tiff webp webpdemux
WANTLIB += webpmux z

FLAVORS=		python3
FLAVOR=			python3

MODPY_PI =		Yes

MODULES=		lang/python
MODPY_PYTEST=		Yes
MODPY_SETUPTOOLS=	Yes
DEBUG_PACKAGES=		${BUILD_PACKAGES}

LIB_DEPENDS=		graphics/lcms2 \
			graphics/openjp2>=2.3.0p0 \
			graphics/libwebp
TEST_DEPENDS=		${FULLPKGNAME}:${BUILD_PKGPATH} \
			sysutils/py-packaging${MODPY_FLAVOR}

SUBST_VARS+=		INCL_DIR MODPY_FLAVOR
INCL_DIR=		${MODPY_INCDIR:S/${LOCALBASE}\///}

pre-test:
	cd ${WRKSRC}; ${MODPY_BIN} ./selftest.py
	# Removing PyQt-related tests that segfault
	cd ${WRKSRC}/Tests; rm -f test_qt_image_fromqpixmap.py test_qt_image_toqimage.py test_qt_image_toqpixmap.py

post-install:
	${INSTALL_DATA_DIR} ${WRKINST}${MODPY_INCDIR}
	${INSTALL_DATA} ${WRKSRC}/src/libImaging/{ImPlatform,Imaging}.h ${WRKINST}${MODPY_INCDIR}

.include <bsd.port.mk>
