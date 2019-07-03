import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
  final int mod = (int)1e9 + 7;
  final int maxn = -1;
  final double eps = 1e-9;

  void main(){
    // freopen("in");
    int T = nextInt();
    for(int t = 0; t < T; ++t){
      int x = nextInt();
      int n = nextInt();
      int[] dp = new int[x + 1];
      for(int i = 1; i <= x; ++i){
        dp[i] = inf;
      }
      for(int i = 0; i < n; ++i){
        int a = nextInt();
        for(int j = a; j <= x; ++j){
          dp[j] = Math.min(dp[j], dp[j - a] + 1);
        }
      }
      if(dp[x] == inf){
        printf("No solution\n");
      }
      else{
        printf("%d\n", dp[x]);
      }
    }
  }

  final double pi = Math.acos(-1.0);
  final long infl = 0x3f3f3f3f3f3f3f3fl;
  final int inf = 0x3f3f3f3f;
  final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;  // pode dar RTE!!!

  int cmp(double x, double y){ return (Math.abs(x - y) < eps ? 0 : x < y ? -1 : 1); }

  PrintWriter out = new PrintWriter(System.out);
  BufferedReader reader = new BufferedReader(new InputStreamReader(System.in), 1 << 15);
  StringTokenizer tokens = new StringTokenizer("");

  Main(){
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

  void readTokens(){ while(!tokens.hasMoreTokens()) try{ tokens = new StringTokenizer(reader.readLine()); } catch(IOException e){ throw new RuntimeException(e); } }

  void printf(String s, Object... o){ out.printf(s, o); }
  void debug(String s, Object... o){ if(!ONLINE_JUDGE) System.err.printf((char)27 + "[91m" + s + (char)27 + "[0m", o); }

  public static void main(String[] args){ new Main(); }
}
