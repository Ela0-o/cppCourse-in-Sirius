add_library(vector STATIC vector.cpp) # статическая библиотека 
target_include_directories(vector PUBLIC "${PROJECT_SOURCE_DIR}/include")
