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

struct Time {
    int day;
    int hour;
    int min;

    Time() : day(0), hour(0), min(0) {}
};

class FileSearch {
    // Mock API declaration provided by the system
    bool checkObject(int day, int hour, int min) {
        // Implemented by the system
        return true; 
    }

    int findMissingItemDay() {
        int l = 0, r = 29, mid;
        int ans = 29; // Default to the last day if never found earlier

        while (l <= r) {
            mid = l + (r - l) / 2;
            // Check the last minute of the day
            if (checkObject(mid, 23, 59)) {
                // Item is safe at the end of this day, look in the future
                l = mid + 1;
            } else {
                // Item is missing, meaning it disappeared on or before this day
                ans = mid;
                r = mid - 1; // Look left to find the earliest day of missing state
            }
        }
        return ans;
    }

    int findMissingItemHour(int lostDay) {
        int l = 0, r = 23, mid;
        int ans = 23;

        while (l <= r) {
            mid = l + (r - l) / 2;
            // Check the last minute of the hour
            if (checkObject(lostDay, mid, 59)) {
                // Item is safe at the end of this hour, look later
                l = mid + 1;
            } else {
                // Item is missing by the end of this hour
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }

    int findMissingItemMin(int lostDay, int lostHour) {
        int l = 0, r = 59, mid;
        int ans = 59;

        while (l <= r) {
            mid = l + (r - l) / 2;
            if (checkObject(lostDay, lostHour, mid)) {
                // Item is still present at this exact minute, look later
                l = mid + 1;
            } else {
                // Item is missing at this minute
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }

public:
    Time findMissingItem() {
        int lostDay = findMissingItemDay();
        int lostHour = findMissingItemHour(lostDay);
        int lostMin = findMissingItemMin(lostDay, lostHour); // FIX: Corrected parameter order alignment

        Time t;
        t.day = lostDay;
        t.hour = lostHour;
        t.min = lostMin;
        return t;
    }

};
