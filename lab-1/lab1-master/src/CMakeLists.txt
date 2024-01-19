add_library(prime STATIC prime.cpp) # статическая библиотека 
target_include_directories(prime PUBLIC "${PROJECT_SOURCE_DIR}/include")
