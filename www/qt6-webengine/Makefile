### ---------------------------------------------------
### /!\ WARNING /!\ WARNING /!\ WARNING /!\ WARNING /!\
### ---------------------------------------------------
### The current state is at the moment:
###
###     >>> "It compiles...let's sell it!" [*] <<<
###
### [*] On 12.2-RELEASE amd64 for ALSA/PULSE/SNDIO and
###     with/without DEBUG
### ---------------------------------------------------
### /!\ WARNING /!\ WARNING /!\ WARNING /!\ WARNING /!\
### ---------------------------------------------------

# TODO XXX
# - If built via WITH_DEBUG then CMAKE_BUILD_TYPE is "Release" during the whole
#   build and leads to plist issues at the end.
# - Examine the issues with the spellchecker feature (see below for further
#   details).
# - Check for the 'XXX's in ${FILESDIR}/*
# - Test build on aarch64 and other platforms
# - Check webcam functionality
# - runtime tests...oh my

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

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libdbus-1.so:devel/dbus \
		libevent.so:devel/libevent \
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

# XXX Python 2.7 is still required to build it...
USES=	bison cmake gl gnome gperf jpeg localbase:ldflags ninja:build \
	nodejs:build,lts pkgconfig python:2.7,build qt-dist:6,webengine xorg
# We need ar(1) from ports because the Chromium code uses the @file syntax.
# We then need to ensure ld(1) from ports is used because of the archives ar(1)
# generated.
USE_BINUTILS=	yes
USE_GL=		gl
USE_GNOME=	glib20 libxml2 libxslt
USE_QT=		base declarative_run quick3d_build
QT_BINARIES=	yes
USE_XORG=	x11 xcb xcomposite xcursor xdamage xext xfixes xi xkbfile \
		xrandr xscrnsaver xshmfence xtst

CMAKE_ON=	QT_FEATURE_webengine_system_ffmpeg QT_FEATURE_webengine_proprietary_codecs
# XXX If enabled (via autodetect), the "convert_dict.stamp" isn't created
#     during build and lead to failures at the near end
CMAKE_OFF=	QT_FEATURE_webengine_spellchecker

# The build system reads the environment variable $NINJA_PATH to decide whether
# to boostrap ninja or not (and also to invoke it afterwards). CC and CXX are
# read by some Chromium code to determine which compiler to invoke when running
# some configuration tests.
# Since we use USES=qmake:norecursive, we also need to pass some variables to
# MAKE_ENV because part of the configuration process happens during the build.
CONFIGURE_ENV+=	NINJAFLAGS="-j${MAKE_JOBS_NUMBER}" \
		NINJA_PATH="${LOCALBASE}/bin/ninja"  \
		PATH=${CONFIGURE_WRKSRC}/bin:${LOCALBASE}/bin:${PATH}
MAKE_ENV+=	CC="${CC}" CXX="${CXX}"			\
		C_INCLUDE_PATH=${LOCALBASE}/include	\
		CPLUS_INCLUDE_PATH=${LOCALBASE}/include	\
		${CONFIGURE_ENV}

# XXX Setting "CC" and "CXX" to "-B${LOCALBASE}/bin" doesn't work anymore due
# some compiler checks via cmake.
CFLAGS+=		"-B${LOCALBASE}/bin"
CXXFLAGS+=		"-B${LOCALBASE}/bin"

# XXX Do we plan to use a own description for qt6-webengine?
DESCR=		${PORTSDIR}/devel/qt6-base/pkg-descr

DISTINFO_FILE=	${.CURDIR}/distinfo
QT6_VERSION=	6.2.2

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

post-extract-SNDIO-on:
	@cd ${WRKSRC}/src/3rdparty/chromium/media/audio && ${MKDIR} sndio openbsd
	@${CP} ${FILESDIR}/sndio_*put.* \
		${WRKSRC}/src/3rdparty/chromium/media/audio/sndio
	@${CP} ${FILESDIR}/audio_manager_openbsd.* \
		${WRKSRC}/src/3rdparty/chromium/media/audio/openbsd

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/src/3rdparty/chromium/base/linux_util.cc \
		${WRKSRC}/src/3rdparty/chromium/build/toolchain/gcc_toolchain.gni \
		${WRKSRC}/src/3rdparty/chromium/chrome/common/chrome_paths.cc \
		${WRKSRC}/src/3rdparty/chromium/third_party/pdfium/core/fxge/fx_ge_linux.cpp \
		${WRKSRC}/src/3rdparty/gn/build/gen.py

pre-configure:
# Link in ${PYTHON_CMD} to ${CONFIGURE_WRKSRC}/bin -- the scripts hardcode 'python'
# in too many places to reasonably patch. So just link in ${PYTHON_CMD} to work around
# $LOCALBASE/bin/python being python3 if the default versions is set to 3.x.
	${MKDIR} ${CONFIGURE_WRKSRC}/bin && ${LN} -s ${PYTHON_CMD} ${CONFIGURE_WRKSRC}/bin/python

.include <bsd.port.post.mk>
