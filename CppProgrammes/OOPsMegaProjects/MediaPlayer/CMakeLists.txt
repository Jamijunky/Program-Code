cmake_minimum_required(VERSION 3.14)

project(MediaPlayer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)  # This enables automatic generation of ui_MainWindow.h

# Include directories
include_directories(include)

# Source files
set(SOURCES
    src/main.cpp
    src/MainWindow.cpp
    src/Player.cpp
)

# Header files
set(HEADERS
    include/MainWindow.h
    include/Player.h
)

# UI file
set(UIS
    ui/MainWindow.ui
)

# Find Qt5
find_package(Qt5 REQUIRED COMPONENTS Core Widgets Multimedia)

# Executable
add_executable(MediaPlayer ${SOURCES} ${HEADERS} ${UIS})

# Link Qt5 libraries
target_link_libraries(MediaPlayer Qt5::Core Qt5::Widgets Qt5::Multimedia)
