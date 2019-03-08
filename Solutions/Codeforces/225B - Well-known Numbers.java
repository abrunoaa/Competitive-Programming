import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
  static class Solver{
    void main(){
      // freopen("in");

      int s = nextInt();
      int k = nextInt();

      int[] f = new int[maxn];
      long[] g = new long[maxn];
      int nf;

      f[0] = 1;
      g[0] = 1;
      for(nf = 1; ; ++nf){
        long x = g[nf - 1] - (nf <= k ? 0 : g[nf - k - 1]);
        if(x > s){
          break;
        }
        f[nf] = (int)x;
        g[nf] = x + g[nf - 1];
      }

      Vector<Integer> ans = new Vector<Integer>();
      for(int i = nf - 1; i >= 0; --i){
        if(s >= f[i]){
          ans.add(f[i]);
          s -= f[i];
        }
      }

      while(ans.size() < 2){
        ans.add(0);
      }
      printf("%d\n", ans.size());
      for(int x : ans){
        printf("%d ", x);
      }
      printf("\n");
    }

    <T extends Comparable<T>> T max(T x, T y){ return (x.compareTo(y) > 0 ? x : y); }
    <T extends Comparable<T>> T min(T x, T y){ return (x.compareTo(y) < 0 ? x : y); }

    final double pi = Math.acos(-1.0);
    final double eps = 1e-9;
    final long infl = 0x3f3f3f3f3f3f3f3fl;
    final int inf = 0x3f3f3f3f;
    final int mod = 1000000007;
    final int maxn = 1000000;

    boolean zero(double x){ return x < eps; }

    class ii implements Comparable<ii>{
      int st; int nd;

      ii(){ st = nd = 0; }
      ii(int a, int b){ st = a; nd = b; }

      public int compareTo(ii p){ return st != p.st ? st - p.st : nd - p.nd; }
      public String toString(){ return "(" + st + ", " + nd + ")"; }
    }

    class tri implements Comparable<tri>{
      int st; int nd; int rd;

      tri(){ st = nd = rd = 0; }
      tri(int a, int b, int c){ st = a; nd = b; rd = c; }

      public int compareTo(tri p){ return st != p.st ? st - p.st : nd != p.nd ? nd - p.nd : rd - p.rd; }
      public String toString(){ return "(" + st + ", " + nd + ", " + rd + ")"; }
    }

    /** io **/
    PrintWriter out;
    BufferedReader reader;
    StringTokenizer tokens;

    Solver(){
      tokens = new StringTokenizer("");
      reader = new BufferedReader(new InputStreamReader(System.in), 1 << 15);
      out = new PrintWriter(System.out);

      Locale.setDefault(Locale.US);     // imprime double com ponto
      main();                           // solução
      out.close();                      // flush output
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

