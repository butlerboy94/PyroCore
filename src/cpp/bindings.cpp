//This file is the bridge between C++ and Python
//pybind11 reads this and exposes our C++ functions so Python can call them like normal Python functions

#include <pybind11/pybind11.h>  //main pybind11 header
#include <pybind11/stl.h>       //teaches pybind11 how to convert std::vector to Python lists automatically
#include "stats.cpp"            //our statistical functions
#include "filter.cpp"           //our filtering function

//shortcut so we can write py:: instead of pybind11:: everywhere
namespace py = pybind11;

//this block defines the Python module named "pyrocore"
//when Python does "import pyrocore" it loads everything registered in here
PYBIND11_MODULE(pyrocore, m) {
    m.doc() = "PyroCore: A C++ library for data processing and analysis";

    // Bind the compute_mean function
    m.def("compute_mean", &compute_mean, "Compute the mean of a list of numbers");

    // Bind the compute_median function
    m.def("compute_median", &compute_median, "Compute the median of a list of numbers");

    // Bind the compute_std_dev function
    m.def("compute_std_dev", &compute_std_dev, "Compute the standard deviation of a list of numbers");

    // Bind the compute_min function
    m.def("compute_min", &compute_min, "Compute the minimum value in a list of numbers");

    // Bind the compute_max function
    m.def("compute_max", &compute_max, "Compute the maximum value in a list of numbers");

    // Bind the filter_rows function
    m.def("filter_rows", &filter_rows, "Filter rows from a table based on a threshold value in a specified column");
}
