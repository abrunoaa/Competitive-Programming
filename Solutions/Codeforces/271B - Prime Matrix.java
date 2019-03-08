import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
  static class Solver{
    Vector<Integer> primes;

    void sieve(int n){
      primes = new Vector<Integer>((int)(n / (Math.log(n) - 1)));
      BitSet isp = new BitSet(n);
      isp.set(2, n);

      for(int i = 2; i < n; ++i){
        if(isp.get(i)){
          primes.add(i);
          for(int j = 2 * i; j < n; j += i){
            isp.clear(j);
          }
        }
      }
    }

    int getPrime(int x){
      int i = 0, j = primes.size() - 1;
      while(i < j){
        int m = (i + j) / 2;
        if(primes.get(m).compareTo(x) < 0){
          i = m + 1;
        }
        else{
          j = m;
        }
      }
      return primes.get(i);
    }

    void main(){
      // freopen("in");
      sieve(100010);

      int n = nextInt();
      int m = nextInt();
      // int n = 500;
      // int m = 500;

      int[] cr = new int[n];
      int[] cc = new int[m];

      for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
          int x = nextInt();
          // int x = rand() % 100000 + 1;
          int c = getPrime(x) - x;
          cr[i] += c;
          cc[j] += c;
        }
      }

      int ans = inf;
      for(int x : cr){
        ans = min(ans, x);
      }
      for(int x : cc){
        ans = min(ans, x);
      }
      printf("%d\n", ans);
    }

    final int maxn = 100010;
    final int inf = 0x3f3f3f3f;

    Random rnd = new Random();
    int rand(){ return rnd.nextInt(); }

    <T extends Comparable<T>> T max(T x, T y){ return (x.compareTo(y) > 0 ? x : y); }
    <T extends Comparable<T>> T min(T x, T y){ return (x.compareTo(y) < 0 ? x : y); }

    /** io **/
    PrintWriter out;
    BufferedReader reader;
    StringTokenizer tokens;

    Solver(){
      tokens = new StringTokenizer("");
      reader = new BufferedReader(new InputStreamReader(System.in), 1 << 15);
      out = new PrintWriter(System.out);

      main();      // solução
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

  public static void main(String[] args){
    new Solver();
  }
}
