import java.io.*;
import java.util.*;
import java.math.*;

public class D{
  final int mod = 1000000007;
  final int maxn = -1;
  final double eps = 1e-9;

  long solve(){
    int n = nextInt();
    List<Integer> a = new ArrayList<Integer>();
    for(int i = 0; i < n; ++i){
      a.add(nextInt());
    }
    Collections.sort(a);
    long ans = (long)a.get(0) * a.get(n - 1);
    for(int i = 1; i <= n / 2; ++i){
      if((long)a.get(i) * a.get(n - i - 1) != ans){
        return -1;
      }
    }
    List<Long> div = new ArrayList<Long>();
    for(long i = 2; i * i <= ans; ++i){
      if(ans % i == 0){
        div.add(i);
        if(i != ans / i){
          div.add(ans / i);
        }
      }
    }
    if(a.size() != div.size()){
      return -1;
    }
    Collections.sort(div);
    for(int i = 0; i < n; ++i){
      if((long)a.get(i) != div.get(i)){
        return -1;
      }
    }
    return ans;
  }

  void main(){
    // freopen("in");
    int T = nextInt();
    for(int t = 1; t <= T; ++t){
      printf("%d\n", solve());
    }
  }

  final double pi = Math.acos(-1.0);
  final long infl = 0x3f3f3f3f3f3f3f3fl;
  final int inf = 0x3f3f3f3f;
  final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;

  boolean zero(double x){ return x < eps; }

  PrintWriter out = new PrintWriter(System.out);
  BufferedReader reader = new BufferedReader(new InputStreamReader(System.in), 1 << 15);
  StringTokenizer tokens = new StringTokenizer("");

  D(){
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

  public static void main(String[] args){ new D(); }
}
