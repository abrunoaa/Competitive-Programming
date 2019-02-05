#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int dx[] = {1, 0, -1,  0};
int dy[] = {0, 1,  0, -1};


vector< string > map;
vector < vector<bool> > matVisit;
vector< pair<long long, int> > vetD;
vector<int> descoberto;
string s;
int n, m;


void bfs(int x, int y, int count) {

    queue< pair<int, int>  > q;

    q.push( make_pair(x, y) );
    matVisit[x][y] = true;
    vetD[ x * n + y ] = make_pair(0, -1);
    descoberto[ x * n + y ] = count;

    while (!q.empty()) {
        pair<int, int> u = q.front(); q.pop();
        
		for (int i = 0; i < 4; ++i) {
			int xx = u.first + dx[i];
			int yy = u.second + dy[i];

			if (xx < 0 || yy < 0 || xx >= int(map.size()) || yy >= int(map[0].size()) || matVisit[xx][yy])
				continue;
			
			if (map[xx][yy] != '#') {
				matVisit[xx][yy] = true;
                descoberto[ xx * n + yy ] = count;
				q.push( make_pair(xx, yy) );
                vetD[ xx * n + yy ] = make_pair(vetD[ u.first * n + u.second ].first + 1, u.first * n + u.second);
			}
		}
    }
}


int main() {

    freopen("../input.txt","r", stdin);
    freopen("../out.txt","w", stdout);

    while (scanf(" %d %d ", &n, &m) == 2 && m && n) {

        map.clear();
		matVisit.assign(n, vector<bool> (m, false));
        vetD.assign(n * m, make_pair(0, -1));
        descoberto.assign(n * m, -1);

        for (int i = 0; i < n; ++i) {
            cin >> s;
            map.push_back(s);
        }

        int count = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (!matVisit[i][j] && map[i][j] != '#')
                    bfs(i, j, count++);
		
        //sort(vetD.begin(), vetD.end());

        /*for (auto i : vetD) {
            cout << "(" << i.first << ", " << i.second << ") " << endl;;
        }
        cout << endl;*/


		long long maxD = 0;
		
        for (int i = vetD.size() - 1; i >= 0; --i) {
			
            if (!vetD[i].first) continue;
            maxD = max(maxD, vetD[i].first);
			
            for (int j = i - 1; j >= 0; --j) {
				
                if ((vetD[i].first + vetD[j].first) <= maxD
                        || vetD[i].first < vetD[j].first
                        || descoberto[i] != descoberto[j])
                    continue;

                //cout << "i: " << vetD[i].first << "\tj: " << vetD[j].first;
				
				int d = vetD[i].first - vetD[j].first;
				int dad = vetD[i].second;
                for (int k = 0; k < d; ++k) {
					dad = vetD[dad].second;
					if (dad == -1) break;
				}

                //cout << "\tDad: " << dad << endl;
				
                if (vetD[j].second != dad) {
                    //cout << "\nentrou\n";

                    int dadi = dad;
                    int dadj = vetD[j].second;
                    while (dadi != dadj) {
                        if (dadi == -1 || dadj == -1)
                            break;
                        dadi = vetD[ dadi ].second;
                        dadj = vetD[ dadj ].second;

                        //cout << "aqui\n";

                    }
                    if (dadi == -1 || dadj == -1)
                        continue;

                    //cout << vetD[i].first << "\t" << vetD[j].first << "\t"  << dadi << "\t r = " << vetD[i].first + vetD[j].first - 2 * vetD[dadi].first + 1 << endl;

                    maxD = max(maxD, vetD[i].first + vetD[j].first - 2 * vetD[dadi].first);
                    //break;
                }
			}
		}
		
		
		cout << maxD << endl;
    }

    return 0;
}
