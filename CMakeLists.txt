cmake_minimum_required(VERSION 3.16)

project(SpeachToText VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶
#|                                                                                  |
#|                                    Packages                                      |
#|                                                                                  |
#̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶

find_package(Qt6 6.2 COMPONENTS Charts Core Gui Qml Quick Multimedia Network REQUIRED)

#̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶
#|                                                                                  |
#|                                  Directories                                     |
#|                                                                                  |
#̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶

include_directories(${CMAKE_SOURCE_DIR}/includes/libs)
include_directories(${CMAKE_SOURCE_DIR}/includes)
include_directories(${CMAKE_SOURCE_DIR}/src)
include("C:/Qt/Tools/sdktool/android_openssl-master/android_openssl.cmake")

#̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶
#|                                                                                  |
#|                                  Files path                                      |
#|                                                                                  |
#̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶

file(GLOB SOURCES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)
file(GLOB HEADERS RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/includes/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/includes/libs/*.h"
)
# file(GLOB QML_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
#     "${CMAKE_CURRENT_SOURCE_DIR}/Components/*.qml"
#     "${CMAKE_CURRENT_SOURCE_DIR}/Components/*/*.qml"
# )

#̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶
#|                                                                                  |
#|                                  Execution                                       |
#|                                                                                  |
#̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶

qt_add_executable(SpeachToText)

add_android_openssl_libraries(SpeachToText)

qt_add_qml_module(SpeachToText
    URI SpeachToText
    VERSION 1.0
    SOURCES ${SOURCES}
    SOURCES ${HEADERS}
    # QML_FILES ${QML_FILES}
    RESOURCES Resources.qrc
)

#̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶
#|                                                                                  |
#|                               Locate libs path                                   |
#|                                                                                  |
#̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶

set(LIB_DIR ${CMAKE_SOURCE_DIR}/libs)
set(LIB_FILES)

if(ANDROID)
    set(LIB_FILES
        ${LIB_DIR}/arm64-v8a/libvosk.so
        ${LIB_DIR}/arm64-v8a/libqmicroz.so
    )
    # Ensure libraries are included in the APK
    # set_target_properties(SpeachToText PROPERTIES
    #     QT_ANDROID_EXTRA_LIBS "${LIB_FILES}"
    # )
elseif(WIN32)
    set(LIB_FILES
        ${LIB_DIR}/Windows/libvosk.lib
        ${LIB_DIR}/Windows/qmicroz.lib
    )
# # Copy DLLs to the executable directory
#     set(DLL_FILES
#         ${LIB_DIR}/Windows/libvosk.dll
#         ${LIB_DIR}/Windows/qmicroz.dll
#     )
#     foreach(DLL ${DLL_FILES})
#         add_custom_command(TARGET SpeachToText POST_BUILD
#             COMMAND ${CMAKE_COMMAND} -E copy_if_different
#             ${DLL}
#             $<TARGET_FILE_DIR:SpeachToText>
#         )
#     endforeach()
endif()

#̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶
#|                                                                                  |
#|                                    Set targerts                                  |
#|                                                                                  |
#̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶

set_target_properties(SpeachToText PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

#̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶
#|                                                                                  |
#|                                     Libraries                                    |
#|                                                                                  |
#̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶

target_link_libraries(SpeachToText
    PRIVATE
    Qt::Charts
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::Quick
    Qt6::Multimedia
    Qt6::Network
    # ${LIB_DIR}/arm64-v8a/libcrypto.so
    # ${LIB_DIR}/arm64-v8a/libssl.so
    # ${LIB_DIR}/arm64-v8a/libvosk.so
    # ${LIB_DIR}/arm64-v8a/libqmicroz.so
    # ${LIB_DIR}/x86_64/libvosk.so
    # ${LIB_DIR}/x86_64/libqmicroz.so
    # ${LIB_DIR}/Windows/libvosk.lib
    # ${LIB_DIR}/Windows/qmicroz.lib
    ${LIB_FILES}
)

#̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶
#|                                                                                  |
#|                                 Custom commands                                  |
#|                                                                                  |
#̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶̶

add_custom_command(TARGET SpeachToText
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_if_different
                           ${LIB_FILES}
                           $<TARGET_FILE_DIR:SpeachToText>
                   COMMENT "Copying libs to executable directory")

include(GNUInstallDirs)
install(TARGETS SpeachToText
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

qt_import_qml_plugins(SpeachToText)
