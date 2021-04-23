# $OpenBSD: Makefile,v 1.88 2020/05/15 01:32:48 abieber Exp $

COMMENT=	fwupd - firmware update tool

GH_ACCOUNT=	fwupd
GH_PROJECT=	fwupd
GH_COMMIT=	cd474377d587d3074c2620ec0c11b42be827a153
DISTNAME=	fwupd-1.5.9

CATEGORIES=	sysutils

HOMEPAGE=	https://github.com/fwupd/fwupd
MAINTAINER=	Norbert Kaminski <norbert.kaminski@3mdeb.com>

# LGPLv2.1
PERMIT_PACKAGE=	Yes

WANTLIB += c gcab-1.0 xmlb jcat gusb girepository-1.0 glib-2.0
WANTLIB += json-glib-1.0 sqlite3 curl archive gio-2.0

MODULES=	devel/meson \
		textproc/intltool

LIB_DEPENDS=	archivers/gcab \
		textproc/libxmlb \
		textproc/libjcat \
		devel/libgusb \
		devel/gobject-introspection \
		devel/glib2 \
		devel/json-glib \
		databases/sqlite3 \
		net/curl \
		archivers/libarchive

BUILD_DEPENDS=	devel/pkgconf \
			lang/vala \
			devel/gettext,-tools \
			textproc/gtk-doc

CONFIGURE_ARGS+=	-Dplugin_uefi_capsule='false' \
			-Dplugin_dell='false' \
			-Dplugin_redfish='false' \
			-Dplugin_nvme='false' \
			-Dplugin_amt='false' \
			-Dplugin_emmc='false' \
			-Dplugin_altos='false' \
			-Dplugin_thunderbolt='false' \
			-Dplugin_synaptics_mst='false' \
			-Dplugin_msr='false' \
			-Dpolkit='false' \
			-Dman='false' \
			-Dgudev='false' \
			-Dtests='false'\
			-Dplugin_tpm='false' \
			-Dsystemd='false' \
			-Dlibjcat:man='false' \
			-Dplugin_synaptics_rmi='false' \
			-Dgcab:docs='false' \
			-Dlibxmlb:docs='false'

.include <bsd.port.mk>
