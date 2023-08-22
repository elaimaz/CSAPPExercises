int decode2(int x, int y, int z) {
    y -= z;
    
    z = y; 

    z <<= 31;
    z >>= 31;

    y *= x;

    return y ^ z;
}

int main() {
  return 0;
}
