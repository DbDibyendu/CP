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

using namespace std;
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define display(A)                                                             \
  for (auto &aa : A)                                                           \
    cout << aa << ' ';                                                         \
  cout << endl;
#define displayP(A)                                                            \
  for (auto &aa : A) {                                                         \
    display(aa);                                                               \
  }
#define read(A)                                                                \
  for (auto &aa : A) {                                                         \
    cin >> aa;                                                                 \
  }
//===========================
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
//=======================
const int MOD = 1'000'000'007;
const int N = INT_MAX, M = N;
//=======================

// class Node
// {
// public:
//     int data;
//     Node *link;
// };
//! OR
struct Node {
  int data;
  Node *link;
};

//! Printing the linked list
void PrintList(Node *p) {
  while (p != NULL) {
    cout << p->data << " ";
    p = p->link;
  }
  cout << endl;
}

//! Code to reverse a linked list
void ReverseList(Node *head) {
  Node *prev, *current, *next;
  int t = 0;
  current = head;
  prev = NULL;
  while (current != NULL) {
    deb(current->data);
    next = current->link; // store next
    current->link = prev; // reverse link
    prev = current;       // update prev
    current = next;       // update current
  }

  head = prev;
  PrintList(head);
}

void solve() {

  ll i, j, n, m, k;
  ll temp = 0, flag = 1;
  cin >> n;

  //! Reading the Linked list
  Node *head, *prev, *el;
  head = NULL;
  int t;
  while (n--) {
    el = new Node();
    cin >> t;
    el->data = t;

    if (head == NULL) {
      head = el;
    } else {
      prev->link = el;
    }
    prev = el;
  }

  Node *p = head;
  while (p->data != 4) {
    // cout << p->data << " ";
    p = p->link;
  }
  //! Adding a new element, in between

  Node *p_new = new Node();

  p_new->link = p->link;
  p_new->data = 6;
  p->link = p_new;

  ReverseList(head);
  // PrintList(head);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

//=======================
