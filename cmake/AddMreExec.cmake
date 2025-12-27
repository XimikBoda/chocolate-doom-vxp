set(COMMON_DIR ${PROJECT_SOURCE_DIR}/mre/common)

function(add_mre_exec TARGET_NAME)
    set(TARGET_NAME ${ARGV0})
    list(REMOVE_AT ARGV 0) 
    set(SRCS ${ARGV})

    if(${CMAKE_SYSTEM_NAME} STREQUAL MRE_NATIVE) # For Phone
        add_executable(${TARGET_NAME} ${SRCS} "${COMMON_DIR}/armmain.c" "${COMMON_DIR}/syscalls.c")

        target_link_options(${TARGET_NAME} PRIVATE 
            "-T${COMMON_DIR}/scat.ld"
            "-Wl,--no-warn-rwx-segment"
        )

        set_target_properties(${TARGET_NAME} PROPERTIES SUFFIX ".axf")
    elseif(${CMAKE_SYSTEM_NAME} STREQUAL MRE_MODIS) # For MoDis 
        if(MSVC)
            add_library(${TARGET_NAME} SHARED ${SRCS} "${COMMON_DIR}/dll.def")
        else()
            add_library(${TARGET_NAME} SHARED ${SRCS} "${COMMON_DIR}/syscalls.c" "${COMMON_DIR}/malloc.c" "${COMMON_DIR}/winmain.c")
            target_link_libraries(${TARGET_NAME} "${COMMON_DIR}/dll.def")
            set_target_properties(${TARGET_NAME} PROPERTIES
                    SUFFIX ".dll"
                    PREFIX ""
            )
        endif()
    else()
        message(FATAL_ERROR "Unsupported target system: ${CMAKE_SYSTEM_NAME}")
    endif()

    #target_link_libraries(${TARGET_NAME} mreapi)
endfunction()