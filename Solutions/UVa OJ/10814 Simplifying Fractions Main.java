import java.util.*;
import java.io.*;
import java.math.*;

class Main
{
  public static void main (String [] args) throws Exception
  {
    //System.setIn(new FileInputStream("in"));

    Scanner in = new Scanner(System.in);
    PrintWriter pr = new PrintWriter(new BufferedWriter(
                                                new OutputStreamWriter(System.out)));

    int t = in.nextInt();
    while (t-- > 0)
    {
      BigInteger n1 = in.nextBigInteger();
      in.skip(" /");
      BigInteger n2 = in.nextBigInteger();

      BigInteger gcd = n1.gcd(n2);                          // máximo divisor comum

      pr.println(n1.divide(gcd) + " / " + n2.divide(gcd));
    }

    pr.close();
  }
}
