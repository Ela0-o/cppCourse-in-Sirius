cmake_minimum_required(VERSION 3.2) # минимальная версия симэйка
project (Simple CXX) # просто название проекта

option(BUILD_TESTING "building tests" On)

add_subdirectory(src)

if (BUILD_TESTING)
    enable_testing()
    add_subdirectory(test)
endif()