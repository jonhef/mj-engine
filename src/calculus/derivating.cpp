#include "derivating.h"

template <typename T>
Derivative<T>::Derivative() {
  this->f = new Constant<T>(0);
}

template <typename T>
Derivative<T>::Derivative(Function<T> &f) {
  this->f = &f;
  if (typeid(&f) == typeid(Sum<T>)) {
    this->df = new Sum<T>(new Derivative<T>(f->getAddend()), new Derivative<T>(f->getAddend2()));
  }
  else if (typeid(&f) == typeid(Product<T>)) {
    this->df = new Sum<T>(new Product<T>(new Derivative<T>(f->getMultilpier()), f->getMultiplicand()),
                       new Product<T>(f->getMultilpier(), new Derivative<T>(f->getMultiplicand())));
  }
  else if (typeid(&f) == typeid(Divide<T>)) {
    this->df = new Divide<T>(new Subtract<T>(new Product<T>(new Derivative<T>(f->getNumerator()), f->getDenominator()), new Product<T>(f->getNumerator(), new Derivative<T>(f->getDenominator()))))
  }
  else if (typeid(&f) == typeid(Subtract<T>)) {
    this-df = new Subtract<T>(new Derivative<T>(f->getMinuend()), new Derivative<T>(f->getSubtrahend()));
  }
  else if (typeid(&f) == typeid(Constant<T>)) {
    this->df = new Constant<T>(0);
  }
  else if (typeid(&f) == typeid(Power<T>)) {
    this->df = new Product<T>(new Product<T>(new Power<T>(f->getFunction(), f->getPower() - 1), new Constant<T>(f->getPower()),
                                       new Derivative<T>(f->getFunction())));
  }
  else if (typeid(&f) == typeid(Sine<T>)) {
    this->df = new Product<T>(new Cosine<T>(f->getFunction()), new Derivative<T>(f->getFunction()));
  }
  else if (typeid(&f) == typeid(Cosine<T>)) {
    this->df = new Product<T>(new Product<T>(new Constant<T>(-1), new Sine<T>(f->getFunction())),
                           new Derivative<T>(f->getFunction()));
  }
  else if (typeid(&f) == typeid(Log<T>)) {
    this->df = new Product<T>(new Divide<T>(new Constant<T>(1),  new Product<T>(new Log<T>(f->getBase(), e), f->getFunction())),
                           new Derivative<T>(f->getFunction()));
  }
  else if (typeid(&f) == typeid(Exp<T>)) {
    this->df = new Product<T>(new Product<T>(new Exp<T>(f->getFunction(), f->getBase()), new Log<T>(f->getBase(), e)),
                           new Derivative<T>(f->getFunction()));
  }
  else if (typeid(&f) == typeid(Asine<T>)) {
    this->df = new Product<T>(new Divide<T>(new Constant<T>(1), new Power<T>(new Subtract<T>(
      new Constant<T>(1),
      new Power<T>(f->getFunction(), new Constant<T>(2))
    ), new Constant<T>(0.5))),
                           new Derivative<T>(f->getFunction()));
  }
  else if (typeid(&f) == typeid(Acosine<T>)) {
    this->df = new Product<T>(new Divide<T>(new Constant<T>(-1), new Power<T>(new Subtract<T>(
      new Constant<T>(1),
      new Power<T>(f->getFunction(), new Constant<T>(2))
    ), new Constant<T>(0.5))),
                           new Derivative<T>(f->getFunction()));
  }
  else if (typeid(&f) == typeid(Atan<T>)) {
    this->df = new Product<T>(Divide<T>(new Constant<T>(1), new Add<T>(new Constant<T>(1), new Power<T>(f->getFunction(), new Constant<T>(2)))),
                           new Derivative<T>(f->getFunction()));
  }
  else if (typeid(&f) == typeid(Atan2<T>)) {
    this->df = new Product<T>(new Derivative<T>(new Divide<T>(new Sine<T>(f->getF1()), new Cosine<T>(f->getF2()))),
                           new Derivative<T>(new Divide<T>(new Sine<T>(f->getF1()), new Cosine<T>(f->getF2()))));
  }
}

template <typename T>
T Derivative<T>::evaluate(T x) {
  return this->df->evaluate(x);
}
