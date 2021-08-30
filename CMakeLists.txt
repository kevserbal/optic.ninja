###########################################################
# CMakeLists.txt generated from qmake-project optic.ninja #
###########################################################

# ... Project setup ...
project(opticninja)
cmake_minimum_required(VERSION 3.16.3)

#OPTION(USECV2 "Use OpenCV 2" OFF)
#OPTION(USECV3 "Use OpenCV 3" OFF)
#OPTION(USECV4 "Use OpenCV 4" ON)

#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#ADD_DEFINITIONS(-DUSECV2=0 -DUSECV3=0 -DUSECV4=1)
OPTION(APP_VERSION "Set Application Version" 1.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CPACK_BINARY_DEB ON)

FIND_PACKAGE(Qt5Core REQUIRED)
FIND_PACKAGE(Qt5Gui REQUIRED)
FIND_PACKAGE(Qt5Widgets REQUIRED)
FIND_PACKAGE(Qt5Sql REQUIRED)

#set(BUILD_SHARED_LIBS ON)
#set(OpenCV_FIND_QUIETLY FALSE)
FIND_PACKAGE(OpenCV REQUIRED)

INCLUDE_DIRECTORIES(${Qt5_USE_FILE})
INCLUDE_DIRECTORIES(${Qt5Core_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${Qt5Gui_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${Qt5Widgets_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${Qt5Sql_INCLUDE_DIRS})

INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})
        
ADD_DEFINITIONS(${QT_DEFINITIONS})

ADD_DEFINITIONS(-fPIC)

# Source files
SET(SRCS
    src/main.cpp
    src/mainwindow.cpp
    src/FrameLabel.cpp
    src/objectdetection.cpp
    src/utility.cpp
    src/detectionThread.cpp
    src/setimage.cpp
    src/createSetDialog.cpp
    src/imageview.cpp
    src/setcontrol.cpp
    src/appsettings.cpp
    src/imagegraphicsview.cpp
    src/imageview/opticrectangle.cpp
    src/datalocal.cpp
    src/setannotations.cpp
    src/annotation.cpp
    src/filelistmodel.cpp
    src/exportdataset.cpp
    src/mainwindow.ui 
    src/createsetdialog.ui 
    src/imageview.ui 
    src/imagegraphicsview.ui
)

# Header files
SET(HDRS
    src/mainwindow.h
    src/structures.h
    src/FrameLabel.h
    src/objectdetection.h
    src/utility.h
    src/detectionThread.h
    src/setimage.h
    src/createSetDialog.h
    src/imageview.h
    src/setcontrol.h
    src/appsettings.h
    src/imagegraphicsview.h
    src/imageview/opticrectangle.h
    src/datalocal.h
    src/annotation.h
    src/filelistmodel.h
    src/exportdataset.h
)

# UI files
SET(UIS
    src/mainwindow.ui
    src/createsetdialog.ui
    src/imageview.ui
    src/imagegraphicsview.ui
)

qt5_wrap_cpp(MOC_SOURCES ${HDRS})
qt5_wrap_ui(UI_HEADERS ${UIS})
ADD_EXECUTABLE(opticninja ${SRCS} ${MOC_SOURCES})
TARGET_INCLUDE_DIRECTORIES(opticninja PUBLIC "/mnt/3ec544f3-901f-475c-ba8b-fb1b3e062c15/QT/5.15.0/gcc_64")
TARGET_LINK_LIBRARIES(opticninja ${Qt5Core_QTMAIN_LIBRARIES} ${QT_LIBRARIES} ${QT_QSQL_LIBRARIES} ${OpenCV_LIBS} Qt5Core Qt5Gui Qt5Widgets Qt5Sql)

#set(CPACK_DEBIAN_PACKAGE_DEPENDS "libqt4-gui")
qt5_use_modules(opticninja Widgets ${QT_LIBRARIES} ${QT_QSQL_LIBRARIES})


set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Annotation Project")
set(CPACK_PACKAGE_VENDOR "Me")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "CMake ${CMake_VERSION_MAJOR}.${CMake_VERSION_MINOR}")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Me")
set(CPACK_COMPONENT_ALL "DEB")
set(CPACK_COMPONENTS_ALL "DEB")
set(CPACK_ARCHIVE_COMPONENT_INSTALL 1)
set(CPACK_PACKAGING_INSTALL_PREFIX "/home")
install(TARGETS opticninja DESTINATION /usr/bin)

if(WIN32 AND NOT UNIX)
  # There is a bug in NSI that does not handle full UNIX paths properly.
  # Make sure there is at least one set of four backlashes.
  set(CPACK_PACKAGE_ICON "${CMake_SOURCE_DIR}/Utilities/Release\\\\InstallIcon.bmp")
  set(CPACK_NSIS_INSTALLED_ICON_NAME "bin\\\\MyExecutable.exe")
  set(CPACK_NSIS_DISPLAY_NAME "${CPACK_PACKAGE_INSTALL_DIRECTORY} My Famous Project")
  set(CPACK_NSIS_HELP_LINK "http:\\\\\\\\www.my-project-home-page.org")
  set(CPACK_NSIS_URL_INFO_ABOUT "http:\\\\\\\\www.my-personal-home-page.com")
  set(CPACK_NSIS_CONTACT "me@my-personal-home-page.com")
  set(CPACK_NSIS_MODIFY_PATH ON)
else()
  set(CPACK_STRIP_FILES "bin/opticninja")
  set(CPACK_SOURCE_STRIP_FILES "")
endif()
set(CPACK_PACKAGE_EXECUTABLES "opticninja" "Optic Ninja")
include(CPack)




