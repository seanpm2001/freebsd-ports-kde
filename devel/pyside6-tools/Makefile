PORTNAME=	pyside6-tools
DISTVERSION=	${PYSIDE6_VERSION}
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/QtForPython/shiboken6/PySide6-${DISTVERSION}-src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyside-setup-everywhere-src-${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Pyside6 development tools
WWW=		https://wiki.qt.io/Qt_for_Python

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers \
		git>0:devel/git
LIB_DEPENDS=	libshiboken6.abi${PYTHON_MAJOR_VER}.so:devel/shiboken6@${PY_FLAVOR} \
		libpyside6.abi${PYTHON_MAJOR_VER}.so:devel/pyside6@${PY_FLAVOR} \
		libxkbcommon.so:x11/libxkbcommon \
		libzstd.so:archivers/zstd \

USES=		cmake gl llvm:${LLVM_DEFAULT},lib python qt:6 shebangfix tar:xz xorg
USE_GL=		gl
USE_PYTHON=	flavors
USE_QT=		base tools languageserver declarative

SHEBANG_FILES=	pyside_tool.py qtpy2cpp_lib/tests/baseline/basic_test.py

CMAKE_ARGS+=	-DQT6_INSTALL_PREFIX=${LOCALBASE}/lib/qt6 \
		-DCMAKE_EXECUTABLE_SUFFIX=6

WRKSRC=		${WRKDIR}/pyside-setup-everywhere-src-${DISTVERSION:R}/sources/pyside-tools

.include <bsd.port.mk>
