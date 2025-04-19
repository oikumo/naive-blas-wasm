#include <emscripten/bind.h>
#include <math.h>
using namespace emscripten;

extern "C" {
  int int_sqrt(int x) { return sqrt(x); }
  int int_sum(int a, int b) { return a + b; }
}

EMSCRIPTEN_BINDINGS(my_module) {
  function("int_sqrt", &int_sqrt);
  function("int_sum", &int_sum);
}


/*#include <math.h>

extern "C" {

int int_sqrt(int x) {
  return sqrt(x);
}

int int_sum(int a, int b) {
  return a + b;
}

}
*/
