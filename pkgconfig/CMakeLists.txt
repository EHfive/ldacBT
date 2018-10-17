set(PREFIX ${CMAKE_INSTALL_PREFIX})
set(LIBDIR ${INSTALL_LIBDIR})
set(INCLUDEDIR ${CMAKE_INSTALL_PREFIX}/include)
set(VERSION ${LIBLDAC_MAJOR_MINOR_BRANCH})

set(PC_VAL_PREFIX "\${prefix}")
set(PC_VAL_LIBDIR "\${libdir}")
set(PC_VAL_INCLUDEDIR "\${includedir}")

message(${CMAKE_CURRENT_BINARY_DIR})

configure_file(
        ldacBT-enc.pc.in
        ldacBT-enc.pc
)
configure_file(
        ldacBT-abr.pc.in
        ldacBT-abr.pc
)

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/ldacBT-enc.pc
        ${CMAKE_CURRENT_BINARY_DIR}/ldacBT-abr.pc
        DESTINATION
        ${INSTALL_LIBDIR}/pkgconfig)