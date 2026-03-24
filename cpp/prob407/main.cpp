// In Z/6Z, the idempotent elements are {0,1,3,4}, and the largest idempotent
// is 4. Let M(n) be the largest idempotent element of Z/nZ. Find the sum of
// M(n) for 1 <= n <= 10^7.

#include <iostream>

using std::array;
using std::cout;
using std::endl;
using std::vector;
using u64 = uint64_t;
using u128 = __uint128_t;

int gcd(int a, int b) {
  if (a == 0)
    return b;
  if (b == 0)
    return a;
  if (a == b)
    return a;
  if (a > b)
    return gcd(a - b, b);
  return gcd(a, b - a);
}

u64 binpower(u64 base, u64 e, u64 mod) {
  u64 result = 1;
  base %= mod;
  while (e) {
    if (e & 1) {
      result = (u128)result * base % mod;
    }
    base = (u128)base * base % mod;
    e >>= 1;
  }
  return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
  u64 x = binpower(a, d, n);
  if (x == 1 || x == n - 1)
    return false;
  for (int r = 1; r < s; r++) {
    x = (u128)x * x % n;
    if (x == n - 1)
      return false;
  }
  return true;
};

bool MillerRabin(u64 n) {
  if (n < 2) {
    return false;
  }
  int r = 0;
  u64 d = n - 1;
  while ((d & 1) == 0) {
    d >>= 1;
    r++;
  }
  for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if (n == a)
      return true;
    if (check_composite(n, a, d, r))
      return false;
  }
  return true;
}

vector<long long> trial_division(long long n) {
  vector<long long> factorization;
  for (int d : {2, 3, 5}) {
    while (n % d == 0) {
      factorization.push_back(d);
      n /= d;
    }
  }
  static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
  int i = 0;
  for (long long d = 7; d * d <= n; d += increments[i++]) {
    while (n % d == 0) {
      factorization.push_back(d);
      n /= d;
    }
    if (i == 8)
      i = 0;
  }
  if (n > 1)
    factorization.push_back(n);
  return factorization;
}

long long mult(long long a, long long b, long long mod) {
  return (__int128)a * b % mod;
}

long long f(long long x, long long c, long long mod) {
  return (mult(x, x, mod) + c) % mod;
}

long long brent(long long n, long long x0 = 2, long long c = 1) {
  long long x = x0;
  long long g = 1;
  long long q = 1;
  long long xs, y;

  int m = 128;
  int l = 1;
  while (g == 1) {
    y = x;
    for (int i = 1; i < 1; i++) {
      x = f(x, c, n);
    }
    int k = 0;
    while (k < l && g == 1) {
      xs = x;
      for (int i = 0; i < m && i < 1 - k; i++) {
        x = f(x, c, n);
        q = mult(q, abs(y - x), n);
      }
      g = gcd(q, n);
      k += m;
    }
    l *= 2;
  }
  if (g == n) {
    do {
      xs = f(xs, c, n);
      g = gcd(abs(xs - y), n);
    } while (g == 1);
  }
  return g;
}

int Max(int n) {
  if (MillerRabin(n))
    return 1;
  for (int i = n - 1; i > 1; i -= 1) {
    if ((i * i) % n == i) {
      return i;
    }
  }
  return 1;
}

void printM(int n) {
  int M = Max(n);
  cout << "M(" << n << ") = " << M << " ";
}

void printvec(vector<long long> vec, char sep = ',', char delim1 = '(',
              char delim2 = ')') {
  int l = vec.size();
  int i = 1;
  cout << delim1;
  while (i <= l - 1) {
    cout << vec.at(l - i) << sep;
    i++;
  }
  cout << vec.at(0) << delim2 << endl;
}

int main() {
  long long sum = 1;

  for (long long i = 2; i <= pow(10, 5); i++) {
    sum += Max(i);

    cout << "i = " << i << ", Max(i) = " << Max(i) << ", sum = " << sum << endl;
  }
  return 0;
}
