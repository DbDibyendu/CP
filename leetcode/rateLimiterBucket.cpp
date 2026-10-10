#include <iostream>
#include <unordered_map>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

// Note: To strictly follow Dependency Inversion Principle (SOLID), 
// we would normally define an abstract interface IRateLimiter here.

class TokenBucket {
    // Single Responsibility Principle (SOLID): This class only handles token math.
private:
    long long maxTokens;
    long long refillRate; // tokens per second
    double currentTokens;
    long long lastRefillTime; // Simple timestamp in seconds

    long long getCurrentTime() {
        return time(nullptr); // Returns current Unix timestamp in seconds
    }

    void refill() {
        long long now = getCurrentTime();
        long long elapsed = now - lastRefillTime;
        double tokensToAdd = elapsed * refillRate;
        
        if (tokensToAdd > 0) {
            currentTokens = min((double)maxTokens, currentTokens + tokensToAdd);
            lastRefillTime = now;
        }
    }

public:
    TokenBucket(long long maxCapacity, long long refillRatePerSec) 
        : maxTokens(maxCapacity), refillRate(refillRatePerSec), currentTokens(maxCapacity) {
        lastRefillTime = getCurrentTime();
    }

    bool allowRequest() {
        refill();
        if (currentTokens >= 1.0) {
            currentTokens -= 1.0;
            return true;
        }
        return false;
    }
};

class RateLimiterManager {
    // Open/Closed Principle (SOLID): Easy to extend with new algorithms 
    // by injecting different rate limiter classes without changing this manager.
private:
    unordered_map<string, TokenBucket*> clientLimiters;
    long long defaultCapacity;
    long long defaultRefillRate;

public:
    RateLimiterManager(long long capacity, long long refillRate) 
        : defaultCapacity(capacity), defaultRefillRate(refillRate) {}

    bool isAllowed(const string& clientId) {
        if (clientLimiters.find(clientId) == clientLimiters.end()) {
            clientLimiters[clientId] = new TokenBucket(defaultCapacity, defaultRefillRate);
        }
        return clientLimiters[clientId]->allowRequest();
    }
    
    // TC: O(1)
    // SC: O(U),  where U is the number of unique clients/users.
    ~RateLimiterManager() {
        for(auto& pair : clientLimiters) {
            delete pair.second;
        }
    }
};
