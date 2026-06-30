

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



int getTheta(int x, int y){
  return atan2(x, y);
}

// Helper function to calculate the cyclic angular distance between two angles in radians
double getAngularDistance(double alpha, double beta) {
    double diff = abs(alpha - beta);
    return min(diff, 2 * M_PI - diff);
}

vector<int> solve(vector<int> query, vector<vector<int>>& nums, int K) {
    int n = nums.size();
    if (K <= 0 || n == 0) return {};
    if (K > n) K = n;

    // Step 1: Pre-compute angles for all document embeddings
    // pair<double, int> stores {angle_in_radians, original_index}
    vector<pair<double, int>> docs(n);
    for (int i = 0; i < n; ++i) {
        docs[i] = {atan2(nums[i][1], nums[i][0]), i};
    }

    // Step 2: Sort by angle
    sort(docs.begin(), docs.end());

    // Step 3: Compute query angle
    double qAngle = atan2(query[1], query[0]);

    // Step 4: Binary Search in your exact requested format
    int l = 0, r = n - 1, mid = 0;
    int bsAns = 0; 
    
    while (l <= r) {
        mid = (l + r) / 2;
        if (docs[mid].first <= qAngle) {
            bsAns = mid;   // Record the best element seen below or equal to qAngle
            l = mid + 1;   // Search the right half
        } else {
            r = mid - 1;   // Search the left half
        }
    }

    // Post-BS Correction: Check if the element right next to bsAns is actually a closer absolute match 
    // due to floating-point values or cyclic boundaries.
    int closestIdx = bsAns;
    if (bsAns + 1 < n && getAngularDistance(docs[bsAns + 1].first, qAngle) < getAngularDistance(docs[bsAns].first, qAngle)) {
        closestIdx = bsAns + 1;
    }

    // Step 5: Two-pointer expansion over a cyclic array framework
    vector<int> result;
    result.push_back(docs[closestIdx].second);
    K--;

    int leftPtr = (closestIdx - 1 + n) % n;
    int rightPtr = (closestIdx + 1) % n;

    while (K > 0) {
        double distL = getAngularDistance(docs[leftPtr].first, qAngle);
        double distR = getAngularDistance(docs[rightPtr].first, qAngle);

        if (distL <= distR) {
            result.push_back(docs[leftPtr].second);
            leftPtr = (leftPtr - 1 + n) % n;  // is important, rather than manually doing shifting
        } else {
            result.push_back(docs[rightPtr].second);
            rightPtr = (rightPtr + 1) % n;     
        }
        K--;
    }

    return result;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) {
    // solve();
  }
  return 0;
}

//=======================
