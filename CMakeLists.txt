project(gamedevascii)

add_executable(gamedevascii main.c display.h structs.h globalVars.h)

set(CMAKE_C_FLAGS "-std=c99")

TARGET_LINK_LIBRARIES(gamedevascii -lncurses -lpthread)

install(TARGETS gamedevascii RUNTIME DESTINATION bin)
