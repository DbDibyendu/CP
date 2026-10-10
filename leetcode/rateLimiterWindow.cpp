#include <iostream>
#include <queue>
#include <ctime>

using namespace std;

// ==========================================
// 1. Fixed Window Counter
// ==========================================
class FixedWindowCounter {
    // Single Responsibility Principle: Handles only fixed boundary counting.
private:
    long long limit;
    long long windowSize; // in seconds
    long long windowStartTime;
    long long count;

    long long getCurrentTime() {
        return time(nullptr);
    }

public:
    FixedWindowCounter(long long maxRequests, long long windowSizeInSec)
        : limit(maxRequests), windowSize(windowSizeInSec), count(0) {
        // Snap to the start of the current window (e.g., start of the minute)
        windowStartTime = (getCurrentTime() / windowSize) * windowSize; 
    }

    bool allowRequest() {
        long long now = getCurrentTime();
        long long currentWindowStart = (now / windowSize) * windowSize;

        // Reset if we've moved to a new window
        if (currentWindowStart != windowStartTime) {
            windowStartTime = currentWindowStart;
            count = 0;
        }

        if (count < limit) {
            count++;
            return true;
        }
        return false;

        // TC: O(1)
        // SC: O(1)
        // Boundary issue remains in fixed counter, but good from simplicity and TC
    }
};

// ==========================================
// 2. Sliding Window Log
// ==========================================
class SlidingWindowLog {
    // Single Responsibility Principle: Handles accurate rolling window via logs.
private:
    long long limit;
    long long windowSize; // in seconds
    queue<long long> timestamps;

    long long getCurrentTime() {
        return time(nullptr);
    }

public:
    SlidingWindowLog(long long maxRequests, long long windowSizeInSec)
        : limit(maxRequests), windowSize(windowSizeInSec) {}

    bool allowRequest() {
        long long now = getCurrentTime();

        // Evict timestamps older than the window
        while (!timestamps.empty() && timestamps.front() <= now - windowSize) {
            timestamps.pop();
        }

        if (timestamps.size() < limit) {
            timestamps.push(now);
            return true;
        }
        return false;
    }

    // TC: Amortized O(1), worse case : O(N). Massive burst
    // SC:  O(L)
};

class RateLimiterManager {
    // Open/Closed Principle (SOLID): Easy to extend with new algorithms 
    // by injecting different rate limiter classes without changing this manager.
private:
    unordered_map<string, SlidingWindowLog*> clientLimiters;
    long long defaultCapacity;
    long long windowSize;

public:
    RateLimiterManager(long long capacity, long long windowSize) 
        : defaultCapacity(capacity), windowSize(windowSize) {}

    bool isAllowed(const string& clientId) {
        if (clientLimiters.find(clientId) == clientLimiters.end()) {
            clientLimiters[clientId] = new SlidingWindowLog(defaultCapacity, windowSize);
        }
        return clientLimiters[clientId]->allowRequest();
    }
    
    ~RateLimiterManager() {
        for(auto& pair : clientLimiters) {
            delete pair.second;
        }
    }
};
