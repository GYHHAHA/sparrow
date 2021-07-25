#include "LinearRegressor.h"
#include <cmath>
#include <pybind11/stl.h>

void _LinearRegressor::fit(py::array_t<double> X, py::array_t<double> Y, double learning_rate) {
    auto x = X.unchecked<1>();
    auto y = Y.unchecked<1>();
    double w_last, b_last, w_next, b_next, w_negative, b_negative, temp;
    w_last = 1e15;
    w_next = 0.0;
    b_last = 1e15;
    b_next = 0.0;
    while (abs(w_last-w_next) + (abs(b_last-b_next)) > 1e-15){
        w_last = w_next;
        b_last = b_next;
        w_negative = 0.0;
        b_negative = 0.0;
        for (int i=0; i<x.shape(0); i++){
            temp = y[i] - w_next*x[i] - b_next;
            w_negative += temp * x[i];
            b_negative += temp;
        }
        w_negative /= double(x.shape(0));
        b_negative /= double(x.shape(0));
        w_next += learning_rate * w_negative;
        w_next += learning_rate * w_negative;
        b_next += learning_rate * b_negative;
    }
    _LinearRegressor::weight = w_next;
    _LinearRegressor::bias = b_next;
}

std::tuple<double, double> _LinearRegressor::get_para() {
    return std::make_tuple(_LinearRegressor::weight, _LinearRegressor::bias);
}

py::array _LinearRegressor::predict(py::array_t<double> x) {
    std::vector<double> y(x.shape(0));
    auto x_ = x.unchecked<1>();
    for (int i=0; i<x.shape(0); i++){
        y[i] = _LinearRegressor::weight * x_[i] + _LinearRegressor::bias;
    }
    return py::array(y.size(), y.data());
}