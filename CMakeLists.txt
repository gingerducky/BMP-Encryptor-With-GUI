cmake_minimum_required(VERSION 3.16)

project(MyProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(bmp_encryptor
    src/main.cpp
    src/BmpImage/BmpImage.cpp
    src/Encryptor/Encryptor.cpp
)

target_include_directories(bmp_encryptor PRIVATE
    src
)
