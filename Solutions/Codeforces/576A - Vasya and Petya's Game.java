import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
  static class Solver{
    void main(){
      int n = nextInt();
      Vector<Integer> v = new Vector<Integer>();

      for(int i = 2; i <= n; ++i){
        if(BigInteger.valueOf(i).isProbablePrime(10)){
          for(int k = 1, x = i; x <= n; ++k, x *= i){
            v.add(x);
          }
        }
      }
      printf("%d\n", v.size());
      for(int x : v){
        printf("%d ", x);
      }
      printf("\n");
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
