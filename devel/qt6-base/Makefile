PORTNAME=	base
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt base (core, gui, widgets, network,...)

BUILD_DEPENDS=	xml:textproc/xmlstarlet \
		${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers \
		${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	\
		libatk-bridge-2.0.so:accessibility/at-spi2-atk \
		libatspi.so:accessibility/at-spi2-core \
		libatk-1.0.so:accessibility/atk \
		libzstd.so:archivers/zstd \
		libfribidi.so:converters/fribidi \
		libdbus-1.so:devel/dbus \
		libdouble-conversion.so:devel/double-conversion \
		libintl.so:devel/gettext-runtime \
		libicui18n.so:devel/icu \
		libepoll-shim.so:devel/libepoll-shim \
		libevdev.so:devel/libevdev \
		libffi.so:devel/libffi \
		libgudev-1.0.so:devel/libgudev \
		libmtdev.so:devel/libmtdev \
		libudev.so:devel/libudev-devd \
		libunistring.so:devel/libunistring \
		libpcre.so:devel/pcre \
		libpcre2-16.so:devel/pcre2 \
		libidn2.so:dns/libidn2 \
		libgraphite2.so:graphics/graphite2 \
		libjpeg.so:graphics/jpeg-turbo \
		libdrm.so:graphics/libdrm \
		libepoxy.so:graphics/libepoxy \
		libpng16.so:graphics/png \
		libvulkan.so:graphics/vulkan-loader \
		libwayland-client.so:graphics/wayland \
		libgmp.so:math/gmp \
		libavahi-client.so:net/avahi-app \
		libcups.so:print/cups \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libgnutls.so:security/gnutls \
		libtasn1.so:security/libtasn1 \
		libnettle.so:security/nettle \
		libp11-kit.so:security/p11-kit \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libinput.so:x11/libinput \
		libwacom.so:x11/libwacom \
		libxkbcommon.so:x11/libxkbcommon \
		libxcb-util.so:x11/xcb-util \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-render-util.so:x11/xcb-util-renderutil \
		libxcb-ewmh.so:x11/xcb-util-wm

USES=		cmake compiler:c++17-lang gl gnome jpeg perl5 pkgconfig python \
		qt-dist:6 shebangfix xorg
USE_GL=		egl gl
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 pango
USE_XORG=	ice pixman sm x11 xau xcb xcomposite xcursor xdamage xdmcp \
		xext xfixes xi xinerama xrandr xrender
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
