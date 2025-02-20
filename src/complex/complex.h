#ifndef COMPLEX_H
#define COMPLEX_H

#include <math.h>
#include <vector>
#include "../functions/function.h"

struct ComplexTrigonometric {
  double r;
  double phi;
};

typedef struct ComplexTrigonometric ComplexTrigonometric;

class Complex {
  double re;
  double im;
public:
  Complex(double re, double im);
  Complex(double re);
  Complex();
  double getReal() const;
  double getImaginary() const;
  ComplexTrigonometric getTrigonometric();
  Complex operator+(Complex &rf);
  Complex operator-(Complex &rf);
  Complex operator*(Complex &rf);
  Complex operator/(Complex &rf);
  Complex operator^(Complex &rf);
  Complex operator+=(Complex &rf);
  Complex operator-=(Complex &rf);
  Complex operator*=(Complex &rf);
  Complex operator/=(Complex &rf);
  Complex operator^=(Complex &rf);
  Complex operator-();
  Complex Ln(long long n = 0);
  Complex Exp();
  static Complex Ln(Complex x, long long n = 0);
  static Complex Exp(Complex x);
  ~Complex();
};
#endif
