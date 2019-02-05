#include <bits/stdc++.h>
using namespace std;

void db() { cerr << endl; }

template<class t, class... u>
void db(t x, u... y)
{ cerr << " " << x, db(y...); }

#define gcd __gcd
#define st first
#define nd second
#define pb push_back
#define eps 1e-9
#define zero(x) (abs(x) < eps)
#define inf 0x3f3f3f3f
#define mod 1000000009
#define maxn 50010

typedef long long ll;
typedef long double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> tri;
typedef vector<int> vi;
typedef vector<ii> vii;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Set;
typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update> Map;

#ifndef ONLINE_JUDGE
struct _ { _() { assert(freopen("in","r",stdin)); } } _;
#define db(x...) cerr << " >>", db(x)
#else
#warning "ONLINE_JUDGE"
struct _ { _() { cin.sync_with_stdio(0), cin.tie(0); } } _;
#define db(x...)
#endif

int n, u[maxn], v[maxn];

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> v[i];

    for(int i = 0, k = 1; i < n; ++i, ++k){
        u[i] = k = min(k, v[i]);
    }

    int ans = 0;
    for(int i = n - 1, k = 1; i >= 0; --i, ++k){
        k = min(k, v[i]);
        ans= max(ans, min(k, u[i]));
    }

    cout << ans << '\n';

    return 0;
}

