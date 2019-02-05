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


struct Point {
    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}
    double x, y;
};

/*
    Retangulo: pair<Point, Point>
        first: ponto inferior esquerdo
        second: ponto superior direito

    Retorna true se o retangulo r1 e r2 tiverem area em comum. c representa a area em comum
*/
inline bool quadrilateroIntercecao(pair<Point, Point> r1, pair<Point, Point> r2)
{
    /*
    x1 = q1.first.x
    y1 = q1.first.y
    x2 = q1.second.x
    y2 = q1.second.y
    x3 = q2.first.x
    y3 = q2.first.y
    x4 = q2.second.x
    y4 = q2.second.y
    */
    double maxX = max(r1.first.x, r2.first.x);
    double minX = min(r1.second.x, r2.second.x);
    double maxY = max(r1.first.y, r2.first.y);
    double minY = min(r1.second.y, r2.second.y);

    if (maxX >= minX || minY <= maxY)
        return false;

    //c = make_pair(Point(maxX, maxY), Point(minX, minY));
    return true;
}

int main() {

    freopen("../input.txt","r", stdin);
    freopen("../out.txt","w", stdout);

    vector< pair<Point, Point> > vetRet;
    pair<Point, Point> r;

    int n;
    cin >> n;

    while (n--) {
        cin >> r.first.x >> r.first.y >> r.second.x >> r.second.y;
        swap(r.first.y, r.second.y);
        vetRet.push_back(r);
    }


    for (int i = 0; i < int(vetRet.size()); ++i)
        for (int j = 0; j < int(vetRet.size()); ++j)
            if (i != j && quadrilateroIntercecao(vetRet[i], vetRet[j])) {
                printf("%0.lf %0.lf %0.lf %0.lf\n", vetRet[i].first.x, vetRet[i].second.y, vetRet[i].second.x, vetRet[i].first.y);
                break;
            }

    return 0;
}
