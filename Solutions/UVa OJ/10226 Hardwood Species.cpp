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
  register int test, tot;
  char str[31];
  map<string, int> m;
  typename map<string, int>::iterator iter, end;

  scanf("%d%*[\n]", &test);
  while (test--) {
    tot = 0;
    *str = 0;
    while (scanf("%1[\n]", str), *str != '\n') {
      scanf("%[^\n]%*c", str);
      m[str]++;
      tot++;
    }

    iter = m.begin();
    end = m.end();
    while (iter != end) {
      printf("%s %.4lf\n", iter->first.data(), (double)iter->second / tot * 100);
      iter++;
    }

    printf("\n\n");

    m.clear();
  }

  return 0;
}

