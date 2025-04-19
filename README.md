
emcc main.cpp   -O3   -s WASM=1   -s MODULARIZE=1   -s EXPORT_NAME="Module"   -s -lembind --emit-tsd module.d.ts  -o dist/module.js
