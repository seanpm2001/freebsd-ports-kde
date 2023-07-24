PORTNAME=	shiboken6
DISTVERSION=	${PYSIDE6_VERSION}
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/QtForPython/${PORTNAME}/PySide6-${DISTVERSION}-src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyside-setup-everywhere-src-${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python binding generator for C++ libraries
WWW=		http://qt-project.org

LICENSE=	GPLv2 LGPL21 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers \
		git>0:devel/git \
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx
LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader \
		libxslt.so:textproc/libxslt

USES=		cmake compiler:c++17-lang gnome llvm:${LLVM_DEFAULT},lib \
		localbase python qt:6 shebangfix tar:xz
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_PYTHON=	flavors
USE_QT=		5compat base declarative doc imageformats networkauth quick3d \
		quicktimeline shadertools svg tools translations wayland

CMAKE_ARGS+=	-DClang_DIR:PATH="${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/cmake/clang" \
		-DLLVM_DIR:PATH="${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/cmake/llvm" \
		-DCMAKE_CXX_FLAGS=-lexecinfo \
		-DCMAKE_STANDARD_LIBRARIES=-lexecinfo \
		-DCMAKE_CXX_STANDARD_LIBRARIES=-lexecinfo \
		-DUSE_PYTHON_VERSION=${PYTHON_VER} \
		-DBUILD_TESTS:BOOL=false

.include <bsd.port.pre.mk>

PLIST_SUB=	DISTVERSION=${DISTVERSION} \
		PYVERSTR=.cpython-${PYTHON_SUFFIX}${PYTHON_ABIVER}
WRKSRC=		${WRKDIR}/pyside-setup-everywhere-src-${DISTVERSION:R}/sources/shiboken6

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/shiboken_tool.py

.include <bsd.port.post.mk>
