cmake_minimum_required(VERSION 2.6)

project(Game)

set(Game_SRCS
    src/main.c
)

find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)

set(SDL_ROOT "" CACHE PATH "The location of the SDL install prefix (only used if the SDL is not yet found)")
if(SDL_ROOT)
   set(CMAKE_PREFIX_PATH ${SDL_ROOT})
endif()

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")

#file(COPY ${CMAKE_SOURCE_DIR}/hello.bmp DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

link_libraries(
    ${SDL_LIBRARY}
    ${SDLIMAGE_LIBRARY}
    ${SDLMAIN_LIBRARY}
)

add_executable(
    Game
    WIN32
    # MACOSX_BUNDLE
    ${Game_SRCS}
)

include_directories(${SDL_INCLUDE_DIR})