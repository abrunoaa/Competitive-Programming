import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
  public static void main(String [] args) throws Exception
  {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    BigInteger b = BigInteger.ONE;
    for (int i = 2; i <= n; ++i)
      b = b.multiply(BigInteger.valueOf(i)).divide(b.gcd(BigInteger.valueOf(i)));
    System.out.println(b);
  }
}
