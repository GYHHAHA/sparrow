#ifndef WOWO_FUNCTION1_H
#define WOWO_FUNCTION1_H

#include "pybind11/numpy.h"
#include <vector>

namespace py = pybind11;

class _LinearRegressor {
public:
    void fit(py::array_t<double>, py::array_t<double>, double);
    py::array predict(py::array_t<double>);
    std::tuple<double, double> get_para();
private:
    double weight;
    double bias;
};

#endif