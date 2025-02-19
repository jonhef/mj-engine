#include "complex.h"
#include "constant.h"
#include "function.h"
#include "basic_functions.h"

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
  auto tr = this->getTrigonometric(); 
  return Complex(pow(this->re, rf.re) * cos(rf.im * this->im), pow(this->re, rf.re) * sin(rf.im * this->im));
}
