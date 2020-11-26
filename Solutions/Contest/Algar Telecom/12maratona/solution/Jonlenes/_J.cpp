
#include <iostream>
using namespace std;


int main() {

  //freopen("../input.txt","r", stdin);
  //freopen("../out.txt","w", stdout);

  int n, a, b;

  cin >> n;

  while (n--) {

    cin >> a >> b;
    cout << int(((a + b) * (b - a + 1)) / 2) << endl;

  }

  return 0;
}
