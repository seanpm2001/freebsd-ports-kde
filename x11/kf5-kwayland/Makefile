PORTNAME=	kwayland
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde kde-frameworks

PATCH_SITES=	https://invent.kde.org/frameworks/kwayland/-/commit/
PATCHFILES=	cb13afd8530f651c7d0ce82e47eaa3e1939bd676.diff:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 Client and Server library wrapper for the Wayland libraries

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
		wayland-protocols>=0:graphics/wayland-protocols \
		plasma-wayland-protocols>=0:x11/plasma-wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

USES=		cmake compiler:c++11-lib gettext gl kde:5 pkgconfig \
		qt:5 tar:xz
USE_GL=		egl
USE_KDE=	ecm:build
USE_QT=		concurrent core gui wayland \
		buildtools:build qmake:build testlib:build

.include <bsd.port.mk>
