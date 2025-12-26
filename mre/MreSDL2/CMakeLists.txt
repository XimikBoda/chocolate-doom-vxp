FILE(GLOB_RECURSE headers "include/*.h")
FILE(GLOB_RECURSE sources "src/*.c")

add_library(MreSDL2 STATIC ${sources} ${headers})

target_include_directories(MreSDL2 PUBLIC "include/")

target_link_libraries(MreSDL2 mreapi)

add_library(SDL2 ALIAS MreSDL2)
add_library(SDL2::SDL2 ALIAS MreSDL2)