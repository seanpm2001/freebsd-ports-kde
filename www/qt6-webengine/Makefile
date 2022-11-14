### ---------------------------------------------------
### /!\ WARNING /!\ WARNING /!\ WARNING /!\ WARNING /!\
### ---------------------------------------------------
### The current state is at the moment:
###
###     >>> "It compiles...let's sell it!" [*] <<<
###
### [*] On 13.1-RELEASE amd64 for ALSA/PULSE/SNDIO and
###     with/without DEBUG
### ---------------------------------------------------
### /!\ WARNING /!\ WARNING /!\ WARNING /!\ WARNING /!\
### ---------------------------------------------------

# TODO XXX
# - Examine the issues with the spellchecker feature (see below for further
#   details).
# - Check for the 'XXX's in the Makefile, ${FILESDIR}/* and in Mk/*
# - Do we still need binutils?
# - Test build on aarch64 and other platforms
# - Check webcam functionality
# - runtime tests...oh my
# - Add remaining patches
# - Webcam
# - Remove USB, HID, Unittest Stuff
# - Check ulimit settings (-n 4096 not allowed during build) (seems no longer
#   be required and the shells/bash dependency can be dropped)
# - Check BSD strip vs. bintools strip
# - bintools seems not to be required anymore...really?

# QtWebEngine itself is a very thin layer of Qt code on top of a large part of
# Chromium (everything up to the content/ layer). As such, most of the work in
# this port revolves around taming Chromium and getting it to build on FreeBSD.
# While it does build at the moment, there are several items that should be
# investigated or improved:
# - We are using several stub files, especially in Chromium's base/ and net/
#   layers. We should look at implementing the missing bits instead.
# - We are currently not using any sandboxing mechanism.
# - We need to see if more "use_system_<FOO>" flags can be passed.
# - The process of porting QtWebEngine needs to be documented so we can move to
#   newer releases more easily.
#
# Also note that, due to the insane amount of patches this port needs, it tends
# to lag behind the rest of the official Qt6 ones, which is why we set
# QT6_VERSION and DISTINFO_FILE here.

PORTNAME=	webengine
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	www
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 6 library to render web content

