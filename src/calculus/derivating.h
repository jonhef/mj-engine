#ifndef DERIVATING_H
#define DERIVATING_H

#include "../constant.h"
#include "../function.h"
#include "../basic_functions.h"

class Derivative : Function {
  Function* f;
  Function* df;
public:
  Derivative();
  Derivative(Function &f);
  double evaluate(double x);
};

#endif
