#ifndef DERIVATING_H
#define DERIVATING_H

#include "../function.h"
#include "../basic_functions.h"

class Derivative : Function {
  Function f;
  void* df;
public:
  Derivative();
  Derivative(Function f);
  Derivative(Sum s);
  Derivative(Product p);
  Derivative(Power p);
  Derivative(Sine s);
  Derivative(Cosine c);
  Derivative(Log l);
  Derivative(Exp e);
  Derivative(Asine a);
  Derivative(Acosine ac);
  Derivative(Atan a);
  Derivative(Atan2 a);
  Derivative(Divide d);
  Derivative(Subtract s);
  double evaluate(double x);
};

#endif
