import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;
import java.io.FileInputStream;

class Main
{
  public static void main (String [] args) throws IOException
  {
    //System.setIn(new FileInputStream("in"));

    boolean flag;
    BigInteger prodp, prodn;  // pos, neg
    BigInteger read, temp, max;
    BigInteger stop = BigInteger.valueOf(-999999);
    Scanner in = new Scanner(System.in);

    while (in.hasNext())
    {
      flag = true;
      prodn = prodp = BigInteger.ONE;
      max = stop;

      while (true)
      {
        read = in.nextBigInteger();

//System.out.println("\n §§ " + read);

        if (read.compareTo(stop) == 0)
          break;
        if (read.compareTo(BigInteger.ZERO) == 0)
        {
          flag = true;
          prodn = prodp = BigInteger.ONE;
        }
        else
        {
          prodp = prodp.multiply(read);
          prodn = prodn.multiply(read);

//System.out.println(" >> " + prodp + "  " + prodn);

          if (read.compareTo(BigInteger.ZERO) < 0)
          {
            if (flag)
            {
              if (read.compareTo(BigInteger.ZERO) < 0)
                prodp = BigInteger.ONE;
              else
                prodn = BigInteger.ONE;

              flag = false;
            }
            else
            {
              temp = prodp;
              prodp = prodn;
              prodn = temp;

              if (prodp.compareTo(max) > 0)
                max = prodp;
            }
          }
          else if (prodp.compareTo(max) > 0)
            max = prodp;
        }

        if (read.compareTo(max) > 0)
          max = read;

//System.out.println(" ## " + max);
      }

      System.out.println(max);
    }
  }
}
