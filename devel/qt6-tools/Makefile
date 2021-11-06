PORTNAME=	tools
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt declarative framework for dynamic user interfaces

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers \
		llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}
LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader \
		libLLVM.so:devel/llvm${LLVM_DEFAULT}

USES=		cmake compiler:c++17-lang gl python:build \
		qt-dist:6
USE_GL=		gl
USE_QT=		base declarative
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

CMAKE_ARGS+=	-DClang_DIR:PATH="${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/cmake/clang" \
		-DLLVM_DIR:PATH="${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/cmake/llvm"

post-install:
	# Install symlinks for user-facing tools
	${REINPLACE_CMD} -e "s#^#${STAGEDIR}#" -e "s# # ${STAGEDIR}#" \
		${WRKDIR}/.build/user_facing_tool_links.txt
	while read t; do \
		${RLN} $$t; \
	done <${WRKDIR}/.build/user_facing_tool_links.txt

.include <bsd.port.mk>
