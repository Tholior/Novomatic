cmake_minimum_required(VERSION 3.30)
project(Kolizje)

set(CMAKE_CXX_STANDARD 20)

# Dependencies
set(RAYLIB_VERSION 5.5)
find_package(raylib ${RAYLIB_VERSION} QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_MakeAvailable(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    endif()
endif()

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(Kolizje
        main.cpp
        triangle.hpp
        vec2.hpp
        collision.hpp
        collision.cpp
)
target_link_libraries(Kolizje raylib)

add_executable(TestKolizje
        test.cpp
        triangle.hpp
        vec2.hpp
        collision.hpp
        collision.cpp
)
target_link_libraries(TestKolizje raylib)
