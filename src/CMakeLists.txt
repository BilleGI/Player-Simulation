cmake_minimum_required(VERSION 3.5)

add_executable(untitled1 main.cpp ${MY_INCLUDE_DIR}/player.h player.cpp ${MY_INCLUDE_DIR}/track.h track.cpp)
target_include_directories(untitled1 PUBLIC ${MY_INCLUDE_DIR})
