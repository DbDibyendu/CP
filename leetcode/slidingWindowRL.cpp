#include <bits/stdc++.h>
using namespace std;

class SlidingWindowRateLimiter {
    int maxRequests;
    int windowSizeSec;
    deque<long long> q;

public:
    SlidingWindowRateLimiter(int maxR, int windowSec)
        : maxRequests(maxR), windowSizeSec(windowSec) {}

    bool allowRequest(long long currentTime) {

        // remove expired requests
        while (!q.empty() &&
               currentTime - q.front() >= windowSizeSec) {
            q.pop_front();
        }

        if (q.size() >= maxRequests) {
            return false;
        }

        q.push_back(currentTime);
        return true;
    }
};
