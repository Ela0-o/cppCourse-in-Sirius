add_library(list_vector STATIC vector.cpp list.cpp) # статическая библиотека 
target_include_directories(list_vector PUBLIC "${PROJECT_SOURCE_DIR}/include")
