/*#include <bits/stdc++.h>*/
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
#include <deque>
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
//=======================


class Node {

  public:
  int data;
  Node* right;
  Node* left;
  int leftTreeCount;

  Node(int v){
    data = v;
    right = nullptr;
    left = nullptr;
    leftTreeCount = 0;
  }
};


class findKthLargest {
  int size;
  Node* root;

  findKthLargest(){
    size = 0;
    root = nullptr;
  }

  void insertHelper(Node* curr, int x){

    if(curr == nullptr){
      curr = new Node(x);
      return;
    }

    if(x < curr->data){
      curr->leftTreeCount++;
      insertHelper(curr->left, x);
    }else{
      insertHelper(curr->right, x);
    }

    return;
  }

  void insert(int x){
    size++;
    insertHelper(root, x);
  }

  int findKthElement(Node* curr, int k){

    if(k == curr->leftTreeCount){
      return curr->data;
    } else if(k < curr->leftTreeCount){ // lies in left subtree
      findKthElement(curr->left, k);
    }else{
      // go to right, this is tricky. deduct size of left tree and then continue.
      findKthElement(curr->right, k - curr->leftTreeCount -1);
    }
  }

  int findLargest(int k){
    if(k > size || k<0) return -1;

    int ans = findKthElement(root, size-k);
    return ans;
  }

};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) {
  }
  return 0;
}

//=======================
