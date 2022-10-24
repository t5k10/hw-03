cmake_minimum_required(VERSION 3.16.3)

project(hw-03)

set(SOURCES 
    guess_the_number.cpp
    read_write_to_file.cpp
    play_game.cpp
)

set(HEADERS
    read_write_to_file.h
    play_game.h
)

add_executable(guess_the_number ${SOURCES} ${HEADERS})

set_target_properties(
    guess_the_number PROPERTIES
    CXX_STANDARD 17 
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(
   guess_the_number
   PRIVATE
   ${CMAKE_CURRENT_BINARY_DIR}
   )
