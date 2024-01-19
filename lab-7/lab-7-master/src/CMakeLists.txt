add_library(matrix STATIC matrix.cpp stream.cpp) # статическая библиотека 
target_include_directories(matrix PUBLIC "${PROJECT_SOURCE_DIR}/include")
