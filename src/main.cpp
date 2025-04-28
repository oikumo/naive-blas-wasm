#include <emscripten/bind.h>
#include <emscripten/val.h>
#include <cstdint>
#include <cstdlib>
#include <math.h>
using namespace emscripten;

extern "C" {
  int int_sqrt(int x) { return sqrt(x); }
  int int_sum(int a, int b) { return a + b; }

  
  // Create array in WASM memory
  size_t create_array(int length) {
    return (size_t)static_cast<size_t*>(malloc(length * sizeof(size_t)));
  }
  
  void free_array(size_t ptr) {
    auto data = reinterpret_cast<uint32_t*>(ptr);
    free(data);
  }
  
  void modify_array(size_t ptr, int index, size_t value) {
    auto data = reinterpret_cast<uint32_t*>(ptr);
    data[index] = value;
  }

  void multiplyByTwo(size_t ptr, size_t length) {
    auto data = reinterpret_cast<uint32_t*>(ptr);
    for (size_t i = 0; i < length; ++i) {
        data[i] *= 2;
    }
  }


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
  function("multiplyByTwo", &multiplyByTwo, allow_raw_pointers());
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
