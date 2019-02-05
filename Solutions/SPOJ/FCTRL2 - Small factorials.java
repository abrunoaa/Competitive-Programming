import java.io.*;
import java.util.*;
import java.math.*;

class Main{
  static class Solver{
    void main(){
      BigInteger[] fact = new BigInteger[102];
      fact[0] = BigInteger.ONE;
      for(int n = 1; n <= 100; ++n){
        fact[n] = fact[n - 1].multiply(BigInteger.valueOf(n));
      }

      int t = nextInt();
      while(t-- > 0){
        int n = nextInt();
        printf("%d\n", fact[n]);
      }
    }

    PrintWriter out;
    BufferedReader reader;
    StringTokenizer tokens;

    Solver(){
      tokens = new StringTokenizer("");
      reader = new BufferedReader(new InputStreamReader(System.in), 1 << 15);
      out = new PrintWriter(System.out);

      Locale.setDefault(Locale.US);
      main();
      out.close();
    }

    int nextInt() { return Integer.parseInt(next()); }

    String next(){
      readTokens();
      return tokens.nextToken();
    }

    boolean readTokens(){
      while(!tokens.hasMoreTokens()){
        try{
          String line = reader.readLine();
          if(line == null) return false;
          tokens = new StringTokenizer(line);
        }
        catch(IOException e){
          throw new RuntimeException(e);
        }
      }
      return true;
    }

    void printf(String s, Object... o) { out.printf(s, o); }
  }

  public static void main(String[] args){ new Solver(); }
}
