#include "basic_functions.h"
#include <math.h>

template <typename T>
T Power<T>::evaluate(T x) {
  return this->f->evaluate(x)^this->p;
}
template <typename T>
Power<T>::Power(Function<T>& f, T p) {
  this->f = &f;
  this->p = p;
}
template <typename T>
T Power<T>::getPower() const {
  return this->p;
}

template <typename T>
T Sine<T>::evaluate(T x) {
  return sin(this->f->evaluate(x));
}
template <typename T>
Sine<T>::Sine(Function<T>& f) {
  this->f = &f;
}

template <typename T>
T Cosine<T>::evaluate(T x) {
  return cos(this->f->evaluate(x));
}
template <typename T>
Cosine<T>::Cosine(Function<T> &f) {
  this->f = &f;
}

template <typename T>
T Log<T>::evaluate(T x) {
  return log(this->f->evaluate(x))/log(this->base);
}
template <typename T>
Log<T>::Log(Function<T> &f, T base) {
  this->f = &f;
  this->base = base;
}
template <typename T>
T Log<T>::getBase() const {
  return this->base;
}

template <typename T>
T Exp<T>::evaluate(T x) {
  return exp(this->f->evaluate(x))/exp(this->base);
}
template <typename T>
Exp<T>::Exp(Function<T> &f, T base) {
  this->f = &f;
  this->base = base;
}
template <typename T>
T Exp<T>::getBase() const {
  return this->base;
}

template <typename T>
T Asine<T>::evaluate(T x) {
  return asin(this->f->evaluate(x));
}
template <typename T>
Asine<T>::Asine(Function<T> &f) {
  this->f = &f;
}

template <typename T>
T Acosine<T>::evaluate(T x) {
  return acos(this->f->evaluate(x));
}
template <typename T>
Acosine<T>::Acosine(Function<T> &f) {
  this->f = &f;
}

template <typename T>
T Atan<T>::evaluate(T x) {
  return atan(this->f->evaluate(x));
}
template <typename T>
Atan<T>::Atan(Function<T> &f) {
  this->f = &f;
}

template <typename T>
T Atan2<T>::evaluate(T x) {
  return atan2(this->f1->evaluate(x), this->f2->evaluate(x));
}
template <typename T>
Atan2<T>::Atan2(Function<T> &f1, Function<T> &f2) {
  this->f1 = &f1;
  this->f2 = &f2;
}
template <typename T>
Function<T>* Atan2<T>::getF1() {
  return this->f1;
}
template <typename T>
Function<T>* Atan2<T>::getF2() {
  return this->f2;
}
