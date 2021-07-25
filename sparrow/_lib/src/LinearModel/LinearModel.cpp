#include "pybind11/pybind11.h"
#include "LinearRegressor.h"

namespace py = pybind11;

PYBIND11_MODULE(LinearModel, m) {
    py::class_<_LinearRegressor>(m, "_LinearRegressor")
            .def(py::init<>())
            .def("fit", &_LinearRegressor::fit)
            .def("predict", &_LinearRegressor::predict)
            .def("get_para", &_LinearRegressor::get_para);
}