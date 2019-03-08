import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
  static class Solver{
    void main(){
      int n = nextInt();

      Vector<Integer> v0 = new Vector<Integer>();
      v0.add(0);
      for(int i = 0; i <= 3; ++i){
        Vector<Integer> v = new Vector<Integer>();
        for(int x : v0){
          if(x != 0 && n % x == 0){
            printf("YES\n");
            return;
          }
          v.add(x * 10 + 4);
          v.add(x * 10 + 7);
        }
        v0 = v;
      }
      printf("NO\n");
    }

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
