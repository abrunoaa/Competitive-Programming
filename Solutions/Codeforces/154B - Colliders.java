import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
  static class Solver{
    boolean[] on;
    int[] conflict;
    BitSet isp;
    Vector<Integer> primes;

    void sieve(int n){
      n = max(n, 2);

      isp = new BitSet(n + 1);
      isp.set(2, n + 1);
      primes = new Vector<Integer>((int)(n / (Math.log(n) - 1)));

      for(int i = 2; i <= n; ++i){
        if(isp.get(i)){
          primes.add(i);
          for(int j = 2 * i; j <= n; j += i){
            isp.clear(j);
          }
        }
      }
    }

    Vector<Integer> factors(int x){
      Vector<Integer> f = new Vector<Integer>();
      for(int p : primes){
        if((long)p * p > x){
          break;
        }
        if(x % p == 0){
          f.add(p);
          while(x % p == 0){
            x /= p;
          }
        }
      }
      if(x > 1 || f.size() == 0){
        f.add(x);
      }
      return f;
    }

    String activate(int i){
      if(on[i]){
        return "Already on";
      }

      Vector<Integer> pf = factors(i);
      for(int p : pf){
        if(conflict[p] != 0){
          return "Conflict with " + conflict[p];
        }
      }

      for(int p : pf){
        conflict[p] = i;
      }
      on[i] = true;

      return "Success";
    }

    String deactivate(int i){
      if(!on[i]){
        return "Already off";
      }

      for(int p : factors(i)){
        conflict[p] = 0;
      }
      on[i] = false;

      return "Success";
    }

    void main(){
      freopen("in");

      sieve(maxn);

      int n = nextInt();
      int m = nextInt();

      on = new boolean[n + 1];
      conflict = new int[n + 1];

      for(int i = 0; i < m; ++i){
        String s = next();
        int k = nextInt();
        // debug("%s %d\n", s, k);
        printf("%s\n", (s.compareTo("+") == 0 ? activate(k) : deactivate(k)));
      }
    }

    <T extends Comparable<T>> T max(T x, T y){ return (x.compareTo(y) > 0 ? x : y); }
    <T extends Comparable<T>> T min(T x, T y){ return (x.compareTo(y) < 0 ? x : y); }

    final double pi = Math.acos(-1.0);
    final double eps = 1e-9;
    final long infl = 0x3f3f3f3f3f3f3f3fl;
    final int inf = 0x3f3f3f3f;
    final int mod = 1000000007;
    final int maxn = 100010;

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

