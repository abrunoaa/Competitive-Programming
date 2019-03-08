import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
  static class Solver{
    void main(){
      freopen("in");

      int n = nextInt();
      int k = nextInt();
      int p = nextInt();

      Vector<Integer> even = new Vector<Integer>(n);
      Vector<Integer> odd = new Vector<Integer>(n);

      for(int i = 0; i < n; ++i){
        int a = nextInt();
        if(a % 2 == 0){
          even.add(a);
        }
        else{
          odd.add(a);
        }
      }

      if(odd.size() < k - p || odd.size() % 2 != (k - p) % 2){
        printf("NO\n");
        return;
      }

      Vector[] ans = new Vector[k];
      for(int i = 0; i < k; ++i){
        ans[i] = new Vector<Integer>(1);
      }

      int i;
      for(i = 0; i < k - p; ++i){
        ans[i].add(odd.get(odd.size() - 1));
        odd.remove(odd.size() - 1);
      }
      for(; i < k; ++i){
        if(!even.isEmpty()){
          ans[i].add(even.get(even.size() - 1));
          even.remove(even.size() - 1);
        }
        else if(odd.size() >= 2){
          for(int j = 0; j < 2; ++j){
            ans[i].add(odd.get(odd.size() - 1));
            odd.remove(odd.size() - 1);
          }
        }
        else{
          printf("NO\n");
          return;
        }
      }

      while(!even.isEmpty()){
        ans[0].add(even.get(even.size() - 1));
        even.remove(even.size() - 1);
      }
      assert(odd.size() % 2 == 0);
      while(!odd.isEmpty()){
        ans[0].add(odd.get(odd.size() - 1));
        odd.remove(odd.size() - 1);
      }

      printf("YES\n");
      for(i = 0; i < k; ++i){
        printf("%d", ans[i].size());
        for(Object x : ans[i]){
          printf(" %d", (int)x);
        }
        printf("\n");
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

