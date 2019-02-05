#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
long long mat[N][N];

const long long LIM = 1000000007;

long long getCount(int b, int g) {
    if (g <= 0) return 0;
    if (b == 1) return g == 1;

    if (mat[b][g] == -1)
        mat[b][g] = ((g * getCount(b - 1, g)) % LIM + (g * getCount(b - 1, g - 1)) % LIM) % LIM;

    return mat[b][g];
}

int main() {

    //freopen("../input.txt","r", stdin);
    //freopen("../out.txt","w", stdout);

    memset(mat, -1, sizeof mat);

    int b, g;

    while (cin >> b >> g && b && g) {
        cout << getCount(b, g) << endl;
    }

    return 0;
}
