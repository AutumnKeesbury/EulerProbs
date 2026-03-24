#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  // get the right primes!
  const unsigned int primes[] = {2,  3,  5,  7,  11, 13, 17, 19, 23,
                                 29, 31, 37, 41, 43, 47, 53, 57};

  unsigned int tests;
  cin >> tests;
  while (tests--) {
    unsigned long long limit;
    cin >> limit;

    // multiply until we hit the limit
    unsigned long long bestPos = 2;
    for (auto p : primes) {
      // continue until bestPos >= desired value
      if (bestPos >= (limit + p - 1) / p)
        break;
      bestPos *= p;
    }
    cout << bestPos << endl;
  }
  return 0;
}
