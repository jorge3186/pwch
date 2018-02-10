#**********************************************************
# pwch Header Files
# All header files need to be declared here.
#**********************************************************
file(GLOB PWCH_ROOT_HEADERS "${PROJECT_SOURCE_DIR}/app/include/pwch/*.h")
file(GLOB PWCH_API_HEADERS "${PROJECT_SOURCE_DIR}/app/include/pwch/api/*.h")
file(GLOB PWCH_GUI_HEADERS "${PROJECT_SOURCE_DIR}/app/include/pwch/gui/*.h")

file(GLOB PWCH_HEADERS 
    ${PWCH_ROOT_HEADERS}
    ${PWCH_API_HEADERS}
    ${PWCH_GUI_HEADERS}
)
include_directories("${PROJECT_SOURCE_DIR}/app/include")

#**********************************************************
# pwch Source Files
# All source files need to be declared here.
#**********************************************************
file(GLOB PWCH_ROOT_SRC "${PROJECT_SOURCE_DIR}/app/src/pwch/*.cpp")
file(GLOB PWCH_API_SRC "${PROJECT_SOURCE_DIR}/app/src/pwch/api/*.cpp")
file(GLOB PWCH_GUI_SRC "${PROJECT_SOURCE_DIR}/app/src/pwch/gui/*.cpp")

file(GLOB PWCH_SRC
    ${PWCH_ROOT_SRC}
    ${PWCH_API_SRC}
    ${PWCH_GUI_SRC}
)

# Source Group the Files to fix paths
# in IDEs
source_group("Header Files\\pwch" FILES ${PWCH_ROOT_HEADERS})
source_group("Header Files\\pwch\\api" FILES ${PWCH_API_HEADERS})
source_group("Header Files\\pwch\\gui" FILES ${PWCH_GUI_HEADERS})

source_group("Source Files\\pwch" FILES ${PWCH_ROOT_SRC})
source_group("Source Files\\pwch\\api" FILES ${PWCH_API_SRC})
source_group("Source Files\\pwch\\gui" FILES ${PWCH_GUI_SRC})

# create exec file with project sources
add_executable(pwch ${PWCH_SRC} ${PWCH_HEADERS})

# Link All dependent libraries
target_link_libraries(pwch ${wxWidgets_LIBRARIES})

# If on windows, we need to let
# windows know to build windows application
# and not a console app (default)
if(WIN32)
	if(MSVC)
		set_target_properties(pwch PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS")
		set_target_properties(pwch PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:WINDOWS")
	endif(MSVC)
endif(WIN32)
#target_link_libraries(pwch aws-cpp-sdk-core aws-cpp-sdk-dynamodb)
