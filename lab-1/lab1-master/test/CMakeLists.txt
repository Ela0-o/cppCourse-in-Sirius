add_executable(main main.cpp)
target_link_libraries(main prime)

add_test(NAME main_prime COMMAND main)