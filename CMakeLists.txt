cmake_minimum_required(VERSION 3.0)
project(libldac C)

set(CMAKE_C_STANDARD 99)


option(LDAC_SOFT_FLOAT "For devices without a FPU" OFF)
if(${LDAC_SOFT_FLOAT} STREQUAL ON)
    set(LDAC_SOFT_FLOAT_DEFINE "-D_32BIT_FIXED_POINT")
endif()

if("${INSTALL_LIBDIR}" STREQUAL "")
    set(INSTALL_LIBDIR ${CMAKE_INSTALL_PREFIX}/lib)
endif()

set(INSTALL_INCLUDEDIR ${CMAKE_INSTALL_PREFIX}/include/ldac)

set(LDACBT_LIB_VER_MAJOR   2)
set(LDACBT_LIB_VER_MINOR   0)
set(LDACBT_LIB_VER_BRANCH  2)
set(LDACBT_SOURCE_VER  2)

set(LIBLDAC_MAJOR_MINOR_BRANCH "${LDACBT_LIB_VER_MAJOR}.${LDACBT_LIB_VER_MINOR}.${LDACBT_LIB_VER_BRANCH}.${LDACBT_SOURCE_VER}")
set(SOVERSION ${LIBLDAC_MAJOR_MINOR_BRANCH})

add_subdirectory(pkgconfig)

include_directories(libldac/inc)
include_directories(libldac/abr/inc)

# libldacBT_enc
add_library(ldacBT_enc SHARED
        libldac/src/ldaclib.c
        libldac/src/ldacBT.c
        )

target_link_libraries(ldacBT_enc m)
target_compile_definitions(ldacBT_enc PUBLIC ${LDAC_SOFT_FLOAT_DEFINE})
set_target_properties(ldacBT_enc PROPERTIES
        VERSION ${LIBLDAC_MAJOR_MINOR_BRANCH}
        SOVERSION ${LDACBT_LIB_VER_MAJOR}
        )

# libldacBT_abr
add_library(ldacBT_abr SHARED
        libldac/abr/src/ldacBT_abr.c
        )

target_link_libraries(ldacBT_abr ldacBT_enc)
set_target_properties(ldacBT_abr PROPERTIES
        VERSION ${LIBLDAC_MAJOR_MINOR_BRANCH}
        SOVERSION ${LDACBT_LIB_VER_MAJOR}
        )

install(TARGETS
        ldacBT_enc
        ldacBT_abr
        LIBRARY DESTINATION
        ${INSTALL_LIBDIR}
        )

install(FILES
        libldac/inc/ldacBT.h
        libldac/abr/inc/ldacBT_abr.h
        DESTINATION
        ${INSTALL_INCLUDEDIR}
        )
