project(gamedevascii)

add_executable(gamedevascii main.c simpleStruct.h)

install(TARGETS gamedevascii RUNTIME DESTINATION bin)
