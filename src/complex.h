#ifndef COMPLEX_H
#define COMPLEX_H

#include <math.h>
#include <vector>
#include "function.h"

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
  ~Complex();
};
#endif
