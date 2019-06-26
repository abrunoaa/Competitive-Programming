import java.io.*;
import java.util.*;
import java.math.*;

public class E{
  final int mod = 998244353;
  final int maxn = -1;
  final double eps = 1e-9;

  void main(){
    // freopen("in");
    int n = nextInt();
    List<Long> a = new ArrayList<Long>();
    for(int i = 0; i < n; ++i){
      a.add((long)(i + 1) * (n - i) * nextInt());
    }
    List<Integer> b = new ArrayList<Integer>();
    for(int i = 0; i < n; ++i){
      b.add(nextInt());
    }
    Collections.sort(a);
    Collections.sort(b, (x, y) -> Integer.compare(y, x));
    int ans = 0;
    for(int i = 0; i < n; ++i){
      ans = (int)(ans + a.get(i) % mod * b.get(i) % mod) % mod;
    }
    printf("%d\n", ans);
  }

  final double pi = Math.acos(-1.0);
  final long infl = 0x3f3f3f3f3f3f3f3fl;
  final int inf = 0x3f3f3f3f;
  final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;

  boolean zero(double x){ return x < eps; }

  PrintWriter out = new PrintWriter(System.out);
  BufferedReader reader = new BufferedReader(new InputStreamReader(System.in), 1 << 15);
  StringTokenizer tokens = new StringTokenizer("");

  E(){
    Locale.setDefault(Locale.US);       // imprime double com ponto
    main();
    out.close();
  }

  void freopen(String s){ try{ reader = new BufferedReader(new InputStreamReader(new FileInputStream(s)), 1 << 15); } catch(FileNotFoundException e){ throw new RuntimeException(e); } }

  int nextInt(){ return Integer.parseInt(next()); }
  long nextLong(){ return Long.parseLong(next()); }
  double nextDouble(){ return Double.parseDouble(next()); }
  String next(){ readTokens(); return tokens.nextToken(); }
  String nextLine(){ readTokens(); return tokens.nextToken("\n"); }

  void readTokens(){
    while(!tokens.hasMoreTokens())      // lê os dados, ignorando linhas vazias
      try{ tokens = new StringTokenizer(reader.readLine()); } catch(IOException e){ throw new RuntimeException(e); }
  }

  void printf(String s, Object... o){ out.printf(s, o); }
  void debug(String s, Object... o){ if(!ONLINE_JUDGE) System.err.printf((char)27 + "[91m" + s + (char)27 + "[0m", o); }

  public static void main(String[] args){ new E(); }
}
