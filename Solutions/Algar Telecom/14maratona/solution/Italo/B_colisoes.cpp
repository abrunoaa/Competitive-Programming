#include <bits/stdc++.h>
using namespace std;

int main(){	
	freopen("e","r",stdin);
	int xa,ya,xb,xc,xd,yb,yc,yd,x,y;
	while(scanf(" %d %d %d %d %d %d %d %d %d %d",&xa,&ya,&xb,&yb,&xc,&yc,&xd,&yd,&x,&y) != EOF){
		if(x > xa && y > ya && x < xc && y < yc) printf("1\n");
		else printf("0\n");
	}
	return 0;
}
