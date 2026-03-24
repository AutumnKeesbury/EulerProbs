#include <cstdint>
#include <cstdlib>
#include <random>
using namespace std;

int gen_pandigital(int length, int min, int max) {
  int d[max - min];

  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distrib(min, max);

  for (int i = 0; i <= max; i++) {
    int randNum = distrib(gen);
  }

  return 0;
}
