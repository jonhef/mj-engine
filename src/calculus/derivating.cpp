#include "derivating.h"

Derivative::Derivative() {
  this->f = new Constant(0);
}

Derivative::Derivative(Function &f) {
  this->f = &f;
  if (typeid(&f) == typeid(Sum)) {
    this->df = new Sum(new Derivative(f->getAddend()), new Derivative(f->getAddend2()));
  }
  else if (typeid(&f) == typeid(Product)) {
    this->df = new Sum(new Product(new Derivative(f->getMultilpier()), f->getMultiplicand()),
                       new Product(f->getMultilpier(), new Derivative(f->getMultiplicand())));
  }
  else if (typeid(&f) == typeid(Divide)) {
    this->df = new Divide(new Subtract(new Product(new Derivative(f->getNumerator()), f->getDenominator()), new Product(f->getNumerator(), new Derivative(f->getDenominator()))))
  }
  else if (typeid(&f) == typeid(Subtract)) {
    this-df = new Subtract(new Derivative(f->getMinuend()), new Derivative(f->getSubtrahend()));
  }
  else if (typeid(&f) == typeid(Constant)) {
    this->df = new Constant(0);
  }
  else if (typeid(&f) == typeid(Power)) {
    this->df = new Product(new Product(new Power(f->getFunction(), f->getPower() - 1), new Constant(f->getPower()),
                                       new Derivative(f->getFunction());
  }
  else if (typeid(&f) == typeid(Sine)) {
    this->df = new Product(new Cosine(f->getFunction()), new Derivative(f->getFunction()));
  }
  else if (typeid(&f) == typeid(Cosine)) {
    this->df = new Product(new Product(new Constant(-1), new Sine(f->getFunction())),
                           new Derivative(f->getFunction()));
  }
  else if (typeid(&f) == typeid(Log)) {
    this->df = new Product(new Divide(new Constant(1),  new Product(new Log(f->getBase(), e), f->getFunction())),
                           new Derivative(f->getFunction()));
  }
  else if (typeid(&f) == typeid(Exp)) {
    this->df = new Product(new Product(new Exp(f->getFunction(), f->getBase()), new Log(f->getBase(), e)),
                           new Derivative(f->getFunction()));
  }
  else if (typeid(&f) == typeid(Asine)) {
    this->df = new Product(new Divide(new Constant(1), new Power(new Subtract(
      new Constant(1),
      new Power(f->getFunction(), new Constant(2))
    ), new Constant(0.5))),
                           new Derivative(f->getFunction()));
  }
  else if (typeid(&f) == typeid(Acosine)) {
    this->df = new Product(new Divide(new Constant(-1), new Power(new Subtract(
      new Constant(1),
      new Power(f->getFunction(), new Constant(2))
    ), new Constant(0.5))),
                           new Derivative(f->getFunction()));
  }
  else if (typeid(&f) == typeid(Atan)) {
    this->df = new Product(Divide(new Constant(1), new Add(new Constant(1), new Power(f->getFunction(), new Constant(2)))),
                           new Derivative(f->getFunction()));
  }
  else if (typeid(&f) == typeid(Atan2)) {
    this->df = new Product(new Derivative(new Divide(new Sine(f->getF1()), new Cosine(f->getF2()))),
                           new Derivative(new Divide(new Sine(f->getF1()), new Cosine(f->getF2()))));
  }
}
double Derivative::evaluate(double x) {
  return this->df->evaluate(x);
}
