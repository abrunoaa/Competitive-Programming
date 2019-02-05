/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import static java.lang.Math.min;
import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author asus
 */
public class Main {

    static BigInteger[] fat = new BigInteger[100000];
    static int val = 2;

    static boolean calcFat(int newValue, BigInteger lim) {
        Integer i;
        for (i = val; i <= (newValue + 3); ++i) {
            fat[i] = fat[i - 1].multiply(BigInteger.valueOf(i));
            if (lim != BigInteger.ZERO && fat[i].compareTo(lim) == 1)
                return false;
        }
        
        val = i - 1;
        return true;
    }
    
    public static void main(String[] args) {
        
        /*
        FileInputStream instream = null;  
        PrintStream outstream = null;  

        try {  
            instream = new FileInputStream("../in.txt");  
            outstream = new PrintStream(new FileOutputStream("../out.txt"));  
            System.setIn(instream);  
            System.setOut(outstream);  
        } catch (Exception e) {  
            System.err.println("Error Occurred.");  
        }*/  
        
        
        fat[0] = BigInteger.ONE;
        fat[1] = BigInteger.ONE;
        
        calcFat(1500, BigInteger.ZERO);
        
        Scanner s = new Scanner(System.in);
        int n, q;
        BigInteger t;

        while (true) {
            n = s.nextInt();
            q = s.nextInt();
            if (n == 0 && q == 0) break;
            
            t = s.nextBigInteger();
            
            
            n = n - q + 1;
            //This method returns -1, 0 or 1 as this BigInteger is numerically 
            //less than, equal to, or greater than val.
            if (fat[ min(val, n) ].compareTo(t) == 1 || !calcFat(n, t)) 
                System.out.println("descartado");
            else 
                System.out.println( fat[ n ] );
        }
    }
}
