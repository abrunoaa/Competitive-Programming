import java.io.*;
import java.util.*;
import java.math.*;

public class F{
  final int mod = 1000000007;
  final int maxn = (int)4e5 + 3;
  final double eps = 1e-9;

  int n, m;
  int[] k = new int[maxn];
  List<Integer>[] dayOffer = new ArrayList[maxn + 1];{
    for(int i = 0; i < dayOffer.length; ++i){
      dayOffer[i] = new ArrayList();
    }
  }

  boolean can(int day){
    int burles = 0;
    int[] offer = new int[maxn];
    for(int d = 1; d <= day; ++d){
      for(int i : dayOffer[d]){
        offer[i] = Math.max(offer[i], d);
      }
    }
    List<Integer>[] sale = new ArrayList[maxn];
    for(int i = 0; i < sale.length; ++i){
      sale[i] = new ArrayList<Integer>();
    }
    for(int i = 0; i < n; ++i){
      sale[offer[i]].add(i);
    }
    int[] buy = new int[maxn];
    for(int d = 1; d <= day; ++d){
      ++burles;
      for(int i : sale[d]){
        buy[i] = Math.min(k[i], burles);
        burles -= buy[i];
      }
    }
    for(int i = 0; i < n; ++i){
      burles -= 2 * (k[i] - buy[i]);
    }
    return burles >= 0;
  }

  void main(){
    // freopen("in");
    n = nextInt();
    m = nextInt();
    int sum = 0;
    for(int i = 0; i < n; ++i){
      k[i] = nextInt();
      sum += k[i];
    }
    for(int i = 0; i < m; ++i){
      int d = nextInt();
      int t = nextInt() - 1;
      dayOffer[d].add(t);
    }
    int i = 1, j = 2 * sum;
    while(i < j){
      int day = (i + j) / 2;
      if(!can(day)){
        i = day + 1;
      }
      else{
        j = day;
      }
    }
    printf("%d\n", i);
  }

  final double pi = Math.acos(-1.0);
  final long infl = 0x3f3f3f3f3f3f3f3fl;
  final int inf = 0x3f3f3f3f;
  final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;

  boolean zero(double x){ return x < eps; }

  PrintWriter out = new PrintWriter(System.out);
  BufferedReader reader = new BufferedReader(new InputStreamReader(System.in), 1 << 15);
  StringTokenizer tokens = new StringTokenizer("");

  F(){
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

  public static void main(String[] args){ new F(); }
}
