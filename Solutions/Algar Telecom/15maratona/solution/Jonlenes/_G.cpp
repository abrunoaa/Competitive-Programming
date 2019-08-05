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
#include <sstream>

using namespace std;


inline bool isPalindromo(string s) {
  if (s.empty()) { return false; }

  int size = s.size();
  for (int i = 0; i < size / 2; ++i)
    if (s[i] != s[size - i - 1]) {
      return false;
    }

  return true;
}

int main() {

  freopen("../input.txt", "r", stdin);
  freopen("../out.txt", "w", stdout);

  int v1, v2, i, n ;
  string s;
  stringstream ss;
  long long soma, qtde;

  cin >> n;
  while (n--) {
    cin >> v1 >> v2;

    soma = qtde = 0;
    for (i = v1; i <= v2; ++i) {
      ss << i;

      if (isPalindromo( ss.str() )) {

        bitset<20> b(i);
        s = b.to_string();
        int idx = s.find_first_of('1');

        if (idx != int(string::npos) && isPalindromo(s.substr(idx, s.size() - idx))) {
          soma += i;
          qtde++;
        }
      }
      ss.str("");
    }

    cout << soma << " " << qtde << endl;
  }

  return 0;
}
