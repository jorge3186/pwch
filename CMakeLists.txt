# We aren't using anything specific from 3.0, but 
# by now everyone should be at least >= 3.0
cmake_minimum_required(VERSION 3.0)

# Project Declaration
project(pwch)


#**************************************************
# wxWidgets - REQUIRED
#**************************************************
# Set the WX_ROOT_DIR to point to the wxWidgets
# root directory.
# Default: ${PROJECT_SOURCE_DIR}/dependencies/wxWidgets
#
# If Cmake is unable to find wxWidgets libraries
# the build will fail
#
#**************************************************
set(WX_ROOT_DIR "${PROJECT_SOURCE_DIR}/dependencies/wxWidgets" CACHE STRING "Root Path to wxWidgets")
set(wxWidgets_ROOT_DIR ${WX_ROOT_DIR})
set(wxWidgets_LIB_DIR "${WX_ROOT_DIR}/lib/vc_lib" CACHE PATH "wxWidgets Library Directory")

if (WIN32)
	set(wxWidgets_CONFIGURATION "mswud" CACHE STRING "COnfiguration for wxWdigdets: msw, mswd, mswu, etc.")
endif(WIN32)

find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})


#**************************************************
# aws-cpp-sdk - REQUIRED
#**************************************************
# Need to specify the root dir for aws-sdk as
# well as the build dir. and the packages 
# that are included.
# If all packages are to be included, then
# it defaults to ALL and does not need to be
# overriden.
#
#**************************************************
set(AWS_ROOT "${PROJECT_SOURCE_DIR}/dependencies/aws-sdk-cpp" CACHE STRING "Root Path to aws-sdk-cpp")
set(AWS_BUILD_DIR "${AWS_ROOT}/build-dynamodb" CACHE STRING "aws-sdk-cpp build directory. Default to ./build. Path Relative to AWS_ROOT")
set(aws-sdk-cpp_DIR "${AWS_ROOT}/${AWS_BUILD_DIR}" CACHE STRING "Path to aws-sdk build dir.")
add_definitions(-DUSE_IMPORT_EXPORT)
include_directories("${AWS_ROOT}/aws-cpp-sdk-core/include")
include_directories("${AWS_ROOT}/aws-cpp-sdk-dynamodb/include")


# Add app/CMakeLists.txt to build path
add_subdirectory(app)