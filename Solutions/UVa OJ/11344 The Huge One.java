import java.io.*;
import java.math.*;
import java.util.*;

class Main
{
  public static void main (String[]args) throws Exception
  {
    PrintWriter pr = new PrintWriter(new BufferedWriter(
                                                    new OutputStreamWriter(System.out)));
    Scanner in = new Scanner(System.in);

    int t = in.nextInt();
    while (t-- > 0)
    {
      BigInteger m = in.nextBigInteger();
      int s = in.nextInt();
      boolean ans = true;
      for (int i = 0; i < s; ++i)
      {
        int v = in.nextInt();
        ans &= (m.remainder(BigInteger.valueOf(v)).compareTo(BigInteger.ZERO) == 0);
      }

      if (ans)
        pr.println(m + " - Wonderful.");
      else
        pr.println(m + " - Simple.");
    }

    pr.close();
  }
}

