import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
  final int mod = 1000000007;
  final int maxn = -1;
  final double eps = 1e-9;

  long digits(long n){
    if(n == 0) return 0;
    int p = (int)Math.log10(n);
    return (p + 1) * (n - (long)Math.pow(10, p) + 1) + digits((long)Math.pow(10, p) - 1);
  }

  void solve(){
    // freopen("in");
    String s = "";
    long k = nextLong();
    long i = 1;
    long j = k;
    while(i < j){
      long m = (i + j) / 2;
      if(digits(m) < k){
        i = m + 1;
      }
      else{
        j = m;
      }
    }
    if(digits(i) >= k) --i;
    printf("%c\n", String.valueOf(i + 1).charAt((int)(k - digits(i) - 1)));
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

  Main(){
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

  public static void main(String[] args){ new Main(); }
}
