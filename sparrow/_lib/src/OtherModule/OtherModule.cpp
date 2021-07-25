#include "pybind11/pybind11.h"
#include "function1.h"
#include "function2.h"

namespace py = pybind11;

PYBIND11_MODULE(OtherModule, m) {
    m.def("add", my_add);
    m.def("minus", my_minus);
}