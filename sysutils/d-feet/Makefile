# $OpenBSD: Makefile,v 1.58 2021/02/23 19:39:41 sthen Exp $

COMMENT=		dbus debugger

GNOME_VERSION=		0.3.15
GNOME_PROJECT=		d-feet
MODPY_EGG_VERSION=	${GNOME_VERSION}
REVISION=		2

CATEGORIES=		sysutils

# GPLv2
PERMIT_PACKAGE=		Yes

MODULES=		devel/dconf \
			devel/meson \
			lang/python \
			x11/gnome

MODGNOME_TOOLS += desktop-file-utils gobject-introspection gtk-update-icon-cache
MODGNOME_TOOLS += yelp

BUILD_DEPENDS=		x11/gtk+3

# needed for tests
BUILD_DEPENDS +=	devel/py-codestyle${MODPY_FLAVOR}

RUN_DEPENDS=		devel/py-gobject3${MODPY_FLAVOR}

# pygobject GTK3 introspection (not provided by indirect dependencies)
RUN_DEPENDS +=		x11/gtk+3

# src/dfeet/wnck_utils.py
RUN_DEPENDS +=		devel/libwnck3

TEST_IS_INTERACTIVE=	x11

.include <bsd.port.mk>
