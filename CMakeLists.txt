# This file tells CMake how to build the PyroCore C++ module
# Run "cmake -S . -B build" to configure and "cmake --build build --config Release" to compile

# minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.15)

# name of the project
project(PyroCore)

# use C++17 which gives us modern features like auto and range-based for loops
set(CMAKE_CXX_STANDARD 17)

# find the Python installation on this machine so CMake knows where to link against it
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)

# tell CMake where pybind11 is installed so it knows where to look before searching
set(pybind11_DIR "C:/Users/kaleb/AppData/Local/Programs/Python/Python313/Lib/site-packages/pybind11/share/cmake/pybind11")

# find the pybind11 package using the path we just set above
find_package(pybind11 REQUIRED)

# compile bindings.cpp into a Python-importable module called "pyrocore"
# this produces pyrocore.pyd in the build/Release folder
pybind11_add_module(pyrocore src/cpp/bindings.cpp)
