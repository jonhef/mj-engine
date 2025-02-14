#ifndef FUNCTION_H
#define FUNCTION_H

#include <vector>

class Function {
  Function *f;
public:
  double evaluate(double x);
  Function(Function &f);
  Function();
};

class Sum : public Function {
  std::vector<Function*> fs;
public:
  double evaluate(double x);
  Sum(std::vector<Function*> &fs);
};

class Product : public Function {
  std::vector<Function*> fs;
public:
  double evaluate(double x);
  Product(std::vector<Function*> &fs);
};

class Divide : public Function {
  Function* f1;
  Function* f2;
public:
  double evaluate(double x);
  Divide(Function numerator, Function denominator);
};

class Subtract : public Function {
  Function f1;
  Function f2;
public:
  double evaluate(double x);
  Subtract(Function minuend, Function subtrahend);
};

class Constant : public Function {
  double c;
public:
  double evaluate(double x);
  Constant(double c);
};

#endif
