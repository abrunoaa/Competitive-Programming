import java.util.Scanner;
import java.io.IOException;
import java.math.BigInteger;

class Main
{
  public static void main (String [] args) throws IOException
  {
    Scanner in = new Scanner(System.in);

    BigInteger n1, n2;

    while (in.hasNext())
    {
      n1 = in.nextBigInteger();
      n2 = in.nextBigInteger();

      System.out.println(n1.xor(n2));
    }
  }
}
