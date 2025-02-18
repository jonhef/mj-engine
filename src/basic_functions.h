#ifndef BASIC_FUNCTIONS_H
#define BASIC_FUNCTIONS_H
#include "function.h"

class Power : public Function {
  Function* f;
  double p;
public:
  double evaluate(double x);
  Power(Function& base, double p);
};

class Sine : public Function {
  Function* f;
public:
  double evaluate(double x);
  Sine(Function& f);
};

class Cosine : public Function {
  Function* f;
public:
  double evaluate(double x);
  Cosine(Function& f);
};

class Log : public Function {
  Function* f;
  double base;
public:
  double evaluate(double x);
  Log(Function& f, double base);
};

class Exp : public Function {
  Function* f;
  double base;
public:
  double evaluate(double x);
  Exp(Function& f, double base);
};

class Asine : public Function {
  Function* f;
public:
  double evaluate(double x);
  Asine(Function& f);
};

class Acosine : public Function {
  Function* f;
public:
  double evaluate(double x);
  Acosine(Function& f);
};

class Atan : public Function {
  Function* f;
public:
  double evaluate(double x);
  Atan(Function& f);
};

class Atan2 : public Function {
  Function* f1;
  Function* f2;
public:
  double evaluate(double x);
  Atan2(Function& f1, Function& f2);
};
#endif
