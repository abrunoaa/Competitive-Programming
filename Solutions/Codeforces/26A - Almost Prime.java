import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
  static class Solver{
    BitSet isp;

    void sieve(int n){
      isp = new BitSet(n + 1);
      isp.set(2, n);

      for(int i = 2; i <= n; ++i){
        if(isp.get(i)){
          for(int j = 2 * i; j <= n; j += i){
            isp.clear(j);
          }
        }
      }
    }

    boolean almost(int x){
      int d = 0;
      for(int i = 1; i * i <= x; ++i){
        if(x % i == 0){
          if(isp.get(i) && ++d > 2){
            return false;
          }
          if(i != x / i && isp.get(x / i) && ++d > 2){
            return false;
          }
        }
      }
      return d == 2;
    }

    void main(){
      int n = nextInt();
      if(n <= 5){
        printf("0\n");
        return;
      }

      sieve(n);
      int ans = 0;
      for(int i = 2; i <= n; ++i){
        if(almost(i)){
          // debug("%d\n", i);
          ++ans;
        }
      }
      printf("%d\n", ans);
    }

    <T extends Comparable<T>> T max(T x, T y){ return (x.compareTo(y) > 0 ? x : y); }
    <T extends Comparable<T>> T min(T x, T y){ return (x.compareTo(y) < 0 ? x : y); }

    final double pi = Math.acos(-1.0);
    final double eps = 1e-9;
    final long infl = 0x3f3f3f3f3f3f3f3fl;
    final int inf = 0x3f3f3f3f;
    final int mod = 1000000007;
    final int maxn = -1;

    boolean zero(double x){ return x < eps; }

    /** io **/
    PrintWriter out;
    BufferedReader reader;
    StringTokenizer tokens;

    Solver(){
      tokens = new StringTokenizer("");
      reader = new BufferedReader(new InputStreamReader(System.in), 1 << 15);
      out = new PrintWriter(System.out);

      Locale.setDefault(Locale.US);
      main();       // solução
      out.close();  // flush output
    }

    void freopen(String s){
      try{
        reader = new BufferedReader(new InputStreamReader(new FileInputStream(s)), 1 << 15);
      }
      catch(FileNotFoundException e){
        throw new RuntimeException(e);
      }
    }

    /** input -- supõe que não chegou no EOF **/
    int nextInt() { return Integer.parseInt(next()); }
    long nextLong() { return Long.parseLong(next()); }
    double nextDouble() { return Double.parseDouble(next()); }

    String next(){
      readTokens();
      return tokens.nextToken();
    }

    String nextLine(){
      readTokens();
      return tokens.nextToken("\n");
    }

    boolean readTokens(){
      while(!tokens.hasMoreTokens()){             // lê os dados, ignorando linhas vazias
        try{
          String line = reader.readLine();
          if(line == null) return false;          // EOF
          tokens = new StringTokenizer(line);
        }
        catch(IOException e){
          throw new RuntimeException(e);
        }
      }
      return true;
    }

    /** output **/
    void printf(String s, Object... o) { out.printf(s, o); }
    void debug(String s, Object... o) { System.err.printf((char)27 + "[91m" + s + (char)27 + "[0m", o); }
  }

  public static void main(String[] args){ new Solver(); }
}
