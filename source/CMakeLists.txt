cmake_minimum_required(VERSION 3.27)

project(server C)

# Making sure to use GLIBC
if (NOT CMAKE_COMPILER_IS_GNUCC)
    message(FATAL_ERROR "Glibc not found. Aborting.")
endif ()

# Set build type to Release
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

# Disable stack protections
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-stack-protector -O3 -Wall -Wextra")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -z noexecstack")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_FORTIFY_SOURCE=0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_FORTIFY_SOURCE=0")
# Disable compiler optimizations
set(CMAKE_C_FLAGS_RELEASE "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O0")

# Disable debugging symbols
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s")

# Setting CMAKE_C_STANDARD
set(CMAKE_C_STANDARD 11)

add_executable(server code/server.c)

# Strip the executable
if (NOT CMAKE_STRIP)
    set(CMAKE_STRIP strip)
endif ()

add_custom_command(TARGET server POST_BUILD
        COMMAND ${CMAKE_STRIP} $<TARGET_FILE:server>
        COMMENT "Stripping executable"
        VERBATIM)

