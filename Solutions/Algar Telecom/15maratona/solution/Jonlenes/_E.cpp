#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n, m, s;
vector<int> countIni, countRef;
vector< vector<int> > adj;
vector< int > indegree;
vector<int> ts;

//Kahn’s algorithm
bool kahnsAlgorithm()
{
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
    ts.clear();

    //Adicionando vertices com grau 0
    for (int i = 0; i < int(indegree.size()); ++i)
        if (indegree[i] == 0) q.push( ii(countIni[i], i) );

    if (q.size() == 0) return false;

    while (!q.empty()) {
        int u = q.top().second;
        q.pop();


        if (s <= countIni[u]) return false;
        s += countRef[u];

        ts.push_back(u);

        // search others
        for (int i = 0; i < int(adj[u].size()); ++i) {
            int v = adj[u][i];

            --indegree[v];
            if (indegree[v] == 0)
                q.push( ii(countIni[v], v) );
        }
    }

    return true;
}


int main() {

    //freopen("../input.txt", "r", stdin);
    //freopen("../out.txt", "w", stdout);

    int i, u, v;

    while (cin >> n >> m >> s && (n || m || s)) {

        countIni.assign(n, 0);
        for (i = 0; i < n; ++i)
            cin >> countIni[i];

        countRef.assign(n, 0);
        for (i = 0; i < n; ++i)
            cin >> countRef[i];

        adj.assign(n, vector<int> ());
        indegree.assign(n, 0);
        for (i = 0; i < m; ++i) {
            cin >> u >> v;
            adj[--u].push_back(--v);
            ++indegree[v];
        }

        if (kahnsAlgorithm() && int(ts.size()) == n) printf("possivel\n");
        else printf("impossivel\n");
    }

    return 0;
}
