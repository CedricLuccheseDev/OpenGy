cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)

set(EXECUTABLE_NAME "OpenGy")

project(${EXECUTABLE_NAME})

add_definitions(-std=c++11 -fPIC)

find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
endif()

SET(CMAKE_CXX_FLAGS  "-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio")
SET(CMAKE_EXE_LINKER_FLAGS  "-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio")

set(LIBS ".")
set(LVISUAL "${LIBS}/Visual")
set(LAUDIO "${LIBS}/Audio")
set(LUTILS "${LIBS}/Utils")
set(LRESSOURCES "${LIBS}/Ressources")
set(LSCENE "${LIBS}/Scene")
set(LENGINE "${LIBS}/Engine")

# ADD VISUAL LIB
include_directories("${LVISUAL}/Include")
# ADD AUDIO LIB
include_directories("${LAUDIO}/Include")
# ADD UTILS LIB
include_directories("${LUTILS}/Include")
# ADD RESSOURCES LIB
include_directories("${LRESSOURCES}/Include")
# ADD SCENE LIB
include_directories("${LSCENE}/Include")
# ADD SCENE LIB
include_directories("${LENGINE}/Include")

ADD_LIBRARY(${EXECUTABLE_NAME} STATIC
${LVISUAL}/Sources/Sfml/Sprite.cpp
${LVISUAL}/Sources/Sfml/Window.cpp
${LVISUAL}/Sources/Sfml/Text.cpp
${LRESSOURCES}/Sources/Parser/ParserRessourcesFiles.cpp
${LRESSOURCES}/Sources/Sfml/Ressources.cpp
${LSCENE}/Sources/Parser/ParserSceneFiles.cpp
${LSCENE}/Sources/Sfml/Manager.cpp
${LSCENE}/Sources/Sfml/View.cpp
${LSCENE}/Sources/Functions/Functions.cpp
${LAUDIO}/Sources/Sfml/Sound.cpp
${LENGINE}/Sources/Instance.cpp
${LENGINE}/Sources/Component.cpp
${LENGINE}/Sources/Entity.cpp
${LENGINE}/Sources/System.cpp
)

target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
