cmake_minimum_required(VERSION 3.5)

set (PROJECT_NAME "hip-thrust")

project(${PROJECT_NAME})

# If debug, add explicitly add -O0 optimization to override built-in -O3 optimization of HIP compiler
if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -Wall -Wextra -Wno-unused-function")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-unused-function")
endif()

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrust/ DESTINATION include/thrust USE_SOURCE_PERMISSIONS)

# Packaging directives
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VENDOR "AMD")
set(CPACK_PACKAGE_VERSION_MAJOR ${BUILD_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${BUILD_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${BUILD_VERSION_PATCH})
set(CPACK_PACKAGE_CONTACT "Ben Sander (ben.sander@amd.com)")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "HIP back-end for Thrust (alpha release).")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/NOTICE")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
include(CPack)
