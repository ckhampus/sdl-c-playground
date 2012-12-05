cmake_minimum_required(VERSION 2.6)

project(Game)

set(Game_SRCS
    src/main.c
)

find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)

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