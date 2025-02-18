#ifndef FUNCTION_H
#define FUNCTION_H

#include <vector>

class Function {
  Function *f;
public:
  virtual double evaluate(double x) = 0;
  Function* getFunction();
  Function(Function &f);
  Function();
};

class Sum : public Function {
  Function* f1;
  Function* f2;
public:
  double evaluate(double x);
  Sum(Function &f1, Function &f2);
  Sum();
  Function* getAddend();
  Function* getAddend2();
};

class Product : public Function {
  Function* f1;
  Function* f2;
public:
  double evaluate(double x);
  Function* getMultilpier();
  Function* getMultiplicand();
  Product(Function &f1, Function &f2);
  Product();
};

class Divide : public Function {
  Function* f1;
  Function* f2;
public:
  double evaluate(double x);
  Function* getNumerator();
  Function* getDenominator();
  Divide(Function &numerator, Function &denominator);
  Divide();
};

class Subtract : public Function {
  Function* f1;
  Function* f2;
public:
  double evaluate(double x);
  Function* getMinuend();
  Function* getSubtrahend();
  Subtract(Function &minuend, Function &subtrahend);
  Subtract();
};

class Constant : public Function {
  double c;
public:
  double evaluate(double x);
  Constant(double c);
  Constant();
};

#endif
