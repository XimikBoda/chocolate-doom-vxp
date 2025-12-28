set(PROJECT_NAME "run_in_MoDis")

add_custom_command( # repack triger 
   OUTPUT null.c
   COMMAND ${CMAKE_COMMAND} -E touch null.c
   DEPENDS chocolate-setup_vxp chocolate-doom_vxp
)

add_library(${PROJECT_NAME} STATIC "null.c")

set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".bat")
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")

set(MODIS_PATH "${MRE_SDK}/models/Model01_QVGA_MRE3.0/")

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:chocolate-setup_vxp>" "${MODIS_PATH}/WIN32FS/DRIVE_E/mre/chocolate-setup.vxp"
   COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:chocolate-doom_vxp>" "${MODIS_PATH}/WIN32FS/DRIVE_E/mre/chocolate-doom.vxp"
   COMMAND echo "${MODIS_PATH}/MoDIS/Release/MoDIS.exe" > "$<TARGET_FILE:${PROJECT_NAME}>" 
)