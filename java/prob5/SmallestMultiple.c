// 2040 is the smallest number which is divisible by 1,...,10
// What is the smallest positive integer divisible by 1,...,20?
#include <stdio.h>
#include <stdlib.h>

// For some integer p and some finite set of integers S,
// we have that p is divisible by all of the elements of S
// <=> p = a_1*x_1 + a_2*x_2 + ... + a_n*x_n for some integers
// a_i and x_i in S. However, we must only consider the smallest
// multiples of each x_i.

int main(int argc, char *argv[]) {

  long p = 1;
  for (long i = 1; i <= 20; i++) {
    p *= i;
  }
  printf("Smallest multiple of numbers 1,...,20: %li\n", p);
  return EXIT_SUCCESS;
}
