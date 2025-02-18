#include "function.h"

#include <math.h>
#include <vector>

// Constructors for function(abstract) class
Function::Function(Function &f) {
  this->f = &f;
}
Function::Function() {
  this->f = nullptr;
}
Function* Function::getFunction() {
  return this->f;
}
Function* Function::operator*(Function &rf) {
  return new Product(*this, rf);
}
Function* Function::operator+(Function &rf) {
  return new Sum(*this, rf);
}
Function* Function::operator-(Function &rf) {
  return new Subtract(*this, rf);
}
Function* Function::operator/(Function &rf) {
  return new Divide(*this, rf);
}
Function* Function::operator-() {
  return new Product(*this, new Constant(-1));
}
double Function::operator()(double x) {
  return this->evaluate(x);
}

double Sum::evaluate(double x) {
  double sum = 0;
  sum += this->f1->evaluate(x);
  sum += this->f2->evaluate(x);
  return sum;
}
Sum::Sum(Function& f1, Function& f2) {
  this->f1 = &f1;
  this->f2 = &f2;
}
Function* Sum::getAddend() {
  return this->f1;
}
Function* Sum::getAddend2() {
  return this->f2;
}
Sum::Sum() {
  this->f1 = nullptr;
  this->f2 = nullptr;
}

Function* Product::getMultilpier() {
  return this->f1;
}
Function* Product::getMultiplicand() {
  return this->f2;
}
double Product::evaluate(double x) {
  return this->f1->evaluate(x) * this->f2->evaluate(x);
}
Product::Product(Function& f1, Function& f2) {
  this->f1 = &f1;
  this->f2 = &f2;
}

double Divide::evaluate(double x) {
  return this->f1->evaluate(x) / this->f2->evaluate(x);
}
Divide::Divide(Function& numerator, Function& denominator) {
  this->f1 = &numerator;
  this->f2 = &denominator;
}
Function* Divide::getNumerator() {
  return this->f1;
}
Function* Divide::getDenominator() {
  return this->f2;
}

double Subtract::evaluate(double x) {
  return f1->evaluate(x) - f2->evaluate(x);
}
Subtract::Subtract(Function& minuend, Function& subtrahend) {
  this->f1 = &minuend;
  this->f2 = &subtrahend;
}
Function* Subtract::getMinuend() {
  return this->f1;
}
Function* Subtract::getSubtrahend() {
  return this->f2;
}

double Constant::evaluate(double x) {
  return c;
}
Constant::Constant(double c) {
  this->c = c;
}
