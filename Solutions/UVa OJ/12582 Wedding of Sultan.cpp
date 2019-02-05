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
#include <stack>
using namespace std;

int main()
{
  char l, topo;
  register unsigned int i, count = 0;
  unsigned int teste, qtd[30];
  stack<char> p;

  scanf("%d%*c", &teste);
  while (teste--)
  {
    i = -1;
    while (++i < 30)
      qtd[i] = 0;

    scanf("%c", &l);
    p.push(l -65);
    while (scanf("%1[\nA-Z]s", &l), l != '\n')
    {
      l -= 65;
      if (!p.empty() && l == (topo = p.top()))
        p.pop();
      else
      {
        qtd[(int)l]++;
        qtd[(int)topo]++;
        p.push(l);
      }
    }

    printf("Case %d\n", ++count);
    for (i = -1; ++i < 26; )
      if (qtd[i])
        printf("%c = %u\n", i +65, qtd[i]);
  }

  return 0;
}
