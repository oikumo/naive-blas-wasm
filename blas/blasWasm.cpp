#include <emscripten/bind.h>
#include <emscripten/val.h>
#include <cstdint>
#include <cstdlib>
#include <math.h>
#include "../blas/include/vector.h"

using namespace emscripten;

extern "C" {

  class Data {

    public:
    std::vector<uint32_t> data;

    void create(int length) {
      data.assign(length, 0);
    }

    int size() {
      return data.size();
    }

    uint32_t get(int index) {
      return data[index];
    }
    
    void set(int index, uint32_t value) {
      data[index] = value;
    }
  };
}

EMSCRIPTEN_BINDINGS(my_module) {
  function("multiply", &multiply, allow_raw_pointers());
  function("int_sqrt", &int_sqrt);
  function("int_sum", &int_sum);
  function("create_array", &create_array, emscripten::allow_raw_pointers());
  function("free_array", &free_array, emscripten::allow_raw_pointer<size_t>());
  function("modify_array", &modify_array, allow_raw_pointer<size_t>());

  emscripten::class_<Data>("Data")
    .smart_ptr_constructor("Data", &std::make_shared<Data>)
    .function("createArray", &Data::create)
    .function("get", &Data::get)
    .function("set", &Data::set);
  }
