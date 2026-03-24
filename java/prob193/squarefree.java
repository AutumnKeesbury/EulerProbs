import java.io.*;
import java.math.*;

public class squarefree {
  public static int[] mu(int n) {
    int size = n + 1;
    Boolean[] prime = new Boolean[size];
    for (int i = 0; i < size; i++) {
      prime[i] = true;
    }

    int[] mu = new int[size];

    for (int i = 2; i < size;) {
      if (!prime[i]) {
        i++;
      }
      mu[i] = -1;
      for (int j = 2; j < n / i + 1; j++) {
        prime[i * j] = false;
        mu[i * j] = -1;
      }
      for (int j = 1; j < n / (i * i) + 1; j++) {
        mu[j * i * i] = 0;
      }
      i++;
    }
    return mu;
  }

  public static void printArr(int[] Arr, String function) {
    if (function.length() == 0) {
      for (int i : Arr) {
        System.out.print(" " + i + " ");
      }
    } else {
      for (int i = 0; i < Arr.length; i++) {
        System.out.println(" " + function + "(" + i + ") = " + Arr[i] + " ");
      }
    }
  }

  public static void main(String[] args) {
    int N = 17;
    printArr(mu(N), "μ");
  }
}
