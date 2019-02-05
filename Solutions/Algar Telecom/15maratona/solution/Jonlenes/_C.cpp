#include <iostream>
#include <algorithm> // std::swap(), std::sort(), std::stable_sort(), std::binary_search(),..
#include <iostream>  // std::cout, std::cin, std::cin.getline(), std::cin.ignore(),..
#include <utility>   // std::pair, std::make_pair(), std::swap(),..
#include <numeric>   // std::accumulate(), std::partial_sum(), std::adjacent_difference(),..
#include <stack>     // std::stack
#include <queue>     // std::queue, std::priority_queue
#include <list>      // std::list
#include <map>       // std::map, std::multimap
#include <set>       // std::set, std::multiset
#include <vector>    // std::vector
#include <string>    // std::string
#include <bitset>    // std::bitset
#include <cstdlib>   // qsort(), bsearch(), srand(), rand(), atoi(), atof(),..
#include <cstring>   // memset(), memcpy(), memmove(), strlen(), strcmp(), strcpy(),..
#include <cctype>    // tolower(), toupper(),..
#include <cstdio>    // printf(), scanf(), putchar(), getchar(), puts(), gets(),..
#include <cmath>     // sqrt(), pow(), ceil(), floor(), abs(), fabs(), exp(), log(), cos(), sin(),..
#include <ctime>     // time_t, time(),..
#include <climits>

using namespace std;

const double EPS = 1e-10;

struct Point {
    double x, y, z;

    Point() { x = y = 0; }
    Point(double _x, double _y) : x(_x), y(_y) {}
};


//Calcula a distancia entre dois pontos
double dist(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

//Vetor matematico
struct Vetor {
    double x, y;

    Vetor() : x(0), y(0) {}
    Vetor(double _x, double _y) : x(_x), y(_y) { }
    Vetor(Point p) : x(p.x), y(p.y) { }

    Point toPoint() { return Point(x, y); }
};

//Converte dois pontos para vetor
Vetor toVetor(Point a, Point b) {
    return Vetor(b.x - a.x, b.y - a.y);
}

//Produto misto entre os vetores, retorna a area do paralelogramo formado por a e b
double cross(Vetor a, Vetor b) {
    return a.x * b.y - a.y * b.x;
}

//Retorna true se o ponto r estiver na mesma linha que pq
bool collinear(Point p, Point q, Point r) {
    return fabs(cross(toVetor(p, q), toVetor(p, r))) < EPS;
}

Point pivot(0, 0);
//Ordenação por angulo
bool angleCmp(Point a, Point b) { // angle-sorting function
    if (collinear(pivot, a, b)) // special case
        return dist(pivot, a) < dist(pivot, b); // check which one is closer
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
} // compare two angles



int main() {

    freopen("input/file1", "r", stdin);
    freopen("out", "w", stdout);

    int d, o;
    int i, j;
    Point p;

    while (cin >> d >> o && d && o) {

        vector<Point> vetD;
        while (d--) {
            cin >> p.x >> p.y;
            vetD.push_back(p);
        }

        vector<Point> vetO;
        while (o--) {
            cin >> p.x >> p.y;
            vetO.push_back(p);
        }

        //sort(vetD.begin(), vetD.end(), angleCmp);
        sort(vetO.begin(), vetO.end(), angleCmp);

        for (i = 0; i < int(vetD.size()); ++i) {
            bool obstaculos = false;
            for (j = 0; j < int(vetD.size()); ++j) {
                if (angleCmp(vetO[j], vetD[i])){
                    if (collinear(pivot, vetD[i], vetO[j])) {
                        obstaculos = true;
                        break;
                    }
                }
                else
					break;
            }

            if (!obstaculos)
				printf("%.0lf %.0lf\n", vetD[i].x, vetD[i].y);
        }

    }

    return 0;
}




















