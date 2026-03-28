#include <iostream>
using namespace std;

using mat = vector<vector<long long>>;
using vec = vector<long long>;
int MOD = 1e9 + 7;

class matrix {
private:
  mat Mat;
  int m, n;

public:
  matrix() {}     // null constructor
  matrix(mat M) { // default constructor
    this->Mat = M;
    this->m = M.size();
    this->n = M[0].size();
  }

  int getSize_m() { return m; }
  int getSize_n() { return n; }
  mat asVec() { return Mat; }
  long long getAt(int i, int j) { return Mat[i][j]; }

  void size() { printf("%i x %i\n", (*this).m, (*this).n); }

  void print() {
    int m = (*this).m;
    int n = (*this).n;
    for (int i = 0; i < m; i++) {
      cout << "[";
      for (int j = 0; j < n; j++) {
        printf(" %lld ", (*this).Mat[i][j]);
      }
      cout << "]" << endl;
    }
  }

  matrix operator=(const matrix &a) { return {a.Mat}; }
  matrix friend operator*(const matrix &a, const matrix &b) {
    mat A = a.Mat;
    mat B = b.Mat;
    mat c;
    for (int i = 0; i < A.size(); i++) {
      for (int j = 0; j < A[0].size(); j++) {
        c[i][j] = 0;
        for (int k = 0; k < A[0].size(); k++) {
          c[i][j] += (A[i][k] * B[k][j]);
        }
      }
    }
    return {c};
  }

  matrix friend operator+(matrix &a, matrix &b) {
    mat c;
    for (int i = 0; i < a.m; i++) {
      for (int j = 0; j < a.n; j++) {
        c[i][j] = a.Mat[i][j] + b.Mat[i][j];
      }
    }
    return {c};
  }

  matrix operator%(int mod) {
    matrix c;
    for (int i = 0; i < (*this).m; i++) {
      for (int j = 0; j < (*this).n; j++) {
        c.Mat[i][j] = Mat[i][j] % mod;
      }
    }
    return c;
  }

  matrix friend operator^(matrix &a, int power) {
    matrix c{{{1, 0}, {0, 1}}};
    while (power) {
      if (power & 1) {
        c *= a;
      }
      a *= a;
      power >>= 1;
    }
    return c;
  }

  bool operator==(matrix &a) {
    for (int i = 0; i < (*this).m; i++) {
      for (int j = 0; j < (*this).n; j++) {
        if (!((*this).Mat[i][j] == a.Mat[i][j]))
          return false;
      }
    }
    return true;
  }

  matrix operator%=(int mod) {
    for (int i = 0; i < (*this).m; i++) {
      for (int j = 0; j < (*this).n; j++) {
        (*this).Mat[i][j] %= mod;
      }
    }
    return *this;
  }

  matrix operator*=(matrix &a) {
    *this = (*this * a);
    return *this;
  }
};

matrix ID{{{1, 0}, {0, 1}}};

// Q is a matrix called the Fibonacci matrix, which generates
// the Fibonacci numbers. The order of Q when taken as an
// element in the general linear group GL(2, Z_n) is exactly
// the Pisano period.
matrix Q{{{1, 1}, {1, 0}}};
matrix F0{{{1, 0}, {0, 0}}};

// returns the smallest integer value n for which A^n = A (modulo some int)
int order(matrix A, int n) {
  int i = 1;
  while (!(A == ID)) {
    (A ^ n) % n;
    ++i;
  }
  return i;
}

// returns the order of the Fibonacci matrix in GL(2, Z_n)
static int pisano(int n) { return order(Q, n); }

// returns the nth Fibonacci number
int Fibonacci(int n) {
  if (n == 0 || n == 1)
    return 1;
  matrix A = Q ^ (n - 1);
  matrix F{F0};
  A *= F;
  return Q.getAt(0, 0) % MOD;
}

int main() {
  matrix A{{{1, 2}, {3, 4}}};

  matrix a = Q;
  matrix b = ID;
  A.print();

  cout << A.getAt(0, 0) << endl;

  return 0;
}
