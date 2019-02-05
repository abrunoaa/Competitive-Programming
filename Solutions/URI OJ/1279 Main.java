import java.util.Scanner;
import java.io.IOException;
import java.math.BigInteger;

public class Main
{
  public static void main (String [] args) throws IOException
  {
    boolean f = false, bis, hul, bul;
    Scanner in = new Scanner(System.in);
    BigInteger b,
               b0 = BigInteger.valueOf(0),
               b4 = BigInteger.valueOf(4),
               b15 = BigInteger.valueOf(15),
               b55 = BigInteger.valueOf(55),
               b100 = BigInteger.valueOf(100),
               b400 = BigInteger.valueOf(400);

    while (in.hasNext())
    {
      if (f) System.out.println("");
      else   f = true;

      b = in.nextBigInteger();
      bis = b.mod(b4) == b0 && (b.mod(b100) != b0 || b.mod(b400) == b0);
      hul = b.mod(b15) == b0;
      bul = bis && b.mod(b55) == b0;
      if (!bis && !hul && !bul)
        System.out.println("This is an ordinary year.");
      else
      {
        if (bis) System.out.println("This is leap year.");
        if (hul) System.out.println("This is huluculu festival year.");
        if (bul) System.out.println("This is bulukulu festival year.");
      }
    }
  }
}




