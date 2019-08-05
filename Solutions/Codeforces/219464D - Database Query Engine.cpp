// C++11

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef pair<long long, long long> ii;

struct cmp {
  bool operator () (ii a, ii b) const {
    return a.first > b.first || (a.first == b.first && a.second < b.second);
  }
};

template <typename T>
using ordered_set = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

struct no {
  long long reliability;
  string code;
};

vector<no> V;
unordered_map<string, int> dic;
int idx, N, SQ;
ordered_set<ii> kth;

void issue(string codex) {

  if (dic.count(codex) == true) {
    int id = dic[codex];
    cout << "EXISTS " << id << ' ' << V[id].reliability << '\n';
  } else {
    dic[codex] = idx;
    V[idx].code = codex;
    V[idx].reliability = 0;
    kth.insert(ii(0, idx));
    cout << "CREATED " << idx << " 0\n";
    ++idx;
  }
}

void del(string code) {

  if (dic.count(code)) {
    int id = dic[code];
    cout << "OK " << id << ' ' << V[id].reliability << '\n';
    kth.erase(ii(V[id].reliability, id));
    dic.erase(code);
  } else {
    cout << "BAD REQUEST\n";
  }
}

void Reli(const string &code, long long x) {

  if (dic.count(code)) {
    int id = dic[code];
    kth.erase(ii(V[id].reliability, id));
    V[id].reliability += x;
    kth.insert(ii(V[id].reliability, id));
    cout << "OK " << id << ' ' << V[id].reliability << '\n';
  } else {
    cout << "BAD REQUEST\n";
  }
}

void find(int n) {

  if (kth.empty()) {
    cout << "EMPTY\n";
  } else {
    ii ans = *kth.find_by_order( min(n, (int)kth.size() - 1) );
    cout << "OK " << V[ans.second].code << ' ' << ans.second << ' ' << ans.first << '\n';
  }
}

int main() {

  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> N;
  SQ = (int)sqrt(N);
  V.assign(N + 1, no());
  idx = 0;
  string cmd, temp;
  long long m;

  while (N--) {
    cin >> cmd;
    if (cmd == "ISSUE") {
      cin >> temp;
      issue(temp);
    } else if (cmd == "DELETE") {
      cin >> temp;
      del(temp);
    } else if (cmd == "RELIABILITY") {
      cin >> temp >> m;
      Reli(temp, m);
    } else {
      cin >> m;
      find(m);
    }
  }
  return 0;
}
