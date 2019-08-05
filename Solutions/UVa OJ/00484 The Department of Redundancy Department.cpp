#include <bits/stdc++.h>
using namespace std;

int main() {
  int v, i;
  vector<int> nums;
  map<int, int> list;

  while (scanf("%d", &v) == 1) {
    if (list.find(v) == list.end()) {
      nums.push_back(v);
    }
    ++list[v];
  }
  for (i = 0; i < (int)nums.size(); ++i) {
    printf("%d %d\n", nums[i], list[nums[i]]);
  }

  return 0;
}
