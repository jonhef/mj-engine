# mj-engine

__WORK IN PROGRESS(README ALSO IN PROGRESS)__

## function.h
### class Function<T> (abstract)
- `Function* f` – the main pointer to the function(must be function alike)
- `virtual T evaluate(T x) = 0` – evaluating function's value
- `Function operator` – returns the new object depends on operator(`*` is `Product` and etc.)
- `T operator ()(T x)` – equivs to evaluate
