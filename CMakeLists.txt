cmake_minimum_required(VERSION 3.15)
project(GradeCalculator VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Исходные файлы
set(SOURCES
    src/main.cpp
    src/student.cpp
    src/gradebook.cpp
    src/utils.cpp
    src/filemanager.cpp
)

# Заголовочные файлы
set(HEADERS
    src/student.h
    src/gradebook.h
    src/utils.h
    src/filemanager.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Кодировка для MSVC
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /utf-8)
endif()
