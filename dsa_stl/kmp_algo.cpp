/*#include <bits/stdc++.h>*/
#include <climits>
#include <iostream>
#include <unordered_map>
#ifndef _GLIBCXX_NO_ASSERT
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>
#endif
using namespace std;

#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))

#define display(A)                                                             \
  for (auto &aa : A)                                                           \
    cout << aa << ' ';                                                         \
  cout << endl;

#define read(A)                                                                \
  for (auto &aa : A) {                                                         \
    cin >> aa;                                                                 \
  }
//===========================
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
//=======================
//
const int MOD = 1000000007;
const int N = 1000007, M = N;
//=======================
//
//
// KMP Algorithm : O(n)
// With the help of LPS (Longest prefix suffx)
// LPS[i] = the length of the longest proper prefix of s[0..i] which is also a
// suffix of s[0..i]
// Index:      0   1   2   3   4   5   6   7   8
// Char:       A   B   A   B   C   A   B   A   B
// LPS Value:  0   0   1   2   0   1   2   3   4
//
// best explained in this : https://www.youtube.com/watch?v=q4_90fOoS-s
// TC: O(N+M)
// SC: O(N)
// Hard to remember and implement in interview 
vector<int> computeLPSArray(const string& pattern) {
    int M = pattern.length();
    vector<int> lps(M, 0);
    
    int len = 0; // Length of the previous longest prefix suffix
    int i = 1;

    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                // Fallback to the previous longest prefix suffix
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  /*cin >> t;*/
  while (t--) {
  }
  return 0;
}
