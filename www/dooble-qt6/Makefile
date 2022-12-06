PORTNAME=	dooble
DISTVERSION=	2022.11.15
CATEGORIES=	www
PKGNAMESUFFIX=	-qt6

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Dooble Web Browser (Area51)
WWW=		https://textbrowser.github.io/dooble/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++17-lang desktop-file-utils gl gmake qmake qt:6 ssl \
		tar xorg
USE_GITHUB=	yes
GH_ACCOUNT=	textbrowser
USE_GL=		gl
USE_QT=		base charts webengine
USE_XORG=	xcb

QMAKE_SOURCE_PATH=	${PORTNAME}.pro

PLIST_FILES=	${PREFIX}/share/applications/${PORTNAME}.desktop \
		${PREFIX}/share/pixmaps/${PORTNAME}.png \
		bin/${PORTNAME}

.include <bsd.port.pre.mk>

QT5_VER_MINOR=	${QT5_VERSION:C/^[0-9]+\.//:C/\..+$//}
.if ${QT5_VER_MINOR} < 15
BROKEN=		Qt 5.15 or higher required, using 5.${QT5_VER_MINOR} now
.endif

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/Dooble ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
		${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
		${INSTALL_DATA} ${WRKSRC}/Icons/Logo/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
		desktop-file-edit --remove-category=Web --add-category=Network --add-category=WebBrowser ${WRKSRC}/${PORTNAME}.desktop
		desktop-file-edit --set-key=Exec --set-value=${PREFIX}/bin/${PORTNAME} ${WRKSRC}/${PORTNAME}.desktop
		desktop-file-edit --set-icon=${PREFIX}/share/pixmaps/${PORTNAME}.png ${WRKSRC}/${PORTNAME}.desktop
		${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop

.include <bsd.port.post.mk>
