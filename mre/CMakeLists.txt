set(CMAKE_SYSTEM_NAME MRE_MODIS)

set(MRE_SDK "$ENV{MRE_SDK}" CACHE STRING "MRE SDK dir")
set(TinyMRESDK "$ENV{TinyMRESDK}" CACHE STRING "TinyMRESDK dir")

add_subdirectory(mreapi)
add_subdirectory(MreSDL2)
add_subdirectory(MreSDL2main)
