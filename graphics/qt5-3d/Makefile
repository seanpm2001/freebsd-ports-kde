PORTNAME=	3d
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
CATEGORIES=	graphics
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt3D module

LIB_DEPENDS=	libassimp.so:multimedia/assimp

USES=		compiler:c++11-lang perl5 pkgconfig qmake:norecursive qt-dist:5,3d
USE_PERL5=	extract
USE_QT=		concurrent core declarative gui network buildtools_build

QT_BINARIES=	yes

.include <bsd.port.mk>
