.if !defined(_BSD_PLASMA6_MK_INCLUDED)

_BSD_PLASMA6_MK_INCLUDED=	yes
.include "${.CURDIR:H:H}/x11/plasma6-plasma/files/bsd.plasma6-version.mk"

_VERSION_SUFFIX=	${_KDE_PLASMA6_VERSION_${PORTNAME}}
KDE_PLASMA_VERSION=	6.0.0-g${_VERSION_SUFFIX}

# component definitions
kde-plasma-wayland-protocols_PORT=	x11/plasma6-plasma-wayland-protocols
kde-plasma-wayland-protocols_PATH=	TODO

kde-kuserfeedback_PORT=			deskutils/plasma6-kuserfeedback
kde-kuserfeedback_LIB=			TODO

kde-polkit-qt-1_PORT=			sysutils/plasma6-polkit-qt-1
kde-polkit-qt-1_LIB=			TODO

kde-libqaccessibilityclient_PORT=	accessibility/plasma6-libqaccessibilityclient
kde-libqaccessibilityclient_LIB=	TODO

kde-libkexiv2_PORT=			graphics/plasma6-libkexiv2
kde-libkexiv2_LIB=			TODO

kde-kpipewire_PORT=			audio/plasma6-kpipewire
kde-kpipewire_LIB=			TODO

kde-breeze_PORT=			x11-themes/plasma6-breeze
kde-breeze_PATH=			TODO

kde-kactivitymanagerd_PORT=		x11/plasma6-kactivitymanagerd
kde-kactivitymanagerd_LIB=		TODO

kde-kdecoration_PORT=			x11-wm/plasma6-kdecoration
kde-kdecoration_LIB=			TODO

kde-kscreenlocker_PORT=			security/plasma6-kscreenlocker
kde-kscreenlocker_LIB=			TODO

kde-kwayland-integration_PORT=		x11/plasma6-kwayland-integration
kde-kwayland-integration_LIB=		TODO

kde-kwin_PORT=				x11-wm/plasma6-kwin
kde-kwin_LIB=				TODO

kde-layer-shell-qt_PORT=		x11/plasma6-layer-shell-qt
kde-layer-shell-qt_LIB=			TODO

kde-libkscreen_PORT=			x11/plasma6-libkscreen
kde-libkscreen_LIB=			TODO

kde-libksysguard_PORT=			sysutils/plasma6-libksysguard
kde-libksysguard_LIB=			TODO

kde-milou_PORT=				deskutils/plasma6-milou
kde-milou_LIB=				TODO

kde-oxygen_PORT=			x11-themes/plasma6-oxygen
kde-oxygen_PATH=			TODO

kde-plasma-desktop_PORT=		x11/plasma6-plasma-desktop
kde-plasma-desktop_LIB=			TODO

kde-plasma-nano_PORT=			x11/plasma6-plasma-nano
kde-plasma-nano_LIB=			TODO

kde-plasma-workspace_PORT=		x11/plasma6-plasma-workspace
kde-plasma-workspace_LIB=		TODO

kde-plasma5support_PORT=		x11/plasma6-plasma5support
kde-plasma5support_LIB=			TODO

kde-powerdevil_PORT=			sysutils/plasma6-powerdevil
kde-powerdevil_LIB=			TODO

kde-systemsettings_PORT=		sysutils/plasma6-systemsettings
kde-systemsettings_LIB=			TODO

kde-kglobalacceld_PORT=			x11/plasma6-kglobalacceld
kde-kglobalacceld_LIB=			TODO

kde-selenium-webdriver-at-spi_PORT=	www/plasma6-selenium-webdriver-at-spi
kde-selenium-webdriver-at-spi_LIB=	TODO

# copyied from kde.mk 
_USE_KDE_ALL=	${_KDE_PLASMA6_COMPONENTS}
# Iterate through components deprived of suffix.
.  for component in ${USE_KDE:O:u:C/:.+//}
  # Check that the component is valid.
.    if ${_USE_KDE_ALL:M${component}} != ""
   # Skip meta-components (currently none).
.      if defined(kde-${component}_PORT) && (defined(kde-${component}_PATH) || defined(kde-${component}_LIB))
    # Check if a dependency type is explicitly requested.
.        if ${USE_KDE:M${component}\:*} != "" && ${USE_KDE:M${component}} == ""
kde-${component}_TYPE=	# empty
.          if ${USE_KDE:M${component}\:build} != ""
kde-${component}_TYPE+=	build
.          endif
.          if ${USE_KDE:M${component}\:run} != ""
kde-${component}_TYPE+=	run
.          endif
.        endif # ${USE_KDE:M${component}_*} != "" && ${USE_KDE:M${component}} == ""
    # If no dependency type is set, default to full dependency.
.        if !defined(kde-${component}_TYPE)
kde-${component}_TYPE=	build run
.        endif
    # Set real dependencies.
.        if defined(kde-${component}_LIB) && ${kde-${component}_TYPE:Mbuild} && ${kde-${component}_TYPE:Mrun}
LIB_DEPENDS+=			${kde-${component}_LIB}:${kde-${component}_PORT}
.        else
kde-${component}_PATH?=		${KDE_PREFIX}/lib/${kde-${component}_LIB}
kde-${component}_DEPENDS=	${kde-${component}_PATH}:${kde-${component}_PORT}
.          if ${kde-${component}_TYPE:Mbuild} != ""
BUILD_DEPENDS+=			${kde-${component}_DEPENDS}
.          endif
.          if ${kde-${component}_TYPE:Mrun} != ""
RUN_DEPENDS+=			${kde-${component}_DEPENDS}
.          endif
.        endif # ${kde-${component}_LIB} && ${kde-${component}_TYPE:Mbuild} && ${kde-${component}_TYPE:Mrun}
.      endif # defined(kde-${component}_PORT) && defined(kde-${component}_PATH)
.    else # ! ${_USE_KDE_ALL:M${component}} != ""
IGNORE=				cannot be installed: unknown USE_KDE component '${component}'
.    endif # ${_USE_KDE_ALL:M${component}} != ""
.  endfor

.endif
