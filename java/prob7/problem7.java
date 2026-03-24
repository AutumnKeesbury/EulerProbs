import java.util.*;
import java.math.*;

class problem7 {
  static Integer MAX_SIZE = 1000005;
  static List<Integer> PRIMES = findPrimes(MAX_SIZE);

  public static void main(String[] args) {
    Integer n = 10001;
    Integer pN = findNthPrime(n);
    System.out.println("The " + n + "th prime number is: " + pN);
  }

  public static List<Integer> findPrimes(int limit) {
    boolean[] isPrime = new boolean[limit + 1];
    Arrays.fill(isPrime, true);
    for (int p = 2; p * p <= limit; p++) {
      if (isPrime[p]) {
        for (int i = p * p; i <= limit; i += p) {
          isPrime[i] = false;
        }
      }
    }
    List<Integer> primes = new ArrayList<>();
    for (int i = 2; i <= limit; i++) {
      if (isPrime[i]) {
        primes.add(i);
      }
    }
    return primes;
  }

  public static int findNthPrime(Integer n) {
    return PRIMES.get(n - 1);
  }

  public static void printArr(List<Integer> arr) {
    System.out.print("[ ");
    for (int i = 0; i < arr.size() - 1; i++) {
      System.out.print(arr.get(i) + ", ");
    }
    System.out.print(arr.get(arr.size() - 1) + " ]");
  }
}
