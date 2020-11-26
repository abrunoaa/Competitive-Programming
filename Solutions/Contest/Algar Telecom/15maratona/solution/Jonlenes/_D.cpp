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

int main() {

  //freopen("../input.txt", "r", stdin);
  //freopen("../out.txt", "w", stdout);

  int n;
  int v1, v2, m, t;

  while (cin >> n && n) {
    cin >> v1;
    m = v2 = v1;
    n--;
    t = 0;
    while (n--) {
      cin >> v2;
      if (v2 - m > 10) { t += v2 - m - 10; }
      m = v2;
    }
    printf("%d\n", v2 + 10 - v1 - t);
  }

  return 0;
}
