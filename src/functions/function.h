#ifndef FUNCTION_H
#define FUNCTION_H

#include <vector>

template<typename T>
class Function {
  Function *f;
public:
  virtual T evaluate(T x) = 0;
  Function* getFunction();
  Function(Function &f);
  Function();
  Function* operator*(Function &rf);
  Function* operator+(Function &rf);
  Function* operator-(Function &rf);
  Function* operator/(Function &rf);
  Function* operator-();
  T operator()(T x);
};

template<typename T>
class Sum : public Function<T> {
  Function<T>* f1;
  Function<T>* f2;
public:
  T evaluate(T x);
  Sum(Function<T> &f1, Function<T> &f2);
  Sum();
  Function<T>* getAddend();
  Function<T>* getAddend2();
};

template<typename T>
class Product : public Function<T> {
  Function<T>* f1;
  Function<T>* f2;
public:
  T evaluate(T x);
  Function<T>* getMultilpier();
  Function<T>* getMultiplicand();
  Product(Function<T> &f1, Function<T> &f2);
  Product();
};

template<typename T>
class Divide : public Function<T> {
  Function<T>* f1;
  Function<T>* f2;
public:
  T evaluate(T x);
  Function<T>* getNumerator();
  Function<T>* getDenominator();
  Divide(Function<T> &numerator, Function<T> &denominator);
  Divide();
};

template<typename T>
class Subtract : public Function<T> {
  Function<T>* f1;
  Function<T>* f2;
public:
  T evaluate(T x);
  Function<T>* getMinuend();
  Function<T>* getSubtrahend();
  Subtract(Function<T> &minuend, Function<T> &subtrahend);
  Subtract();
};

template<typename T>
class Constant : public Function<T> {
  T c;
public:
  T evaluate(T x);
  Constant(T c);
  Constant();
};

#endif
