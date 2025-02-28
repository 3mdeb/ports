# $OpenBSD: Makefile,v 1.88 2021/03/27 14:35:12 sthen Exp $

COMMENT =		ebook management application

V =			5.14.0
DISTNAME =		calibre-$V

CATEGORIES =		textproc

HOMEPAGE =		https://calibre-ebook.com/

# GPLv3
PERMIT_PACKAGE =	Yes

WANTLIB += ${COMPILER_LIBCXX} GL Qt5Core Qt5DBus Qt5Gui Qt5Widgets
WANTLIB += crypto fontconfig freetype glib-2.0 gthread-2.0 hunspell-1.7
WANTLIB += hyphen icudata icui18n icuio icuuc intl m podofo ${MODPY_WANTLIB}
WANTLIB += z

MASTER_SITES =	https://github.com/kovidgoyal/calibre/releases/download/v${V}/
EXTRACT_SUFX =	.tar.xz

MODULES =	lang/python \
		x11/qt5

COMMON_DEPENDS =	databases/py-apsw${MODPY_FLAVOR}>=3.34.0 \
			devel/py-dateutil${MODPY_FLAVOR} \
			devel/py-html5lib${MODPY_FLAVOR} \
			devel/py-regex${MODPY_FLAVOR} \
			devel/xdg-utils \
			graphics/libwmf \
			graphics/png \
			graphics/py-Pillow${MODPY_FLAVOR} \
			net/py-dnspython${MODPY_FLAVOR} \
			net/py-msgpack${MODPY_FLAVOR} \
			net/py-zeroconf${MODPY_FLAVOR} \
			print/poppler \
			print/poppler,-qt5 \
			textproc/py-css-parser${MODPY_FLAVOR} \
			textproc/py-cssselect${MODPY_FLAVOR} \
			textproc/py-cssutils${MODPY_FLAVOR} \
			textproc/py-lxml${MODPY_FLAVOR} \
			textproc/py-markdown${MODPY_FLAVOR} \
			textproc/py-toml${MODPY_FLAVOR} \
			textproc/py-webencodings${MODPY_FLAVOR} \
			www/py-CherryPy${MODPY_FLAVOR} \
			www/py-beautifulsoup4${MODPY_FLAVOR} \
			www/py-html5-parser${MODPY_FLAVOR} \
			www/py-mechanize${MODPY_FLAVOR} \
			www/py-qtwebengine${MODPY_FLAVOR} \
			x11/py-qt5${MODPY_FLAVOR}

LIB_DEPENDS =		devel/gettext,-runtime \
			textproc/hunspell \
			textproc/hyphen \
			textproc/icu4c \
			textproc/podofo

BUILD_DEPENDS =		${COMMON_DEPENDS} \
			devel/py-qt-builder${MODPY_FLAVOR} \
			sysutils/py-packaging${MODPY_FLAVOR}

RUN_DEPENDS =		${COMMON_DEPENDS} \
			converters/py-html2text${MODPY_FLAVOR} \
			devel/desktop-file-utils \
			misc/shared-mime-info \
			net/py-netifaces${MODPY_FLAVOR}  \
			print/poppler,-utils \
			x11/gtk+3,-guic

SUBST_VARS =		WRKDIR

LDFLAGS +=		-L${LOCALBASE}/lib

MAKE_ENV +=		CALIBRE_PY3_PORT=1 \
			FT_LIB_DIR="${X11BASE}/lib" \
			LDFLAGS="${LDFLAGS}" \
			OVERRIDE_CFLAGS="${CFLAGS}" \
			OVERRIDE_LDFLAGS="${LDFLAGS}" \
			PODOFO_INC_DIR="${LOCALBASE}/include/podofo" \
			PODOFO_LIB_DIR="${LOCALBASE}/lib" \
			QMAKE="${MODQT_QMAKE}" \
			WITH_USB=yes \
			XDG_DATA_DIRS="${PREFIX}/share" \
			XDG_UTILS_INSTALL_MODE=system

PORTHOME =		${WRKDIR}
NO_TEST =		Yes
MODPY_SETUPTOOLS =	Yes

## setup.py doesn't like the options in our python module
MODPY_DISTUTILS_BUILD =		build
MODPY_DISTUTILS_INSTALL =	install --prefix=${LOCALBASE} \
				--root=${PREFIX}

# Cannot use MODPY_ADJ_FILES as there are ERANGE files with hard-coded shebang
pre-patch:
	cd ${WRKSRC} && find . -type f -name '*.py' -exec ${MODPY_BIN_ADJ} {} +

# Remove bundled cherrypy so it uses the system version
pre-configure:
	cd ${WRKSRC} && rm -rf src/cherrypy
	cd ${WRKSRC}/setup && ${SUBST_CMD} build.py build_environment.py
	cp ${FILESDIR}/fake-xdg ${WRKDIR}/bin; chmod +x ${WRKDIR}/bin/fake-xdg
.for i in xdg-icon-resource xdg-desktop-menu xdg-mime
	ln -s fake-xdg ${WRKDIR}/bin/$i
.endfor

do-install:
	${MODPY_CMD} ${MODPY_DISTUTILS_INSTALL} ${MODPY_DISTUTILS_INSTALLARGS}
	${INSTALL_DATA_DIR} ${PREFIX}/share/calibre/recipes
	cd ${WRKSRC}/recipes && find . -type f -exec \
	    ${INSTALL_DATA} {} ${PREFIX}/share/calibre/recipes/ \;

post-install:
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py ${PREFIX}/lib/calibre
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py ${PREFIX}/share/calibre

.include <bsd.port.mk>
