#include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second

typedef pair<int,int> ii;
typedef pair<ii,int> iii;

struct cmp
{ bool operator () (iii i1, iii i2) { return !(i1.fst.fst < i2.fst.fst || (i1.fst.fst == i2.fst.fst && (i1.fst.snd > i2.fst.snd || (i1.fst.snd == i2.fst.snd && i1.snd < i2.snd)))); } };

int n, m, t, p, pos;
bitset<100100> acima;
vector<ii> pontos;
priority_queue<iii,vector<iii>,cmp> pq;

bool menor (ii i1, ii i2) { return i1.fst < i2.fst || (i1.fst == i2.fst && i1.snd > i2.snd); }

int main()
{
  //~ freopen("gin", "r", stdin);

  scanf("%d%d", &n, &m);
  pos = 1;
  pontos.assign(n + 5, ii(0,0));
  acima.reset();

  while (m--)
  {
    scanf("%d%d", &t, &p);

    ++pontos[t].fst;
    pontos[t].snd += p;

    if (t != 1)
    {
      if (menor(pontos[1], pontos[t]))
      {
        if (!acima[t])
        {
          acima[t] = 1;
          ++pos;
        }
        pq.push(iii(pontos[t], t));
      }
    }
    else
    {
      //~ cerr << " >> " << pq.top().fst.fst << " " << pq.top().fst.snd << " " << pq.top().snd << endl;
      while (!pq.empty() && !menor(pontos[1], pq.top().fst))
      {
        if (pq.top().fst == pontos[pq.top().snd]) --pos, acima[pq.top().snd] = 0;
        pq.pop();
      }
    }

    printf("%d\n", pos);
  }

  return 0;
}
