cmake_minimum_required(VERSION 3.9)

project(CC3k+)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

file(GLOB_RECURSE SRC_FILES "src/*.cpp")
file(GLOB_RECURSE HEADER_FILES "src/*.hpp")

add_executable(
    ${PROJECT_NAME}
    ${SRC_FILES}
    ${HEADER_FILES}
)

target_link_libraries(
    ${PROJECT_NAME}
    sfml-graphics
    sfml-audio
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})