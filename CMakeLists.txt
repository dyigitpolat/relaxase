# only for cmake --version >= 3.5.1
cmake_minimum_required(VERSION 3.5.1)

# project name
project(relaxase)

# creates the variable EXEC and sets it to hello
set(EXEC relaxase)

# set the C++14 standard
set(CMAKE_CXX_STANDARD 14)

# /include
include_directories(include)

# puts all .cpp files inside src to the SOURCES variable
file(GLOB SOURCES src/*.cpp)

# STATICALLY LINKED LIBRARIES
add_subdirectory(lib/tiny-AES-c)
add_subdirectory(lib/schifra_dir)

# compiles the files defined by SOURCES to generante the executable defined by EXEC
add_executable(${EXEC} ${SOURCES})

# Link libraries
target_link_libraries(${EXEC} tiny-aes)
target_link_libraries(${EXEC} schifra)