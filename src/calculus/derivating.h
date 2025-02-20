#ifndef DERIVATING_H
#define DERIVATING_H

#include "../constant.h"
#include "../functions/function.h"
#include "../functions/basic_functions.h"

template <typename T>
class Derivative : Function<T> {
  Function<T>* f;
  Function<T>* df;
public:
  Derivative();
  Derivative(Function<T> &f);
  T evaluate(T x);
};

#endif
