#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

class LFU {
// Making data structures private, but interface public
private:
    unordered_map<int, pair<int, int>> key_to_val;       // key -> {value, frequency}
    // bucket sort
    unordered_map<int, list<int>> freq_to_list;         // frequency -> list of keys
    unordered_map<int, list<int>::iterator> key_to_it;  // key -> iterator in the list
    int K, size, minFreq;

public:
    LFU(int k) {
        minFreq = 1;
        size = 0;
        K = k;
    }

    int get(int key) {
        if (key_to_val.find(key) == key_to_val.end()) {
            return -1; // Not found
        }

        // 1. Use a reference (&) so modifications update the map directly
        auto& a = key_to_val[key]; 
        int old_freq = a.second;

        // 2. Erase key from its current frequency list
        freq_to_list[old_freq].erase(key_to_it[key]);

        // 3. Update frequency
        a.second++;
        int new_freq = a.second;

        // 4. Move key to the new frequency list
        freq_to_list[new_freq].push_front(key);
        key_to_it[key] = freq_to_list[new_freq].begin();

        // 5. If the old minFreq list is now empty, increment minFreq
        if (freq_to_list[minFreq].empty()) {
            minFreq++;
        }

        return a.first;
    }

    void put(int key, int val) {
        if (K <= 0) return; // Edge case: handle 0 capacity gracefully

        // Case 1: Element already exists
        if (key_to_val.find(key) != key_to_val.end()) {
            key_to_val[key].first = val; // Update the value
            get(key);                    // Leverage get() to update frequency lists
            return;                      // CRITICAL: Return early
        }

        // Case 2: Eviction needed before inserting new item
        if (size == K) {
            auto evictBack = freq_to_list[minFreq].back();
            
            freq_to_list[minFreq].pop_back(); // Fixed compilation issue
            key_to_val.erase(evictBack);
            key_to_it.erase(evictBack);
            size--;
        }

        // Case 3: Insert new item
        key_to_val[key] = {val, 1};
        freq_to_list[1].push_front(key);
        key_to_it[key] = freq_to_list[1].begin();
        minFreq = 1; // Reset minFreq to 1 for the brand new item
        size++;
    }
};
