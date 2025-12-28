FILE(GLOB_RECURSE headers "include/*.h")
FILE(GLOB_RECURSE sources "src/*.c")

add_library(MreSDL2_net STATIC ${sources} ${headers})

target_include_directories(MreSDL2_net PUBLIC "include/")

target_link_libraries(MreSDL2_net SDL2 mreapi libco)

add_library(SDL2_net ALIAS MreSDL2_net)
add_library(SDL2_net::SDL2_net ALIAS MreSDL2_net)