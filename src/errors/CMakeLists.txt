set(TARGET_NAME errors)

set(TARGET_SOURCES
    "errors.c"
)

add_library(${TARGET_NAME} STATIC
    ${TARGET_SOURCES}
)

target_include_directories(${TARGET_NAME}
    PUBLIC "include" ${INCLUDE_DIRECTORIES_TO_PROPAGATE}
)

set_target_c_compiler_flags(${TARGET_NAME})
