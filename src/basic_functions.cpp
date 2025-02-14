#include "basic_functions.h"
#include <math.h>

double Power::evaluate(double x) {
  return pow(f.evaluate(x), this->p); 
}
Power::Power(double p) {
  this->p = p;
}

double Sine::evaluate(double x) {
  return sin(this->f.evaluate(x));
}
Sine::Sine(Function f) {
  this->f = f;
}

double Cosine::evaluate(double x) {
  return cos(this->f.evaluate(x));
}
Cosine::Cosine(Function f) {
  this->f = f;
}

double Log::evaluate(double x) {
  return log(this->f.evaluate(x))/log(this->base);
}
Log::Log(Function f, double base) {
  this->f = f;
  this->base = base;
}

double Exp::evaluate(double x) {
  return pow(this->base, this->f.evaluate(x));
}
Exp::Exp(Function f, double base) {
  this->f = f;
  this->base = base;
}

double Asine::evaluate(double x) {
  return asin(this->f.evaluate(x));
}
Asine::Asine(Function f) {
  this->f = f;
}

double Acosine::evaluate(double x) {
  return acos(this->f.evaluate(x));
}
Acosine::Acosine(Function f) {
  this->f = f;
}

double Atan::evaluate(double x) {
  return atan(this->f.evaluate(x));
}
Atan::Atan(Function f) {
  this->f = f;
}

double Atan2::evaluate(double x) {
  return atan2(this->f1.evaluate(x), this->f2.evaluate(x));
}
Atan2::Atan2(Function f1, Function f2) {
  this->f1 = f1;
  this->f2 = f2;
}
