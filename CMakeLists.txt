
## gretl examples from https://sourceforge.net/p/gretl/git/ci/master/tree/

cmake_minimum_required(VERSION 3.17)
project(GretlAPI)

set(CMAKE_CXX_STANDARD 14)

find_package(PkgConfig REQUIRED QUIET)
pkg_check_modules(LIBGRETL REQUIRED gretl)


message(STATUS "LIBGRETL_INCLUDE_DIRS = " ${LIBGRETL_INCLUDE_DIRS})
message(STATUS "LIBGRETL_LINK_LIBRARIES = " ${LIBGRETL_LINK_LIBRARIES})
message(STATUS "LIBGRETL_PREFIX = " ${LIBGRETL_PREFIX})

add_executable(arma_example arma_example.c)
target_include_directories(arma_example PUBLIC ${LIBGRETL_INCLUDE_DIRS})
target_link_libraries(arma_example ${LIBGRETL_LINK_LIBRARIES})

add_executable(nls_example nls_example.c)
target_include_directories(nls_example PUBLIC ${LIBGRETL_INCLUDE_DIRS})
target_link_libraries(nls_example ${LIBGRETL_LINK_LIBRARIES})

add_executable(simple_client simple_client.c)
target_include_directories(simple_client PUBLIC ${LIBGRETL_INCLUDE_DIRS})
target_link_libraries(simple_client ${LIBGRETL_LINK_LIBRARIES})

## garch example I got to work with gretl API
add_executable(dj_garch dj_garch.c dj_garch.c)
target_include_directories(dj_garch PUBLIC ${LIBGRETL_INCLUDE_DIRS})
target_link_libraries(dj_garch ${LIBGRETL_LINK_LIBRARIES})
