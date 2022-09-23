COMMENT =		tools and libraries to work with EFI

PKGNAME =		efivar-38
SHARED_LIBS +=		efivar                   1.38
SHARED_LIBS +=		efiboot                  1.38
SHARED_LIBS +=		efisec                   1.38
CATEGORIES =		devel

HOMEPAGE =		https://github.com/rhboot/efivar

# LGPL v2.1+
PERMIT_PACKAGE =	Yes

# The project is Linux-oriented, using fork with BSD-specific changes so that
# patches are manageable and can be potentially sent upstream.
#
# The fork also uses unreleased changes as some of them fix build on systems
# that don't use glibc.
DISTNAME =		efivar-38
GH_ACCOUNT =		3mdeb
GH_PROJECT =		efivar
GH_TAGNAME =		bsd-v1

USE_GMAKE = 		Yes
MAKE_FLAGS =		CC=clang MANDIR=${PREFIX}/man LIBDIR=${PREFIX}/lib
# TODO: remove this, when kernel changes are upstream
MAKE_FLAGS +=		CPPFLAGS=-I/sys
FAKE_FLAGS = 		PREFIX=${PREFIX}

.include <bsd.port.mk>
