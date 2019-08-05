#include <cstdio>

char m[205][205];
int h, w, img;

void col1(int i, int j) {
  m[i][j] = -1;
  if (i + 1 < h  && !m[i + 1][j]) { col1(i + 1, j); }
  if (i - 1 >= 0 && !m[i - 1][j]) { col1(i - 1, j); }
  if (j + 1 < w  && !m[i][j + 1]) { col1(i, j + 1); }
  if (j - 1 >= 0 && !m[i][j - 1]) { col1(i, j - 1); }
}

void col2(int i, int j) {
  m[i][j] = -1;
  if (i + 1 < h) {
    if (m[i + 1][j] > 0) {
      col2(i + 1, j);
    } else if (!m[i + 1][j]) {
      img++, col1(i + 1, j);
    }
  }
  if (i - 1 >= 0) {
    if (m[i - 1][j] > 0) {
      col2(i - 1, j);
    } else if (!m[i - 1][j]) {
      img++, col1(i - 1, j);
    }
  }
  if (j + 1 < w) {
    if (m[i][j + 1] > 0) {
      col2(i, j + 1);
    } else if (!m[i][j + 1]) {
      img++, col1(i, j + 1);
    }
  }
  if (j - 1 >= 0) {
    if (m[i][j - 1] > 0) {
      col2(i, j - 1);
    } else if (!m[i][j - 1]) {
      img++, col1(i, j - 1);
    }
  }
}

int main() {
  register int i, j, k;
  int hie[10], d, count = 0;

  while (scanf("%d%d", &h, &w), h || w) {
    for (i = -1; ++i < h; )
      for (j = k = -1; ++j < w; ) {
        scanf("%1x", &d);
        m[i][++k] = d & 8;
        m[i][++k] = d & 4;
        m[i][++k] = d & 2;
        m[i][++k] = d & 1;
      }
    w *= 4;
    /*
    for (i = 0; i < h; i++)
    {
      for (j = 0; j < w; j++)
        printf("%d", m[i][j]);
      printf("\n");
    }
    //*/
    for (i = h; i--; )
      if (!m[i][0]) {
        col1(i, 0);
      }
    for (j = w; j--; )
      if (!m[0][j]) {
        col1(0, j);
      }
    for (i = h, j = w - 1; i--; )
      if (!m[i][j]) {
        col1(i, j);
      }
    for (i = h - 1, j = w; j--; )
      if (!m[i][j]) {
        col1(i, j);
      }
    /*
    for (i = 0; i < h; i++)
    {
      for (j = 0; j < w; j++)
        printf("%d", m[i][j] < 0 ? 9 : m[i][j]);
      printf("\n");
    }
    //*/
    for (i = 6; i--; hie[i] = 0);
    for (i = h; i--; )
      for (j = w; j--; )
        if (m[i][j] > 0) {
          img = 0;
          col2(i, j);
          hie[img]++;
//printf(" ! %d %d %d\n", i, j, img);
        }
    printf("Case %d: ", ++count);
    for (i = hie[1]; i--; printf("A"));
    for (i = hie[5]; i--; printf("D"));
    for (i = hie[3]; i--; printf("J"));
    for (i = hie[2]; i--; printf("K"));
    for (i = hie[4]; i--; printf("S"));
    for (i = hie[0]; i--; printf("W"));
    printf("\n");
  }

  return 0;
}
