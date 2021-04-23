# $OpenBSD: Makefile,v 1.88 2020/05/15 01:32:48 abieber Exp $

COMMENT=	Help create and query binary XML blobs

GH_ACCOUNT=	hughsie
GH_PROJECT=	libxmlb
GH_TAGNAME=	0.3.0

CATEGORIES=	textproc

SHARED_LIBS += xmlb                  0.3 # 0.3.0

HOMEPAGE=	https://github.com/hughsie/libxmlb
MAINTAINER=	Norbert Kaminski <norbert.kaminski@3mdeb.com>

# LGPLv2.1
PERMIT_PACKAGE=	Yes

WANTLIB += c glib-2.0 gobject-2.0 gio-2.0 girepository-1.0
MODULES=	devel/meson

BUILD_DEPENDS=	devel/pkgconf \
			devel/gettext,-tools \
			textproc/gtk-doc

LIB_DEPENDS=	devel/glib2

.include <bsd.port.mk>
