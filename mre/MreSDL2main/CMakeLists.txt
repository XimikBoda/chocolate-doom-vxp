add_library(MreSDL2main STATIC SDL2main.c)

target_link_libraries(MreSDL2main mreapi)

add_library(SDL2main ALIAS MreSDL2main)
add_library(SDL2::SDL2main ALIAS MreSDL2main)

