import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
  static class Solver{
    class ii{
      int st, nd;

      ii(int a, int b){
        st = a;
        nd = b;
      }
    }

    final int maxn = (int)Math.sqrt(1e9) + 10;

    Vector<Integer> primes;
    BitSet isp;

    void sieve(int n){
      primes = new Vector<Integer>();
      isp = new BitSet(n);
      isp.set(0, n);

      for(int i = 2; i < n; ++i){
        if(isp.get(i)){
          primes.add(i);
          for(int j = 2 * i; j < n; j += i){
            isp.clear(j);
          }
        }
      }
    }

    Vector<ii> fatora(int n){
      Vector<ii> f = new Vector<ii>();
      for(int p : primes){
        if((long)p * p > n){
          break;
        }
        if(n % p == 0){
          int e = 0;
          while(n % p == 0){
            n /= p;
            ++e;
          }
          if(p > 3){
            f.add(new ii(p, e));
          }
        }
      }
      if(n > 1){
        f.add(new ii(n, 1));
      }
      return f;
    }

    void main(){
      // freopen("in");

      sieve(maxn);

      int n = nextInt();
      int[] a = new int[n];
      for(int i = 0; i < n; ++i){
        a[i] = nextInt();
      }

      Vector<ii> f0 = fatora(a[0]);
      for(int i = 1; i < n; ++i){
        int x = a[i];
        while(x % 2 == 0){
          x /= 2;
        }
        while(x % 3 == 0){
          x /= 3;
        }
        for(ii p : f0){
          for(int k = 0; k < p.nd; ++k){
            if(x % p.st != 0){
              printf("No\n");
              return;
            }
            x /= p.st;
          }
          if(x % p.st == 0){
            printf("No\n");
            return;
          }
        }
        if(x > 1){
          printf("No\n");
          return;
        }
      }
      printf("Yes\n");
    }

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
  }

  public static void main(String[] args){
    new Solver();
  }
}
