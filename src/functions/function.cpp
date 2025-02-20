#include "function.h"

#include <math.h>
#include <vector>

// Constructors for function(abstract) class
template <typename T>
Function<T>::Function(Function<T> &f) {
  this->f = &f;
}
template <typename T>
Function<T>::Function() {
  this->f = nullptr;
}
template <typename T>
Function<T>* Function<T>::getFunction() {
  return this->f;
}
template <typename T>
Function<T>* Function<T>::operator*(Function<T> &rf) {
  return new Product<T>(*this, rf);
}
template <typename T>
Function<T>* Function<T>::operator+(Function<T> &rf) {
  return new Sum<T>(*this, rf);
}
template <typename T>
Function<T>* Function<T>::operator-(Function<T> &rf) {
  return new Subtract<T>(*this, rf);
}
template <typename T>
Function<T>* Function<T>::operator/(Function<T> &rf) {
  return new Divide<T>(*this, rf);
}
template <typename T>
Function<T>* Function<T>::operator-() {
  return new Product<T>(*this, new Constant<T>(-1));
}
template <typename T>
T Function<T>::operator()(T x) {
  return this->evaluate(x);
}

template <typename T>
T Sum<T>::evaluate(T x) {
  T sum = 0;
  sum += this->f1->evaluate(x);
  sum += this->f2->evaluate(x);
  return sum;
}
template <typename T>
Sum<T>::Sum(Function<T>& f1, Function<T>& f2) {
  this->f1 = &f1;
  this->f2 = &f2;
}
template <typename T>
Function<T>* Sum<T>::getAddend() {
  return this->f1;
}
template <typename T>
Function<T>* Sum<T>::getAddend2() {
  return this->f2;
}
template <typename T>
Sum<T>::Sum() {
  this->f1 = nullptr;
  this->f2 = nullptr;
}

template <typename T>
Function<T>* Product<T>::getMultilpier() {
  return this->f1;
}
template <typename T>
Function<T>* Product<T>::getMultiplicand() {
  return this->f2;
}
template <typename T>
T Product<T>::evaluate(T x) {
  return this->f1->evaluate(x) * this->f2->evaluate(x);
}
template <typename T>
Product<T>::Product(Function<T>& f1, Function<T>& f2) {
  this->f1 = &f1;
  this->f2 = &f2;
}

template <typename T>
T Divide<T>::evaluate(T x) {
  return this->f1->evaluate(x) / this->f2->evaluate(x);
}
template <typename T>
Divide<T>::Divide(Function<T>& numerator, Function<T>& denominator) {
  this->f1 = &numerator;
  this->f2 = &denominator;
}
template <typename T>
Function<T>* Divide<T>::getNumerator() {
  return this->f1;
}
template <typename T>
Function<T>* Divide<T>::getDenominator() {
  return this->f2;
}

template <typename T>
T Subtract<T>::evaluate(T x) {
  return f1->evaluate(x) - f2->evaluate(x);
}
template <typename T>
Subtract<T>::Subtract(Function<T>& minuend, Function<T>& subtrahend) {
  this->f1 = &minuend;
  this->f2 = &subtrahend;
}
template <typename T>
Function<T>* Subtract<T>::getMinuend() {
  return this->f1;
}
template <typename T>
Function<T>* Subtract<T>::getSubtrahend() {
  return this->f2;
}

template <typename T>
T Constant<T>::evaluate(T x) {
  return c;
}
template <typename T>
Constant<T>::Constant(T c) {
  this->c = c;
}
