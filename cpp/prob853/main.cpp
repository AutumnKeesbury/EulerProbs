#include <iostream>
using namespace std;

using mat = vector<vector<long long>>;
using vec = vector<long long>;

struct matrix {
  mat Mat;
  int m;
  int n;
  matrix friend operator*(const matrix &a, const matrix &b) {
    if (a.m != b.m || a.n != b.n) {
      return a;
    }
    matrix c;
    for (int i = 0; i < a.m; i++) {
      for (int j = 0; j < a.n; j++) {
        c.Mat[i][j] = 0;
        for (int k = 0; k < a.m; k++) {
          c.Mat[i][j] += a.Mat[i][k] * b.Mat[k][j];
        }
      }
    }
    return c;
  }
  matrix friend operator+(const matrix &a, const matrix &b) {
    matrix c;
    for (int i = 0; i < a.m; i++) {
      for (int j = 0; j < a.n; j++) {
        c.Mat[i][j] = a.Mat[i][j] + b.Mat[i][j];
      }
    }
  }
};

matrix ID{{{1, 0}, {0, 1}}};

int MOD = 1e9 + 7;

void printMatrix(matrix A) {
  int m = A.m;
  int n = A.n;
  for (int i = 0; i < m; i++) {
    cout << "[";
    for (int j = 0; j < n; j++) {
      printf(" %lld ", A[i][j]);
    }
    cout << "]" << endl;
  }
}

// A is a matrix called the Fibonacci matrix, which generates
// the Fibonacci numbers. The order of A when taken as an
// element in the general linear group GL(2, Z_n) is exactly
// the Pisano period.
matrix A() { return {{1, 1}, {1, 0}}; }
matrix F0() { return {{1, 0}, {0, 0}}; }

// returns A * B
matrix multiply(matrix &A, matrix &B) {
  matrix ans(2, vec(2));

  ans[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD;
  ans[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD;
  ans[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD;
  ans[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD;

  return ans;
}

// A => A * B
void multeqls(matrix &A, matrix &B) {
  matrix ans = multiply(A, B);

  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 1; j++) {
      A[i][j] = ans[i][j];
    }
  }
}

// returns M^pow
matrix power(matrix M, int pow) {
  matrix ans = ID;

  while (pow) {
    if (pow & 1)
      multeqls(ans, M);
    multeqls(M, M);
    pow >>= 1;
  }
  return ans;
}

//  returns M (modulo some int)
matrix matrixMod(matrix A, int mod) {
  matrix ans(2, vec(2));
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 1; j++) {
      ans[i][j] = A[i][j] % mod;
    }
  }
  return ans;
}

// returns true iff A==B (by value)
bool isEqual(matrix A, matrix B) {
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 1; j++) {
      if (A[i][j] != B[i][j])
        return false;
    }
  }
  return true;
}

// returns A^pow (modulo some int)
matrix modPower(matrix A, int mod, int pow = 2) {
  return matrixMod(power(A, pow), mod);
}

// returns the smallest integer value n for which A^n = A (modulo some int)
int order(matrix A, int n) {
  int i = 1;
  while (!isEqual(A, ID)) {
    modPower(A, n);
    ++i;
  }
  return i;
}

// returns the order of the Fibonacci matrix in GL(2, Z_n)
static int pisano(int n) {
  matrix Q = A();
  return order(Q, n);
}

// returns the nth Fibonacci number
int Fibonacci(int n) {
  matrix Q = A();
  if (n == 0 || n == 1)
    return 1;
  Q = power(Q, n - 1);

  matrix F = F0();
  multeqls(Q, F);
  return Q[0][0] % MOD;
}

int main() {
  matrix Q = A();
  printMatrix(Q);
  cout << "\nQ^12\n";
  printMatrix(modPower(Q, 8, 12));

  return 0;
}
