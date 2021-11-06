PORTNAME=	base
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt base (core, gui, widgets, network,...)

BUILD_DEPENDS=	xml:textproc/xmlstarlet \
		${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libcups.so:print/cups \
		libdrm.so:graphics/libdrm \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libicui18n.so:devel/icu \
		libicuuc.so:devel/icu \
		libinput.so:x11/libinput \
		libmtdev.so:devel/libmtdev \
		libodbc.so:databases/unixODBC \
		libpcre2-16.so:devel/pcre2 \
		libpng16.so:graphics/png \
		libudev.so:devel/libudev-devd \
		libzstd.so:archivers/zstd \
		libdouble-conversion.so:devel/double-conversion \
		libvulkan.so:graphics/vulkan-loader \
		libxcb-ewmh.so:x11/xcb-util-wm \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-util.so:x11/xcb-util \
		libxcb-render-util.so:x11/xcb-util-renderutil \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-xrm.so:x11/xcb-util-xrm \
		libXcursor.so:x11/libXcursor \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++17-lang gl gnome jpeg perl5 pkgconfig python shebangfix \
		qt-dist:6 xorg
USE_GL=		egl gl
USE_GNOME=	glib20 gtk30 pango
USE_XORG=	x11 xrender xcb ice sm xext xi
CMAKE_ON=	QT_AVOID_CMAKE_ARCHIVING_API \
		QT_FIND_ALL_PACKAGES_ALWAYS
CMAKE_OFF=	QT_FEATURE_eglfs \
		QT_FEATURE_gssapi
SHEBANG_FILES=	${WRKSRC}/mkspecs/features/uikit/device_destinations.sh \
		${WRKSRC}/mkspecs/features/uikit/devices.py \
		${WRKSRC}/mkspecs/features/data/mac/objc_namespace.sh \
		${WRKSRC}/util/android/android_emulator_launcher.sh
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

# zstd from base fails to compress files during the build (error 11: unsupported argument)
BINARY_ALIAS=	zstd=${LOCALBASE}/bin/zstd

#== Option handling
OPTIONS_GROUP=		SQL
OPTIONS_GROUP_SQL=	IBASE MYSQL ODBC PSQL SQLITE
OPTIONS_DEFAULT=	SQLITE
OPTIONS_SUB=		yes

IBASE_DESC=		InterBase database support
IBASE_CMAKE_ON=		-DFEATURE_sql_ibase=ON
IBASE_CMAKE_OFF=	-DFEATURE_sql_ibase=OFF
IBASE_USES=		firebird:4.0
IBASE_BROKEN=		IBASE: fatal error: 'gen/iberror.h' file not found

MYSQL_DESC=		MySQL database support
MYSQL_CMAKE_ON=		-DFEATURE_sql_mysql=ON
MYSQL_CMAKE_OFF=	-DFEATURE_sql_mysql=OFF
MYSQL_USES=		mysql

ODBC_DESC=		ODBC database support
ODBC_CMAKE_ON=		-DFEATURE_sql_odbc=ON
ODBC_CMAKE_OFF=		-DFEATURE_sql_odbc=OFF
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC

PSQL_DESC=		PostgreSQL database support
PSQL_CMAKE_ON=		-DFEATURE_sql_psql=ON
PSQL_CMAKE_OFF=		-DFEATURE_sql_psql=OFF
PSQL_USES=		pgsql

SQLITE_DESC=		Sqlite database support
SQLITE_CMAKE_ON=	-DFEATURE_sql_sqlite=ON \
			-DQT_FEATURE_system_sqlite=ON
SQLITE_CMAKE_OFF=	-DFEATURE_sql_sqlite=OFF
SQLITE_USES=		sqlite:3

# TODO: do this cleaner -- somewhere cmake/qmake still creates empty directories
# for the cmake files in INSTALL_PREFIX/lib/cmake
post-install:
	${RM} -vr ${STAGEDIR}${PREFIX}/${QT_LIBDIR_REL}/cmake
	# Install symlinks for user-facing tools
	${REINPLACE_CMD} -e "s#^#${STAGEDIR}#" -e "s# # ${STAGEDIR}#" \
		${WRKDIR}/.build/user_facing_tool_links.txt
	while read t; do \
		${RLN} $$t; \
	done <${WRKDIR}/.build/user_facing_tool_links.txt

.include <bsd.port.mk>
