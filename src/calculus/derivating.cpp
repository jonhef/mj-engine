#include "derivating.h"

Derivative::Derivative() {
  this->f = Constant(0);
}

Derivative::Derivative(Function f) {
  this->f = f;
}

Derivative::Derivative(Sum s) {
  std::vector<Function*> fs = s.getFunctions();
  std::vector<Derivative*> df;
  for (Function* f : fs) {
    df.push_back(new Derivative(*f));
  }
  this->df = new Sum(df);
}

Derivative::Derivative(Product p) {
  std::vector<Function*> fs = p.getFunctions();
  std::vector<Derivative*> df;
  for (Function* f : fs) {
    df.push_back(new Derivative(*f));
  }
  this->df = new Product(df);
}
