#include <bits/stdc++.h>
using namespace std;

// Dijkstra 'Shunting yard'
// O(n)
string inToPost (string infix)
{
  vector<char> op;
  string postfix;

  for (int i = 0; i < (int)infix.size(); ++i)
  {
    char &c = infix[i];

    if (isdigit(c))
      postfix.push_back(c);
    else if (c == '(')
      op.push_back(c);
    else if (c == ')')
    {
      while (op.back() != '(')
        postfix.push_back(op.back()), op.pop_back();
      op.pop_back();
    }
    else
    {
      if (c == '*' || c == '/')
        while (!op.empty() && op.back() != '(' && op.back() != '+' && op.back() != '-')
          postfix.push_back(op.back()), op.pop_back();
      else
        while (!op.empty() && op.back() != '(')
          postfix.push_back(op.back()), op.pop_back();
      op.push_back(c);
    }
  }
  while (!op.empty())
    postfix.push_back(op.back()), op.pop_back();

  return postfix;
}

int main()
{
  char c;
  int t;
  string eq;

  scanf("%d", &t);
  while (t--)
  {
    scanf(" ");
    eq.clear();

    while (scanf("%c%*1[ \n]", &c) == 1 && c != '\n')
      eq.push_back(c);

    printf("%s\n", inToPost(eq).data());
    if (t) puts("");
  }

  return 0;
}
