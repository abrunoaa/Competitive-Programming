import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author asus
 */
public class Maratona {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        BigInteger[] fat = new BigInteger[15001];
        
        fat[0] = BigInteger.ONE;
        fat[1] = BigInteger.ONE;
        
        for (Integer i = 2; i <= 15000; ++i)
            fat[i] = fat[i - 1].multiply(BigInteger.valueOf(i));
        
        Scanner s = new Scanner(System.in);
        int n;

        while (true) {
            n = s.nextInt();
            if (n == 0) break;
            System.out.println( fat[ n ]);
        }
    }
}
