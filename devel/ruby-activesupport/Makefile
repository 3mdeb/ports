# $OpenBSD: Makefile,v 1.44 2021/03/31 11:43:41 sebastia Exp $

COMMENT =		support libraries and Ruby extensions extracted from Rails

DISTNAME =		activesupport-6.1.3.1
CATEGORIES =		devel
MAINTAINER =		Sebastian Reitenbach <sebastia@openbsd.org>

# MIT
PERMIT_PACKAGE =	Yes

MODULES =		lang/ruby

BUILD_DEPENDS +=	${RUN_DEPENDS}
RUN_DEPENDS +=		devel/ruby-concurrent-ruby,${MODRUBY_FLAVOR},>=1.0.2,<2 \
			devel/ruby-i18n,${MODRUBY_FLAVOR},>=0.7,<2 \
			devel/ruby-minitest,${MODRUBY_FLAVOR}>=5.1,<6 \
			devel/ruby-zeitwerk,${MODRUBY_FLAVOR}>=2.3,<3 \
			sysutils/ruby-tzinfo,${MODRUBY_FLAVOR}>=2.0,<3
				

CONFIGURE_STYLE = 	ruby gem

.include <bsd.port.mk>
