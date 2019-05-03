import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
  public static void main(String [] args) throws Exception
  {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    BigInteger[] f = new BigInteger[n + 10];
    f[0] = BigInteger.ZERO;
    f[1] = f[2] = BigInteger.ONE;
    for (int i = 3; i <= n; ++i) f[i] = f[i - 1].add(f[i - 3]);
    System.out.println(f[n]);
  }
}
