cmake_minimum_required(VERSION 3.16)

project(MyProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(wxWidgets REQUIRED COMPONENTS core base)

add_executable(MyExecutable
    src/main.cpp
    src/BmpImage/BmpImage.cpp
    src/Encryptor/Encryptor.cpp
)

target_include_directories(MyExecutable PRIVATE
    src
)

target_link_libraries(MyExecutable
    wx::core
    wx::base
)
