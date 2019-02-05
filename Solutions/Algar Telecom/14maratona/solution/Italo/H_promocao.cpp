#include <stdio.h>
#include <algorithm>
using namespace std;

int wt[110];
int val[110];

int knapSack(int W, int n)
{
   int i, w;
   int K[n+1][W+1];
   
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   } 
   return K[n][W];
}

int main(){
	int q,p;
	while(scanf(" %d",&q),q){
		for(int i = 0 ; i < q ; ++i){
			scanf(" %d %d",&val[i],&wt[i]);
		}
		scanf(" %d",&p);
		
		printf("%d\n",knapSack(p,q));
	}
	return 0;
}
