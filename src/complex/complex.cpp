#include "complex.h"
#include "../constant.h"
#include "../functions/function.h"
#include "../functions/basic_functions.h"
#include <math.h>

Complex::Complex(double re, double im) {
  this->re = re;
  this->im = im;
}
Complex::Complex(double re) {
  this->re = re;
  this->im = 0;
}
Complex::Complex() {
  this->re = 0;
  this->im = 0;
}
double Complex::getReal() const {
  return this->re;
}
double Complex::getImaginary() const {
  return this->im;
}
ComplexTrigonometric Complex::getTrigonometric() {
  return {pow(this->re*this->re + this->im*this->im, 0.5), this->re > 0 ? atan2(this->im, this->re) : this->re < 0 ? atan2(this->im, this->re) + pi : this->re == 0 && this->im == 0 ? 0 : this->im < 0 ? (double)3/(double)2*pi : pi/2};
}
Complex Complex::operator+(Complex &rf) {
  return Complex(this->re + rf.re, this->im + rf.im);
}
Complex Complex::operator-(Complex &rf) {
  return Complex(this->re - rf.re, this->im - rf.im);
}
Complex Complex::operator*(Complex &rf) {
  return Complex(this->re * rf.re - this->im * rf.im, this->re * rf.im + this->im * rf.re);
}
Complex Complex::operator/(Complex &rf) {
  return Complex((this->re * rf.re + this->im * rf.im) / (rf.re * rf.re + rf.im * rf.im),
                 (this->im * rf.re - this->re * rf.im) / (rf.re * rf.re + rf.im * rf.im));
} 

Complex Ln(Complex x) {
  auto tr = x.getTrigonometric();
  return Complex(log(tr.r), log(tr.phi));
}

Complex Complex::operator^(Complex &rf) {
  Complex a = this->Ln() * rf;
  return Complex::Exp(this->Ln() * rf);
}

Complex Complex::Ln(long long n) {
  auto tr = this->getTrigonometric();
  return Complex(log(tr.r), tr.phi + n*pi);
}

Complex Complex::Exp() {
  return Complex(exp(this->re)*cos(this->im), exp(this->re)*sin(this->im));
}

Complex Complex::Ln(Complex x, long long n) {
  auto tr = x.getTrigonometric();
  return Complex(log(tr.r), tr.phi);
}

Complex Complex::Exp(Complex x) {
  return Complex(exp(x.re)*cos(x.im), exp(x.re)*sin(x.im));
}
