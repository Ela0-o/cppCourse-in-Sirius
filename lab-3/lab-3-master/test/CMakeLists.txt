add_executable(main main.cpp)
target_link_libraries(main vector)

add_test(NAME main_vector COMMAND main)