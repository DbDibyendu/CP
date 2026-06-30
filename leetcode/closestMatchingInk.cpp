



#include <fstream>
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

vl ans;



// dikjstra solve
// R*G*B colours, M inks


unordered_map<int,
    unordered_map<int,
        unordered_map<int, vector<int>>>> mp;

bool checkBoundaries(vector<int>& c) {
    return c[0] >= 0 && c[0] < 256 &&
           c[1] >= 0 && c[1] < 256 &&
           c[2] >= 0 && c[2] < 256;
}

// dijkstra code
void bfs(vector<vector<int>>& inks) {

    // dist, color, sourceInk
    priority_queue<
        tuple<int, vector<int>, vector<int>>
    > pq;

    for (auto& ink : inks) {
        pq.push({0, ink, ink});
    }

    vector<int> dr = {1, 0, 0, -1, 0, 0};
    vector<int> dg = {0, 1, 0, 0, -1, 0};
    vector<int> db = {0, 0, 1, 0, 0, -1};

    while (!pq.empty()) {

        auto [dist, oldColor, ink] = pq.top();
        pq.pop();

        dist = -dist;

        int r = oldColor[0];
        int g = oldColor[1];
        int b = oldColor[2];

        // already assigned
        if (mp[r][g].count(b))
            continue;

        // first arrival wins
        mp[r][g][b] = ink;

        for (int i = 0; i < 6; i++) {

            vector<int> newColor = {
                oldColor[0] + dr[i],
                oldColor[1] + dg[i],
                oldColor[2] + db[i]
            };

            if (!checkBoundaries(newColor))
                continue;

            pq.push({
                -(dist + 1),
                newColor,
                ink
            });
        }
    }
}


vector<int> closestMatchingInk(vector<vector<int>> colours, vector<vector<int>> inks){

  // O(M*N)
  // (r1-x) + (r2-x) + (r3-x)
}
// Approach 1: dijkstra based solution is good
// But memory will still be O(256*256*256) and time complexity would be O(rgb)log(rgb) compared to O(RGB)*M 
// in brute force
// Approach 2: Downscale the dimensions -> Bucketing
// Scale down 256-> 16, and it can act as source of truth. But for precision, also query neighbouring buckets. 
// And calculate actual ink.
//
// Downscale code

vector<vector<int>> inks;
int n;

const int BUCKET_SIZE = 16;
const int NUM_BUCKETS = 16;


// dp[rBucket][gBucket][bBucket]
// stores nearest ink index
int dp[16][16][16];

long long colourDiff(
    const vector<int>& c1,
    const vector<int>& c2
) {
    long long dr = c1[0] - c2[0];
    long long dg = c1[1] - c2[1];
    long long db = c1[2] - c2[2];

    return dr * dr + dg * dg + db * db;
}

int nearest(int rBucket, int gBucket, int bBucket) {

    // Use bucket center as representative color
    vector<int> bucketColor = {
        rBucket * 16 + 8,
        gBucket * 16 + 8,
        bBucket * 16 + 8
    };

    int closestInk = -1;
    long long bestDist = LLONG_MAX;

    for (int i = 0; i < inks.size(); i++) {

        long long dist =
            colourDiff(bucketColor, inks[i]);

        if (dist < bestDist) {
            bestDist = dist;
            closestInk = i;
        }
    }

    return closestInk;
}

void buildDownscaleCache(
    const vector<vector<int>>& availableInks
) {

    inks = availableInks;

    for (int r = 0; r < 16; r++) {
        for (int g = 0; g < 16; g++) {
            for (int b = 0; b < 16; b++) {

                dp[r][g][b] = nearest(r, g, b);
            }
        }
    }
}

int query(int r, int g, int b) {

    int rb = r / 16;
    int gb = g / 16;
    int bb = b / 16;

    return dp[rb][gb][bb];
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
