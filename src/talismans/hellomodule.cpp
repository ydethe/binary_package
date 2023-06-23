#include <pybind11/pybind11.h>


// See https://pybind11.readthedocs.io/en/stable/index.html for help about C++ wrapping
int add(int i, int j) {
    return i + j;
}

PYBIND11_MODULE(hello, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function that adds two numbers");
}