# XXX Is this still required?
#BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
#		bash:shells/bash \

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat \
		${PYTHON_PKGNAMEPREFIX}html5lib>0:www/py-html5lib@${PY_FLAVOR} \
		${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libdbus-1.so:devel/dbus \
		libevent.so:devel/libevent \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		liblcms2.so:graphics/lcms2 \
		libminizip.so:archivers/minizip \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libopus.so:audio/opus \
		libpci.so:devel/libpci \
		libpng.so:graphics/png \
		libre2.so:devel/re2 \
		libsnappy.so:archivers/snappy \
		libvpx.so:multimedia/libvpx \
		libwebp.so:graphics/webp \
		libxkbcommon.so:x11/libxkbcommon

# XXX Are these libs still required?
#LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libdouble-conversion.so:devel/double-conversion \
		libjsoncpp.so:devel/jsoncpp \

USES=	bison cmake gl gnome gperf jpeg localbase:ldflags ninja:build \
	nodejs:build,lts pkgconfig python:build qt-dist:6,webengine xorg
# We need ar(1) from ports because the Chromium code uses the @file syntax.
# We then need to ensure ld(1) from ports is used because of the archives ar(1)
# generated.
# XXX Building seems to work without binutils...
#USE_BINUTILS=	yes
USE_GL=		gl
USE_GNOME=	glib20 libxml2 libxslt
USE_QT=		base declarative:run quick3d:build
QT_BINARIES=	yes
USE_XORG=	x11 xcb xcomposite xcursor xdamage xext xfixes xi xkbfile \
		xrandr xrender xscrnsaver xshmfence xtst

CMAKE_ON=	QT_FEATURE_webengine_system_ffmpeg QT_FEATURE_webengine_proprietary_codecs
# XXX If enabled (via autodetect), the "convert_dict.stamp" isn't created
#     during build and lead to failures at the near end
# 
# If the "convert_dict.stamp" is created by hand during build, the build process succeeds then.
#     /usr/local/poudriere/data/.m/123Ramd64-qt6/ref/wrkdirs/usr/ports/www/qt6-webengine/work-normal/.build/src/core/Debug/amd64/convert_dict
CMAKE_OFF=	QT_FEATURE_webengine_spellchecker
#MAKE_JOBS_UNSAFE=yes

# The build system reads the environment variable $NINJA_PATH to decide whether
# to boostrap ninja or not (and also to invoke it afterwards). CC and CXX are
# read by some Chromium code to determine which compiler to invoke when running
# some configuration tests.
CONFIGURE_ENV+=	NINJAFLAGS="-j${MAKE_JOBS_NUMBER}" \
		NINJA_PATH="${LOCALBASE}/bin/ninja"  \
		PATH=${CONFIGURE_WRKSRC}/bin:${LOCALBASE}/bin:${PATH}
MAKE_ENV+=	CC="${CC}" CXX="${CXX}"			\
		C_INCLUDE_PATH=${LOCALBASE}/include	\
		CPLUS_INCLUDE_PATH=${LOCALBASE}/include	\
		${CONFIGURE_ENV}

# XXX Setting "CC" and "CXX" to "-B${LOCALBASE}/bin" doesn't work anymore due
# some compiler checks via cmake.
#CFLAGS+=		"-B${LOCALBASE}/bin"
#CXXFLAGS+=		"-B${LOCALBASE}/bin"

# XXX This is required at the moment to avoid error like this:
# ld: error: /usr/lib/crtn.o:(.debug_aranges+0x6): relocation R_X86_64_32 out of range: 4948421891 is not in [0, 4294967295]; consider recompiling with -fdebug-types-section to reduce size of debug sections
#CFLAGS+=	-fdebug-types-section
#CXXFLAGS+=	-fdebug-types-section
#
# Also disable TMPFS in poudriere
# But linking requires a loooong time to complete
#
# 12.1 has clang 10 which seems too old to compile the debug build:
# In file included from ../../../../../qtwebengine-everywhere-src-6.4.0/src/3rdparty/chromium/v8/src/deoptimizer/translation-array.h:8:
# ../../../../../qtwebengine-everywhere-src-6.4.0/src/3rdparty/chromium/v8/src/codegen/register.h:29:48: error: member reference base type 'RegListBase' is not a structure or union
#   int num_different_regs = RegListBase{regs...}.Count();
#                              ~~~~~~~~~~~~~~~~~~~~^~~~~~
#                              ../../../../../qtwebengine-everywhere-src-6.4.0/src/3rdparty/chromium/v8/src/codegen/register.h:29:7: warning: uninitialized variable in a constexpr function is a C++20 extension [-Wc++20-extensions]
#                                int num_different_regs = RegListBase{regs...}.Count();
#                                      ^
#
#WITH_DEBUG=	yes

# XXX Do we plan to use a own description for qt6-webengine?
DESCR=		${PORTSDIR}/devel/qt6-base/pkg-descr

DISTINFO_FILE=	${.CURDIR}/distinfo
QT6_VERSION=	6.4.0

OPTIONS_DEFAULT=	ALSA
OPTIONS_SINGLE=		AUDIO
OPTIONS_SINGLE_AUDIO=	ALSA PULSEAUDIO SNDIO

AUDIO_DESC=		Audio backend

# Need the alsa plugins to get sound at runtime, otherwise messages
# that the pcm_oss plugin can't be opened.
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	alsa-plugins>=0:audio/alsa-plugins
ALSA_CMAKE_ON=		-DQT_FEATURE_webengine_system_alsa:BOOL=ON
ALSA_CMAKE_OFF=		-DQT_FEATURE_webengine_system_alsa:BOOL=OFF
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_ON=	-DQT_FEATURE_webengine_system_pulseaudio:BOOL=ON
PULSEAUDIO_CMAKE_OFF=	-DQT_FEATURE_webengine_system_pulseaudio:BOOL=OFF
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CMAKE_ON=		-DQT_FEATURE_webengine_system_sndio:BOOL=ON
SNDIO_CMAKE_OFF=	-DQT_FEATURE_webengine_system_sndio:BOOL=OFF

.include <bsd.port.pre.mk>

#.if defined(WITH_DEBUG)
#USES+=	compiler:c++20-lang
#.endif

# Add extra-patch-no-mempcpy-nasm only when there's no mempcpy() in base.
# Nested variable expansion avoids executing the test when not needed for
# expanding EXTRA_PATCHES.
# mempcpy was introduced in ee37f64cf875255338f917a9da76c643cf59786c
EXTRA_PATCHES+=	${"${:!${GREP} mempcpy ${CROSS_SYSROOT}/usr/include/string.h \
		|| ${TRUE}!}" == "":?${PATCHDIR}/extra-patch-no-mempcpy-nasm:}

post-extract:
	@${MKDIR} ${WRKSRC}/src/3rdparty/chromium/media/audio/sndio \
		${WRKSRC}/src/3rdparty/chromium/sandbox/policy/freebsd \
		${WRKSRC}/src/3rdparty/chromium/sandbox/policy/openbsd

post-patch:
	# XXX Maybe there's still a better way to inject these args into the build process...
	# The BUILD.toolchain.gn.in still needs to be reworked as it contains hardcoded values
	#@${REINPLACE_CMD} -e 's|%%CXXFLAGS%%|${CXXFLAGS}|;s|%%LDFLAGS%%|${LDFLAGS}|' \
		${WRKSRC}/src/host/BUILD.toolchain.gn.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/src/3rdparty/chromium/third_party/pdfium/core/fxge/linux/fx_linux_impl.cpp \
		${WRKSRC}/src/3rdparty/chromium/third_party/wayland/features.gni

pre-configure:
# Link in ${PYTHON_CMD} to ${CONFIGURE_WRKSRC}/bin -- the scripts hardcode 'python'
# in too many places to reasonably patch. So just link in ${PYTHON_CMD} to work around
# $LOCALBASE/bin/python being python3 if the default versions is set to 3.x.
	${MKDIR} ${CONFIGURE_WRKSRC}/bin && ${LN} -s ${PYTHON_CMD} ${CONFIGURE_WRKSRC}/bin/python

# XXX We used to remove bundled libraries to be sure that chromium uses
# system libraries and not shipped ones.
# cd ${WRKSRC} && ${PYTHON_CMD} \
# ./build/linux/unbundle/remove_bundled_libraries.py [list of preserved]
	cd ${WRKSRC}/src/3rdparty/chromium && ${SETENV} ${CONFIGURE_ENV} ${PYTHON_CMD} \
		./build/linux/unbundle/replace_gn_files.py --system-libraries \
		fontconfig freetype harfbuzz-ng libdrm libevent libpng libxml libxslt opus || ${FALSE}
		# XXX Try to unbundle a few more libraries
		# libwebp snappy
		# flac icu? libvpx openh264 re2 zlib

.include <bsd.port.post.mk>
