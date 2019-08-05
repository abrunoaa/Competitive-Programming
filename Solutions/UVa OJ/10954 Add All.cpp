/*
 * Copyright 2017 Bruno Oliveira <abrunoaa@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#include <cstdio>
#include <map>
using namespace std;

int main() {
  register int i, j, k, n;
  unsigned long long cost;
  map<unsigned int, int> m;
  map<unsigned int, int>::iterator iter, end, del;

  while (scanf("%d", &n), n) {
    i = -1;
    cost = 0;
    while (++i < n) {
      scanf("%d", &j);
      m[j]++;
    }
    iter = m.begin();
    end = m.end();
    while (true) {
      j = iter->second;
      k = iter->first;
      if (j > 1) {
        cost += k *= 2;
        m[k]++;
        iter->second -= 2;
      } else if (j == 1) {
        del = iter++;
        if (iter == end) {
          break;
        }
        m.erase(del);
        cost += k += iter->first;
        m[k]++;
        iter->second--;
      } else {
        del = iter++;
        m.erase(del);
      }
//printf("- %llu\n", cost);
    }
    m.clear();
    printf("%lld\n", cost);
  }

  return 0;
}
