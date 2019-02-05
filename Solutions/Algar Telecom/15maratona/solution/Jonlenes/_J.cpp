#include <bits/stdc++.h>

using namespace std;


int main() {

    freopen("../input.txt","r", stdin);
    freopen("../out.txt","w", stdout);

    double v;
    int n;

    cin >> n;
    while (n--) {
        scanf("%lf", &v);
        printf("%.2lf ", trunc(v * 100) / 100.0);
        v += v/2;
        printf("%.2lf ", trunc(v * 100) / 100.0);
        v -= v/4;
        printf("%.2lf ", trunc(v * 100) / 100.0);
        v += v/2;
        printf("%.2lf ", trunc(v * 100) / 100.0);
        v -= v/4;
        printf("%.2lf \n", trunc(v * 100) / 100.0);
    }
}
