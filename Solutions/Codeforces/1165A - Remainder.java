import java.io.*;
import java.util.*;
import java.math.*;

public class A{
  final int mod = 1000000007;
  final int maxn = -1;
  final double eps = 1e-9;

  void solve(){
    // freopen("in");
    int n = nextInt();
    int x = nextInt();
    int y = nextInt();
    String s = new StringBuilder(next()).reverse().toString();
    int ans = 0;
    for(int i = 0; i < x; ++i){
      char c = s.charAt(i);
      if(i == y && c == '0'){
        ++ans;
      }
      else if(i != y && c == '1'){
        ++ans;
      }
    }
    printf("%d\n", ans);
  }

  final double pi = Math.acos(-1.0);
  final long infl = 0x3f3f3f3f3f3f3f3fl;
  final int inf = 0x3f3f3f3f;
  final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;

  boolean zero(double x){ return x < eps; }

  /** io **/
  PrintWriter out;
  BufferedReader reader;
  StringTokenizer tokens;

  A(){
    long s = System.currentTimeMillis();
    tokens = new StringTokenizer("");
    reader = new BufferedReader(new InputStreamReader(System.in), 1 << 15);
    out = new PrintWriter(System.out);
    Locale.setDefault(Locale.US);     // imprime double com ponto
    solve();
    out.close();
    debug("Time elapsed: %dms", System.currentTimeMillis() - s);
  }

  void freopen(String s){
    try{ reader = new BufferedReader(new InputStreamReader(new FileInputStream(s)), 1 << 15); }
    catch(FileNotFoundException e){ throw new RuntimeException(e); }
  }

  /** input -- supõe que não chegou no EOF **/
  int nextInt(){ return Integer.parseInt(next()); }
  long nextLong(){ return Long.parseLong(next()); }
  double nextDouble(){ return Double.parseDouble(next()); }

  String next(){ readTokens(); return tokens.nextToken(); }
  String nextLine(){ readTokens(); return tokens.nextToken("\n"); }

  boolean readTokens(){
    while(!tokens.hasMoreTokens()){             // lê os dados, ignorando linhas vazias
      try{
        String line = reader.readLine();
        if(line == null) return false;          // EOF
        tokens = new StringTokenizer(line);
      }
      catch(IOException e){ throw new RuntimeException(e); }
    }
    return true;
  }

  /** output **/
  void printf(String s, Object... o){ out.printf(s, o); }
  void debug(String s, Object... o){ if(!ONLINE_JUDGE) System.err.printf((char)27 + "[91m" + s + (char)27 + "[0m", o); }

  public static void main(String[] args){ new A(); }
}
