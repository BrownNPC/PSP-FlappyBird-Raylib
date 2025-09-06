cmake_minimum_required(VERSION 3.17)

project(game)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# PSP SDK
set(PSPDEV $ENV{PSPDEV})

file(GLOB SOURCES src/*.c src/*.cpp)

add_executable(game ${SOURCES})
target_include_directories(game PRIVATE include)

# Link with raylib
find_package(raylib REQUIRED)
target_link_libraries(game PUBLIC raylib)
target_link_libraries(game PUBLIC -lpthread)

# link with box2d
include(FetchContent)
FetchContent_Declare(
  box2d
  GIT_REPOSITORY https://github.com/erincatto/box2d.git
  GIT_TAG v3.1.1
)
FetchContent_MakeAvailable(box2d)
target_link_libraries(game PUBLIC box2d)
# make clangd happy
target_compile_options(game
  PRIVATE
    "--sysroot=${PSPDEV}/psp"
    "-I=${PSPDEV}/psp/include"
    "-I=${PSPDEV}/psp/sdk/include"
    "-I${PSPDEV}/psp/include/c++/15.1.1"
)


create_pbp_file(
  TARGET game
  TITLE change this in CMakeLists.txt
  ICON_PATH "${CMAKE_CURRENT_SOURCE_DIR}/assets/icon.png"
  BUILD_PRX=1
  ENC_PRX=1
)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR}) 
