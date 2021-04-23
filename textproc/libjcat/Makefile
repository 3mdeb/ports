# $OpenBSD: Makefile,v 1.88 2020/05/15 01:32:48 abieber Exp $

COMMENT=	Library for reading and writing JSON catalog files

GH_ACCOUNT=	hughsie
GH_PROJECT=	libjcat
GH_TAGNAME=	0.1.6

CATEGORIES=	textproc

SHARED_LIBS += jcat                  0.1 # 0.1.6

HOMEPAGE=	https://github.com/hughsie/libjcat
MAINTAINER=	Norbert Kaminski <norbert.kaminski@3mdeb.com>

# LGPLv2.1
PERMIT_PACKAGE=	Yes

WANTLIB += c json-glib-1.0 gnutls glib-2.0 gobject-2.0
WANTLIB += gpg-error gpgme gio-2.0 intl

MODULES=	devel/meson \
		textproc/intltool

LIB_DEPENDS=	security/gnutls \
		devel/json-glib \
		security/libgpg-error \
		security/gpgme \
		devel/glib2

BUILD_DEPENDS=	devel/pkgconf \
			lang/vala \
			devel/help2man \
			devel/gettext,-tools \
			textproc/gtk-doc

.include <bsd.port.mk>
