#include <cmath>
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

class Example
{
private:
    int a;

public:
    Example()
    {
        a = 0;
    }

    void process()
    {
        a += 1;
    }

    int getResult()
    {
        return a;
    }
};

// See https://pybind11.readthedocs.io/en/stable/index.html for help about C++ wrapping
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
    m.doc() = "pybind11 example plugin"; // optional module docstring

    py::class_<Example, std::shared_ptr<Example>>(m, "Example")
        .def(py::init<>())
        .def("process", &Example::process)
        .def("getResult", &Example::getResult);

    m.def("add", &add, "A function that adds two numbers");
    m.def("norm", &norm, "A function that computes the euclidian norm of a vector");
    m.def("create_example", &create_example);
}
