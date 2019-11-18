#include <bits/stdc++.h>
using namespace std;

char mask[] = { (char)0x80, (char)0x40, (char)0x20, (char)0x10, (char)0x08, (char)0x04, (char)0x02, (char)0x01 };
#define chr(i) (cs==sizeof(int)?((int *)s)[i]:((char *)s)[i])
#define isLMS(i) (i>0 && t[i] && !t[i - 1])

// find the start or end of each bucket
void getBuckets(char *s, vector<int>& bkt, int n, int k, int cs, bool end) {
    for (int i = 0; i <= k; i++) bkt[i] = 0; // clear all buckets
    for (int i = 0; i < n; i++) ++bkt[chr(i)]; // compute the size of each bucket
    for (int i = 0, sum = 0; i <= k; i++) {
        sum += bkt[i];
        bkt[i] = end ? sum : sum - bkt[i];
    }
}
// compute SAl
void induceSAl(vector<bool>& t, int *p, char *s, vector<int>& bkt, int n, int k, int cs) {
    getBuckets(s, bkt, n, k, cs, false); // find starts of buckets
    for (int i = 0; i < n; i++) {
        int j = p[i] - 1;
        if (j >= 0 && !t[j])
            p[bkt[chr(j)]++] = j;
    }
}
// compute SAs
void induceSAs(vector<bool>& t, int *p, char *s, vector<int>& bkt, int n, int k, int cs) {
    getBuckets(s, bkt, n, k, cs, true); // find ends of buckets
    for (int i = n - 1; i >= 0; i--) {
        int j = p[i] - 1;
        if (j >= 0 && t[j])
            p[--bkt[chr(j)]] = j;
    }
}

// find the suffix array p of s[0..n-1] in {1..k}^n
// require s[n-1]=0 (the sentinel!), n>=2
// use a working space (excluding s and p) of at most 2.25n+O(1) for a constant alphabet
void SA_IS(char *s, int *p, int n, int k, int cs) {
    int i, j;
    vector<bool> t(n);
    // Classify the type of each character
    t[n - 2] = 0;
    t[n - 1] = 1;// the sentinel must be in s1, important!!!
    for (i = n - 3; i >= 0; i--)
      t[i] = chr(i)<chr(i+1) || (chr(i)==chr(i+1) && t[i + 1]);

    // stage 1: reduce the problem by at least 1/2
    // sort all the S-substrings
    // int *bkt = (int *) malloc(sizeof(int) * (k + 1)); // bucket array
    vector<int> bkt(k + 1);
    getBuckets(s, bkt, n, k, cs, true); // find ends of buckets
    for (i = 0; i < n; i++)
        p[i] = -1;
    for (i = 1; i < n; i++)
        if (t[i] && !t[i - 1])
            p[--bkt[chr(i)]] = i;
    induceSAl(t, p, s, bkt, n, k, cs);
    induceSAs(t, p, s, bkt, n, k, cs);
    // compact all the sorted substrings into the first n1 items of p
    // 2*n1 must be not larger than n (proveable)
    int n1 = 0;
    for (i = 0; i < n; i++)
        if (p[i]>0 && t[p[i]] && !t[p[i] - 1])
            p[n1++] = p[i];
    // find the lexicographic names of all substrings
    for (i = n1; i < n; i++) p[i] = -1; // init the name array buffer
    int name = 0, prev = -1;
    for (i = 0; i < n1; i++) {
        int pos = p[i];
        bool diff = false;
        for (int d = 0; d < n; d++)
            if (prev == -1 || chr(pos+d) != chr(prev+d) || t[pos+d] != t[prev+d]) {
                diff = true;
                break;
            } else if (d > 0 && (isLMS(pos+d) || isLMS(prev+d)))
                break;
        if (diff) {
            name++;
            prev = pos;
        }
        pos /= 2;
        p[n1 + pos] = name - 1;
    }
    for (i = n - 1, j = n - 1; i >= n1; i--)
        if (p[i] >= 0)
            p[j--] = p[i];

    // stage 2: solve the reduced problem
    // recurse if names are not yet unique
    int *s1 = p + n - n1;
    if (name < n1)
        SA_IS((char*) s1, p, n1, name - 1, sizeof(int));
    else
        // generate the suffix array of s1 directly
        for (i = 0; i < n1; i++)
            p[s1[i]] = i;

    // stage 3: induce the result for the original problem
    // put all left-most S characters into their buckets
    getBuckets(s, bkt, n, k, cs, true); // find ends of buckets
    for (i = 1, j = 0; i < n; i++)
        if (isLMS(i))
            s1[j++] = i; // get p1
    for (i = 0; i < n1; i++)
        p[i] = s1[p[i]]; // get index in s
    for (i = n1; i < n; i++)
        p[i] = -1; // init p[n1..n-1]
    for (i = n1 - 1; i >= 0; i--) {
        j = p[i];
        p[i] = -1;
        p[--bkt[chr(j)]] = j;
    }
    induceSAl(t, p, s, bkt, n, k, cs);
    induceSAs(t, p, s, bkt, n, k, cs);
}

// const int mas
// int lcp[maxn];
// int rnk[maxn];
// char *s;
// int n;

// void calc_lcp() {
    // for (int i = 0; i < n; i++)
        // rnk[p[i]] = i;
    // for (int i = 0, h = 0; i < n; i++) {
        // if (rnk[i] < n - 1) {
            // for (int j = p[rnk[i] + 1]; s[i + h] == s[j + h]; ++h)
                // ;
            // lcp[rnk[i]] = h;
            // if (h > 0)
                // --h;
        // }
    // }
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
  string s(10000, 'a');
  for (char &c : s) c = (char)(rand() % 26 + 'a');
  s += s;
  map<char, int> mp;
  for (char c : s) mp[c];
  int k = 0;
  for (auto& p : mp) p.second = ++k;
  vector<int> sm;
  for (char c : s) sm.push_back(mp[c]);
  sm.push_back(0);
  vector<int> p(s.size() + 1);
  SA_IS(s.data(), (int*)p.data(), (int)s.size() + 1, 256, 1);
  for (int i = 1; i < (int)s.size(); ++i) {
    assert(s.substr(p[i - 1]) < s.substr(p[i]));
  }
  return 0;
}
