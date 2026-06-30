

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

const int N = 1e6 + 100, M = N;
//=======================


// binary search + greedy approach
    vector<int> buildPackets(
        int dataLength,
        vector<int>& splitPositions,
        int capacity
    ) {
        vector<int> points;
        points.push_back(0);

        for (int p : splitPositions)
            points.push_back(p);

        points.push_back(dataLength);

        vector<int> packets;

        int n = points.size();
        int curr = 0; // current packet start index

        while (curr < n - 1) {

            int next = curr;

            // Find farthest reachable split point.
            while (
                next + 1 < n &&
                points[next + 1] - points[curr] <= capacity
            ) {
                next++;
            }

            // Couldn't move at all => impossible.
            if (next == curr)
                return {};

            packets.push_back(
                points[next] - points[curr]
            );

            curr = next;
        }

        return packets;
    }

    vector<int> SplitData(
        int dataLength,
        vector<int>& splitPositions,
        int maxPacketSize
    ) {
        // Minimum packet count achievable
        vector<int> initial =
            buildPackets(
                dataLength,
                splitPositions,
                maxPacketSize
            );

        if (initial.empty())
            return {};

        int minPackets = initial.size();

        int low = 1;
        int high = maxPacketSize;
        int bestCapacity = maxPacketSize;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            vector<int> candidate =
                buildPackets(
                    dataLength,
                    splitPositions,
                    mid
                );

            if (
                !candidate.empty() &&
                candidate.size() == minPackets
            ) {
                bestCapacity = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return buildPackets(
            dataLength,
            splitPositions,
            bestCapacity
        );
    };



// DP Approach

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
