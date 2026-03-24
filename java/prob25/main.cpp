#include <iostream>
using namespace std;

int Fibonacci(int n) {
  if (n >= 3) {
    return Fibonacci(n - 1) + Fibonacci(n - 2);
  } else {
    return 1;
  }
}

int main(int argc, char *argv[]) {
  int n = 25;

  int Fibonacci_n = Fibonacci(n);

  cout << Fibonacci_n << endl;

  for (int i = 12; i < 25;) {
    if (Fibonacci(i) / 1000 > 1) {
      printf("F_%i has more than 4 digits", i);
    } else {
      i += 1;
    }
  }

  return 0;
}
