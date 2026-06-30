#include <bits/stdc++.h>
using namespace std;

class TokenBucketRateLimiter {
    double capacity;
    double tokens;
    double refillRate; // tokens per second
    long long lastRefillTime;

public:
    TokenBucketRateLimiter(double cap, double rate) {

    capacity = cap;
    tokens = cap;
    refillRate = rate;

    lastRefillTime =
        chrono::duration_cast<chrono::seconds>(
            chrono::steady_clock::now().time_since_epoch()
        ).count();
    }

    void refill(long long now) {
        double delta = now - lastRefillTime;
        tokens = min(capacity, tokens + delta * refillRate);
        lastRefillTime = now;
    }

    bool allowRequest(long long now) {

        refill(now);

        if (tokens >= 1) {
            tokens -= 1;
            return true;
        }

        return false;
    }
};
