add_executable(main main.cpp)
target_link_libraries(main matrix)

add_test(NAME main_matrix COMMAND main)