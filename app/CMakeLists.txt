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
include_directories(${PWCH_HEADERS})

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

# If using Visual Studio:
# We set source groups for the Header/Source files
# so they are included properly with correct paths.
if(MSVC)
    source_group("Header Files\\pwch" FILES ${PWCH_ROOT_HEADERS})
    source_group("Header Files\\pwch\\api" FILES ${PWCH_API_HEADERS})
    source_group("Header Files\\pwch\\gui" FILES ${PWCH_GUI_HEADERS})

    source_group("Source Files\\pwch" FILES ${PWCH_ROOT_SRC})
    source_group("Source Files\\pwch\\api" FILES ${PWCH_API_SRC})
    source_group("Source Files\\pwch\\gui" FILES ${PWCH_GUI_SRC})
endif(MSVC)

# create exec file with project sources
add_executable(pwch ${PWCH_SRC})

# Link All dependent libraries
target_link_libraries(pwch ${wxWidgets_LIBRARIES})
if(WIN32)
	if(MSVC)
		set_target_properties(pwch PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS")
		set_target_properties(pwch PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:WINDOWS")
	endif(MSVC)
endif(WIN32)
#target_link_libraries(pwch aws-cpp-sdk-core aws-cpp-sdk-dynamodb)
