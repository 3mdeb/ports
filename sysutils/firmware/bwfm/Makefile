# $OpenBSD: Makefile,v 1.9 2021/04/05 14:30:04 sthen Exp $

FW_DRIVER=	bwfm
LINUX_VER=	20200316
SUP_VER=	1.2
REVISION=	0
FW_VER=		${LINUX_VER}.${SUP_VER}
DISTNAME=	linux-firmware-${LINUX_VER}
EXTRACT_SUFX=	.tar.xz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		brcm-supplemental-${SUP_VER}.tar.gz:1
# broad enough to reduce WRKSRC size but specific enough to match both DISTFILES
EXTRACT_FILES=	\*/{brcm\*.{bin,txt},LICEN[CS]E\*}

MAINTAINER=	Patrick Wildt <patrick@blueri.se>

MASTER_SITES=	https://cdn.kernel.org/pub/linux/kernel/firmware/
MASTER_SITES1=	https://github.com/bsdkurt/brcm-supplemental/archive/

HOMEPAGE=	https://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/tree/brcm

SUP_DIR=	${WRKDIR}/brcm-supplemental-brcm-supplemental-${SUP_VER}

do-install:
	${INSTALL_DATA} ${WRKSRC}/brcm/*bin ${PREFIX}/firmware/
	${INSTALL_DATA} ${WRKSRC}/brcm/*txt ${PREFIX}/firmware/
	${INSTALL_DATA} ${SUP_DIR}/*bin ${PREFIX}/firmware/
	${INSTALL_DATA} ${SUP_DIR}/*txt ${PREFIX}/firmware/
	${INSTALL_DATA} ${SUP_DIR}/brcmfmac4356-sdio.vamrs,rock960.txt \
		${PREFIX}/firmware/brcmfmac4356-sdio.friendlyarm,nanopc-t4.txt
	${INSTALL_DATA} ${WRKSRC}/LICENCE.broadcom_bcm43xx \
	    ${PREFIX}/firmware/bwfm-license

.include <bsd.port.mk>
