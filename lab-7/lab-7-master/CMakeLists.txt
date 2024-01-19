cmake_minimum_required(VERSION 3.2) # минимальная версия симэйка
project (Matrix CXX) # просто название проекта

option(BUILD_TESTING "building tests" On)

# добавление директориев, в которых тоже есть смэйки
add_subdirectory(src)

if (BUILD_TESTING)
    enable_testing()
    add_subdirectory(test)
endif()