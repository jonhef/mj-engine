#include "function.h"

#include <math.h>
#include <vector>

class Function {
  Function f;
public:
  double evaluate(double x) {
    return f.evaluate(x);
  }
  Function(Function f) {
    this->f = f;
  }
};

class Sum : public Function {
  std::vector<Function> fs;
public:
  double evaluate(double x) {
    double sum = 0;
    for (auto f : fs) {
      sum += f.evaluate(x);
    }
    return sum;
  }
  Sum(std::vector<Function> fs) {
    this->fs = fs;
  }
};

class Product : public Function {
  std::vector<Function> fs;
public:
  double evaluate(double x) {
    double prod = 1;
    for (auto f : fs) {
      prod *= f.evaluate(x);
    }
    return prod;
  }
  Product(std::vector<Function> fs) {
    this->fs = fs;
  }
};

class Divide : public Function {
  Function f1;
  Function f2;
public:
  double evaluate(double x) {
    return f1.evaluate(x) / f2.evaluate(x);
  }
  Divide(Function numerator, Function denominator) {
    this->f1 = numerator;
    this->f2 = denominator;
  }
};

class Subtract : public Function {
  Function f1;
  Function f2;
public:
  double evaluate(double x) {
    return f1.evaluate(x) - f2.evaluate(x);
  }
  Subtract(Function minuend, Function subtrahend) {
    this->f1 = minuend;
    this->f2 = subtrahend;
  }
};

class Constant : public Function {
  double c;
public:
  double evaluate(double x) {
    return c;
  }
  Constant(double c) {
    this->c = c;
  }
};
