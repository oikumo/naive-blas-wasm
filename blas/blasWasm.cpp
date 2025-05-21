#include <emscripten/bind.h>
#include <emscripten/val.h>
#include <cstdint>
#include <cstdlib>
#include <math.h>
#include "include/vector.h"
#include "include/data.h"
#include "include/texture.h"
#include "include/array-float32.h"

using namespace emscripten;

EMSCRIPTEN_BINDINGS(my_module) {
  function("draw", &texture::draw);
  function("multiply", &multiply, allow_raw_pointers());
  function("int_sqrt", &int_sqrt);
  function("int_sum", &int_sum);
  function("create_array", &create_array, emscripten::allow_raw_pointers());
  function("free_array", &free_array, emscripten::allow_raw_pointer<size_t>());
  function("modify_array", &modify_array, allow_raw_pointer<size_t>());
  function("drawTexToTex", &drawTexToTex, allow_raw_pointer<size_t>());

  function("arrayFloat32Modify", &arrayFloat32Modify, emscripten::allow_raw_pointers());
  function("arrayFloat32ModifySegment", &arrayFloat32Modify, emscripten::allow_raw_pointers());

  emscripten::class_<Data>("Data")
    .smart_ptr_constructor("Data", &std::make_shared<Data>)
    .function("createArray", &Data::create)
    .function("get", &Data::get)
    .function("set", &Data::set);
  }
