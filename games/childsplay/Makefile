# $OpenBSD: Makefile,v 1.33 2021/03/08 21:07:17 remi Exp $

COMMENT=	collection of educational activities for young children

DISTNAME=	childsplay-3.3
EXTRACT_SUFX=	.tgz

CATEGORIES=	games education

HOMEPAGE=	http://www.childsplay.mobi/

# GPLv3
PERMIT_PACKAGE=	Yes

MASTER_SITES=	${MASTER_SITE_SAVANNAH:=/childsplay/}

MODULES=	lang/python
MODPY_VERSION =	${MODPY_DEFAULT_VERSION_2}

# NO_BUILD=Yes but python(1) is used in do-install
BUILD_DEPENDS=	${_MODPY_BUILD_DEPENDS}

RUN_DEPENDS=	databases/py-sqlalchemy \
		devel/pygame \
		x11/py-gtk2

NO_TEST=	Yes
NO_BUILD=	Yes

MODPY_ADJ_FILES=childsplay.py

pre-configure:
	echo '#!/bin/sh' >${WRKSRC}/childsplay.sh
	echo >>${WRKSRC}/childsplay.sh
	echo 'cd ${MODPY_SITEPKG}/childsplay' >>${WRKSRC}/childsplay.sh
	echo 'exec ${MODPY_BIN} childsplay.py $$@' >>${WRKSRC}/childsplay.sh

do-install:
	${INSTALL_DATA_DIR} ${WRKINST}/${MODPY_SITEPKG}/childsplay
	${INSTALL_SCRIPT} ${WRKSRC}/childsplay.sh ${PREFIX}/bin/childsplay
	${INSTALL_DATA} ${WRKSRC}/*.py \
		${WRKINST}/${MODPY_SITEPKG}/childsplay
	cp -Rp ${WRKSRC}/locale ${PREFIX}/share
	${INSTALL_DATA} ${WRKSRC}/sp_content.db \
		${WRKINST}/${MODPY_SITEPKG}/childsplay
.for i in SPWidgets alphabet-sounds lib
	cp -Rp ${WRKSRC}/$i ${WRKINST}/${MODPY_SITEPKG}/childsplay
.endfor
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${WRKINST}/${MODPY_SITEPKG}/childsplay
	chown -R ${SHAREOWN}:${SHAREGRP} \
		${WRKINST}/${MODPY_SITEPKG}/childsplay \
		${PREFIX}/share/locale

.include <bsd.port.mk>
