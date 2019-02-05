import java.math.*;
import java.util.*;

class Main
{
  public static void main (String args[])
  {
    final int max = 1010;
    Scanner in = new Scanner(System.in);
    int ans[] = new int[max];

    BigInteger fat = BigInteger.ONE;
    for (int i = 1; i < max; ++i)
    {
      fat = fat.multiply(BigInteger.valueOf(i));
      String strfat = fat.toString();
      for (int j = 0; j < strfat.length(); ++j)
        ans[i] += strfat.charAt(j) - '0';
    }

    while (in.hasNext()) System.out.println(ans[in.nextInt()]);
  }
}
