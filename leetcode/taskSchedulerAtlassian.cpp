// Task Scheduler — 20 min LLD
//
// Design an in-memory Task Scheduler.
//
// Requirements
// schedule(taskId, executeAt, task)
// Schedule a task to execute at a given time.
// cancel(taskId)
// Cancel a scheduled task.
// Tasks should execute in order of their scheduled time.
// Support multiple worker threads to execute tasks concurrently.
// If no task is ready, workers should wait efficiently rather than continuously polling.
// Thread-safe APIs.
// Example
// schedule("T1", 10:05, task1)
// schedule("T2", 10:02, task2)
// schedule("T3", 10:07, task3)
//
// 10:02 → T2
// 10:05 → T1
// 10:07 → T3
// Expected core design
// TaskScheduler
//     |
//     +-- PriorityQueue<Task>
//     |
//     +-- Worker Threads
//
// The key interview discussion should be:
//
// Why PriorityQueue / min-heap?
// How do workers wait until the next task is ready?
// What happens when a new task is inserted that has an earlier execution time?
// How do you handle cancellation?
// How do you make schedule() and cancel() thread-safe?
//
// Don't add retries, recurring tasks, persistence, Kafka, distributed scheduling, etc. for a 20-minute round. Those are scope-creep traps.


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
const int N = 3000007, M = N;
//=======================
//
//

int n, i, j, m, k, start, q;

ll dist = 0;

void solve() {

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
