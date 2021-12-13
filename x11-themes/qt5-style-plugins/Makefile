# Created by: Marie Loise Nolden <loise@kde.org>

PORTNAME=	qt5-style-plugins
PORTVERSIONPREFIX=	v${QT5_KDE_PATCH}
PORTVERSION=	5.0.0-23${QT5_KDE_PATCH}
PORTVERSIONSUFFIX=	-g335dbe${QT5_KDE_PATCH}
PORTREVISION=	10
CATEGORIES=	x11-themes
DIST_SUBDIR=	KDE/Qt/addons

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Additional Styles for Qt 5 and KDE

LICENSE=	LGPL21

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler:c++11-lang gettext-runtime gl gnome pkgconfig qmake \
		qt:5 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	qt
GH_PROJECT=	qtstyleplugins
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 pango
USE_QT=		core dbus gui widgets buildtools_build
USE_GL=		gl
USE_XORG=	x11 xext

.include <bsd.port.mk>
