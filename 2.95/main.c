// Solution based on: https://dreamanddead.github.io/CSAPP-3e-Solutions/chapter2/2.96/

#include <stdio.h>
#include <assert.h>

typedef unsigned float_bits;

int float_f2i(float_bits f) {
  unsigned sig = f >> 31;
  unsigned exp = f >> 23 & 0xFF;
  unsigned frac = f & 0x7FFFFF;
  unsigned bias = 0x7F;

  int num;
  unsigned E;
  unsigned M;

  if (exp >= 0 && exp < 0 + bias) {
    num = 0;
  } else if (exp >= 31 + bias) {
    num = 0x80000000;
  } else {
    E = exp - bias;
    M = frac | 0x800000;
    if (E > 23) {
      num = M << (E - 23);
    } else {
      num = M >> (23 - E);
    }
  }

  return sig ? -num : num;
}

int main() {
    assert(float_f2i(0x42E1999A) == 112);
    assert(float_f2i(0xC2E1999A) == -112);
    assert(float_f2i(0x3F000000) == 0);
    assert(float_f2i(0xBF000000) == 0);
    
    return 0;
}