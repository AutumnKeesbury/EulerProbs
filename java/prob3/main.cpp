#include "cmath"
#include "iostream"
#include "vector"
using namespace std;

vector<long> primeFactor(long n) {
  vector<long> factors;
  // Check for factor of 2
  if (n % 2 == 0) {
    factors.push_back(2);
    while (n % 2 == 0)
      n /= 2;
  }

  // Check for odd prime factors
  for (long i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0) {
      factors.push_back(i);
      while (n % i == 0)
        n /= i;
    }
  }

  // if remaining n is prime
  if (n > 2) {
    factors.push_back(n);
  }

  return factors;
}

int main(int argc, char *argv[]) {
  long n = 13195;
  long N = 600851475143;
  vector<long> primesN = primeFactor(N);
  for (long prime : primesN) {
    std::cout << prime << " ";
  }
  std::cout << "\n";

  vector<long> primes = primeFactor(n);
  for (long prime : primes) {
    std::cout << prime << " ";
  }
  std::cout << "\nThe largest prime factor of " << n << " is " << primes.back()
            << "\n";
  return 0;
}
