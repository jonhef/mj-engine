#ifndef BASIC_FUNCTIONS_H
#define BASIC_FUNCTIONS_H
#include "function.h"

template<typename T>
class Power : public Function<T> {
  Function<T>* f;
  T p;
public:
  T evaluate(T x);
  Power(Function<T>& base, T p);
  T getPower() const;
};
template <typename T>
class Sine : public Function<T> {
  Function<T>* f;
public:
  T evaluate(T x);
  Sine(Function<T>& f);
};

template <typename T>
class Cosine : public Function<T> {
  Function<T>* f;
public:
  T evaluate(T x);
  Cosine(Function<T>& f);
};

template <typename T>
class Log : public Function<T> {
  Function<T>* f;
  T base;
public:
  T evaluate(T x);
  Log(Function<T>& f, T base);
  T getBase() const;
};

template <typename T>
class Exp : public Function<T> {
  Function<T>* f;
  T base;
public:
  T evaluate(T x);
  Exp(Function<T>& f, T base);
  T getBase() const;
};

template <typename T>
class Asine : public Function<T> {
  Function<T>* f;
public:
  T evaluate(T x);
  Asine(Function<T>& f);
};

template <typename T>
class Acosine : public Function<T> {
  Function<T>* f;
public:
  T evaluate(T x);
  Acosine(Function<T>& f);
};

template <typename T>
class Atan : public Function<T> {
  Function<T>* f;
public:
  T evaluate(T x);
  Atan(Function<T>& f);
};

template <typename T>
class Atan2 : public Function<T> {
  Function<T>* f1;
  Function<T>* f2;
public:
  T evaluate(T x);
  Atan2(Function<T>& f1, Function<T>& f2);
  Function<T>* getF1();
  Function<T>* getF2();
};
#endif
