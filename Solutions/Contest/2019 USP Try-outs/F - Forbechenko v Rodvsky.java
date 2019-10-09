import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
  static long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    long a = in.nextLong();
    long b = in.nextLong();
    b /= gcd(a, b);
    int up = Math.min((int)Math.sqrt(b), (int)1e6);
    long ans = 1;
    for (int d = 2; d <= up; ++d) {
      if (b % d == 0) {
        ans *= d;
        while (b % d == 0) {
          b /= d;
        }
      }
    }
    int r = (int)(Math.sqrt(b) + 0.5);
    if (b > 1 && (long)r * r == b && BigInteger.valueOf(r).isProbablePrime(10)) {
      ans *= (int)Math.sqrt(b);
    } else {
      ans *= b;
    }
    System.out.printf("%d\n", Math.max(2, ans));
  }
}
