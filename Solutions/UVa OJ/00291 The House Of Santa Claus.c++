#include <bits/stdc++.h>
using namespace std;

char adj[5][5] = {{ 0, 1, 1, 0, 1},
                  { 1, 0, 1, 0, 1},
                  { 1, 1, 0, 1, 1},
                  { 0, 0, 1, 0, 1},
                  { 1, 1, 1, 1, 0}};

vector < int > way;

void busca (int u)
{
  if (way.size() == 9)
  {
    for (int i = 0; i < 9; ++i)
      printf("%d", way[i]);
    printf("\n");
    return;
  }

  for (int i = 0; i < 5; ++i)
    if (adj[u][i])
    {
      way.push_back(i + 1);
      adj[u][i] = 0;
      adj[i][u] = 0;
      busca(i);
      adj[u][i] = 1;
      adj[i][u] = 1;
      way.pop_back();
    }
}

int main()
{
  way.push_back(1);
  busca(0);
  return 0;
}
