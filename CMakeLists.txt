cmake_minimum_required(VERSION 3.10)
project(Hangman)

set(CMAKE_CXX_STANDARD 14)

# Определение исходных файлов
set(SOURCE_FILES
    main.cpp
    hangman.cpp
)

# Создание исполняемого файла
add_executable(hangman ${SOURCE_FILES})