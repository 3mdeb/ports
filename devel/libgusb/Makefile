# $OpenBSD: Makefile,v 1.88 2020/05/15 01:32:48 abieber Exp $

COMMENT=	GObject wrapper for libusb1

GH_ACCOUNT=	hughsie
GH_PROJECT=	libgusb
GH_TAGNAME=	0.3.6

CATEGORIES=	devel

SHARED_LIBS += gusb                  0.3 # 0.3.6

HOMEPAGE=	https://github.com/hughsie/libgusb
MAINTAINER=	Norbert Kaminski <norbert.kaminski@3mdeb.com>

# LGPLv2.1
PERMIT_PACKAGE=	Yes

WANTLIB=		c glib-2.0 gobject-2.0 gio-2.0
MODULES=		devel/meson

BUILD_DEPENDS=	devel/pkgconf \
			lang/vala \
			devel/gettext,-tools \
			textproc/gtk-doc
LIB_DEPENDS=		devel/glib2 \
			devel/gobject-introspection

.include <bsd.port.mk>
