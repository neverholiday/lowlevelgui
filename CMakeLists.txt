#   Required minimum version
cmake_minimum_required(VERSION 3.17.0)

#   Project
project( coredump-generator )

#   Find package
find_package(FLTK REQUIRED)

#   Add executable file
add_executable( coredump_generator_ui coredump_generator_ui.c++ )
add_executable( coredump_generator coredump_generator.c++ )

target_link_libraries( coredump_generator_ui ${FLTK_LIBRARIES} )

#
#       Debian
#

set(FILE_LISTS 
        "coredump_generator_ui" 
        "coredump_generator")

install(TARGETS ${FILE_LISTS}
        DESTINATION "/usr/bin/"
)

# SET(CPACK_GENERATOR "DEB")
# SET(CPACK_DEBIAN_VERSION "1.0.0")
# SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "nashay") #required

SET(MAJOR_VERSION "1")
SET(MINOR_VERSION "0")
SET(PATCH_VERSION "2")


SET(CPACK_GENERATOR "DEB")

SET(CPACK_PACKAGE_VENDOR "nashay")
SET(CPACK_PACKAGE_CONTACT "nashay@yannix.com")
SET(CPACK_PACKAGE_VERSION_MAJOR "${MAJOR_VERSION}")
SET(CPACK_PACKAGE_VERSION_MINOR "${MINOR_VERSION}")
SET(CPACK_PACKAGE_VERSION_PATCH "${PATCH_VERSION}")
SET(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "all")
SET(CPACK_PACKAGE_DESCRIPTION "coredump generator package implement on fltk")
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "GUI for demo coredump package and hook by apport")
SET(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}_${MAJOR_VERSION}.${MINOR_VERSION}.${CPACK_PACKAGE_VERSION_PATCH}_${CPACK_DEBIAN_PACKAGE_ARCHITECTURE}")
SET(CPACK_SOURCE_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}_${MAJOR_VERSION}.${MINOR_VERSION}.${CPACK_PACKAGE_VERSION_PATCH}_${CPACK_DEBIAN_PACKAGE_ARCHITECTURE}")

INCLUDE(CPack)

