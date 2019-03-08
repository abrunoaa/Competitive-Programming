import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
  static class Solver{
    long f(int n, int r){
      return n / 5 + (n % 5 >= r ? 1 : 0);
    }

    void main(){
      // freopen("in");

      int n = nextInt();
      int m = nextInt();
      long ans = 0;
      for(int r = 1; r <= 5; ++r){
        ans += f(n, r) * f(m, (r == 5 ? 5 : 5 - r));
      }
      printf("%d\n", ans);
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

