#include <cmath>
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>

#include "example.h"


// See https://pybind11.readthedocs.io/en/stable/index.html for help about C++ wrapping
namespace py = pybind11;



int add(int i, int j)
{
    return i + j;
}

double norm(py::array_t<double, py::array::c_style | py::array::forcecast> array)
{
    py::buffer_info buf = array.request();
    double norm2 = 0.0;
    double *ptr = static_cast<double *>(buf.ptr);

    for (size_t idx = 0; idx < buf.shape[0]; idx++)
        norm2 += pow(ptr[idx], 2);

    return sqrt(norm2);
}

std::shared_ptr<Example> create_example()
{
    return std::shared_ptr<Example>(new Example());
}

PYBIND11_MODULE(hello, m)
{
    m.doc() = "Talismans example plugin"; // optional module docstring

    py::class_<Example, std::shared_ptr<Example>>(m, "Example", "Example C++ class docstring for Talismans")
        .def(py::init<>())
        .def("process", &Example::process, "Process one batch of data")
        .def("getResult", &Example::getResult, "Get the result of the processing");

    m.def("add", &add, "A function that adds two numbers");
    m.def("norm", &norm, "A function that computes the euclidian norm of a vector");
    m.def("create_example", &create_example, "A function that creates an instance of the Example C++ class");
}
