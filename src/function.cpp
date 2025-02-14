#include "function.h"

#include <math.h>
#include <vector>


double Function::evaluate(double x) {
  return this->f->evaluate(x);
}
Function::Function(Function &f) {
  this->f = &f;
}

double Sum::evaluate(double x) {
  double sum = 0;
  for (auto f : fs) {
    sum += f->evaluate(x);
  }
  return sum;
}
Sum::Sum(std::vector<Function*> &fs) {
  this->fs = fs;
}

double Product::evaluate(double x) {
    double prod = 1;
    for (auto f : fs) {
      prod *= f->evaluate(x);
    }
    return prod;
}
Product::Product(std::vector<Function*> &fs) {
    this->fs = fs;
}

double Divide::evaluate(double x) {
  return this->f1->evaluate(x) / this->f2->evaluate(x);
}
Divide::Divide(Function numerator, Function denominator) {
  this->f1 = &numerator;
  this->f2 = &denominator;
}

double Subtract::evaluate(double x) {
  return f1.evaluate(x) - f2.evaluate(x);
}
Subtract::Subtract(Function minuend, Function subtrahend) {
  this->f1 = minuend;
  this->f2 = subtrahend;
}

double Constant::evaluate(double x) {
  return c;
}
Constant::Constant(double c) {
  this->c = c;
}
