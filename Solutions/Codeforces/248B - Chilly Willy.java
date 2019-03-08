import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
  static class Solver{
    public void solve(){
      int n = nextInt();
      final BigInteger b210 = BigInteger.valueOf(210);
      BigInteger ans = BigInteger.TEN.pow(n - 1).divide(b210).multiply(b210);
      if (ans.toString().length() < n){
        ans = ans.add(b210);
      }
      if(ans.compareTo(BigInteger.ZERO) == 0 || ans.toString().length() != n){
        printf("-1\n");
      }
      else{
        printf("%d\n", ans);
      }
    }

    Solver(){
      tokens = null;
      reader = new BufferedReader(new InputStreamReader(System.in), 1 << 15);
      out = new PrintWriter(System.out);
    }

    public void close(){ out.close(); } // imprime os dados

    PrintWriter out;
    BufferedReader reader;
    StringTokenizer tokens;

    void settoken(){
      while(tokens == null || !tokens.hasMoreTokens()){
        try{
          tokens = new StringTokenizer(reader.readLine());
        }
        catch(IOException e){
          throw new RuntimeException(e);
        }
      }
    }

    String next(){
      settoken();
      return tokens.nextToken();
    }

    String nextLine(){
      settoken();
      return tokens.nextToken("\n");
    }

    int nextInt() { return Integer.parseInt(next()); }
    long nextLong() { return Long.parseLong(next()); }
    double nextDouble() { return Double.parseDouble(next()); }

    void printf(String s, Object... o) { out.printf(s, o); }
  }

  public static void main(String[] args){
    Solver s = new Solver();
    s.solve();
    s.close();
  }
}
