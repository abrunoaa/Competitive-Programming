import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
  static class Solver{
    Vector<Integer> div(int x){
      Vector<Integer> d = new Vector<Integer>();
      for(int i = 2; i * i <= x; ++i){
        if(x % i == 0){
          d.add(i);
          if(i != x / i){
            d.add(x / i);
          }
        }
      }
      return d;
    }

    void main(){
      // freopen("in");

      int n = nextInt();
      int[] t = new int[n];
      int ans = 0;
      for(int i = 0; i < n; ++i){
        t[i] = nextInt();
        ans += t[i];
      }

      for(int k : div(n)){
        if(n / k < 3){
          continue;
        }
        int[] s = new int[k];
        for(int i = 0; i < n; ++i){
          s[i % k] += t[i];
        }
        for(int x : s){
          ans = max(ans, x);
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
