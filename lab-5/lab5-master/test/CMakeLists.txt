add_executable(main main.cpp)
target_link_libraries(main list_vector)

add_test(NAME main_func COMMAND main)