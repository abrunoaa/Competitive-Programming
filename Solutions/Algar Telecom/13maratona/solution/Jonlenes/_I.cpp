#include <algorithm>
#include <iostream>
#include <utility>
#include <numeric>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
#include <utility>

using namespace std;


int main() {

    //freopen("../input.txt","r", stdin);
    //freopen("../out.txt","w", stdout);

    int a, b, c, d, n;

    cin >> n;
    while (n--) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        double r = double(d - b) / (c - a);
        cout << (unsigned long long)r << ",";
        printf("%02d\n", int((r - (unsigned long long)r) * 100));
    }
}
