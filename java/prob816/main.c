#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const float S_NULL = 290797;
float MODULUS = 50515093.0f;

float s(float n) {
  if (n == 0) {
    return S_NULL;
  }
  float S = pow(s(n - 1), 2);
  return fmod(S, MODULUS);
}

float *P(float n) {
  float *p = malloc(sizeof(float) * 2);
  p[0] = s(2 * n);
  p[1] = s((2 * n) + 1);
  return p;
}

int main(int argc, char *argv[]) {
  float n = 1.0f;
  printf("s(n-1)^2 = (%f)^2 = %f\n", s(n - 1), pow(s(n - 1), 2));
  printf("\ns(%.f) = %f\n", n, s(n));
  printf("P(1) = (%f, %f)\n", P(n)[0], P(n)[2]);
  return EXIT_SUCCESS;
}
