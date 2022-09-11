COMMENT =		library for EFI boot devices management

PKGNAME =		libefiboot-38
SHARED_LIBS +=		efiboot                  1.38
CATEGORIES =		devel

HOMEPAGE =		https://github.com/rhboot/efivar

# LGPL v2.1+
PERMIT_PACKAGE =	Yes
WANTLIB =		

DISTNAME =		efivar-38
MASTER_SITES =		https://github.com/rhboot/efivar/releases/download/38/
EXTRACT_SUFX =		.tar.bz2

USE_GMAKE = 		Yes
MAKE_FILE =		Makefile
MAKE_FLAGS =		-C src CC=clang LIBTARGETS=libefiboot.so PCTARGETS=efiboot.pc TARGETS=libefiboot.so\ efiboot.pc BINTARGETS=
MAKE_ENV =		TOPDIR=${WRKBUILD}
FAKE_FLAGS = 		PREFIX=${PREFIX}

.include <bsd.port.mk>
