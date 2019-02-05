#include <iostream>
using namespace std;

struct Graph {
    vector< vector< vector <int> > > adjList;
    vector<int> dfs_visit;
    vector<bool> visited;

    unsigned int n;

    Graph() { n = 0; }
    Graph(unsigned int n) { this->n = n; reset(); }

    void setEdge(int u, int v, int time) {
        adjList[u][v].push_back(time);
        ++indegree[v];
    }

	void reset() {
        dfs_visit = vector<int> (n, UNVISITED);
        indegree = vector<int> (n, 0);
        visited = vector<bool> (n, false);
		
		adjList = vector< vector< vector <int> > > (n,  vector< vector <int> > (n, vector <int> () ) );
    }
};

typedef pair<int, int> ii;
int minDist = INT_MAX;
int firstTime;
int origem;
int destino;
int R;


int dfs(Graph &graph, int u, int atual) {
    graph.dfs_visit[u] = VISITED;
    for (int v = 0; v < int(graph.n); v++) {
		vector<int> vetTimes = graph.adjList[u][v];	
		if (v == d) {
			minDist = min(minDist, atual - firstTime);
			break;
		} 
		if (!vetTimes.size()) continue;
	
		for (int i = 0; i < int(vetTimes.size()); ++i)
			if (atual + R <= vetTimes[i]) break;
				
		if (i == vetTimes.size()) break;
		if (u == origem) firstTime = vetTimes[i];
		
		dfs(graph, v, vetTimes[i]);
    }
	
	return minDist;
}


int main() {
	
	int cases;
	int n;
	int u, v, t;
	
	cin >> cases;
	
	while (cases--) {
		cin >> R;
		cin >> n;
		Graph graph(n);
		while (n--) {
			cin >> u >> v >> t;
			graph.setEdge(u, v, t);
		}
		
		cin >> origem >> destino;
		
		for (int i = 0 i < graph.n; ++i)
			for (int j = 0; i < graph.n; ++j)
				sort(graph.adjList[i][j].begin(), graph.adjList[i][j].end());
			
		cout << dfs(graph) << endl; 
	}
	
	return 0;
}
	
	
	