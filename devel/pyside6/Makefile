PORTNAME=	pyside6
DISTVERSION=	${PYSIDE6_VERSION}
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/QtForPython/shiboken6/PySide6-${DISTVERSION}-src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyside-setup-everywhere-src-${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python Qt bindings for Qt 6
WWW=		https://wiki.qt.io/Qt_for_Python

LICENSE=	LGPL3

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers \
		git>0:devel/git \
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx
LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader \
		libshiboken6.abi${PYTHON_MAJOR_VER}.so:devel/shiboken6@${PY_FLAVOR}

USES=		cmake gl llvm:${LLVM_DEFAULT},lib python qt:6 tar:xz
USE_GL=		gl
USE_LDCONFIG=	yes
USE_PYTHON=	flavors
USE_QT=		3d 5compat base charts declarative doc imageformats multimedia \
		networkauth positioning quick3d quicktimeline remoteobjects \
		sensors serialbus serialport shadertools svg tools translations \
		wayland webchannel websockets

CMAKE_ARGS+=	-DPYTHON_EXECUTABLE=${PYTHON_CMD}

.include <bsd.port.pre.mk>

PLIST_SUB+=	PYVERSTR=.cpython-${PYTHON_SUFFIX}${PYTHON_ABIVER}
PLIST_SUB+=	DISTVERSION=${DISTVERSION}

WRKSRC=		${WRKDIR}/pyside-setup-everywhere-src-${DISTVERSION:R}/sources/pyside6

.if ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB+=	WEBENGINE=""
USE_QT+=	webengine
.else
PLIST_SUB+=	WEBENGINE="@comment "
.endif

.include <bsd.port.post.mk>
