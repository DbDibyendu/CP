#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Address {
  int number; // Treat 0 as the missing/wildcard indicator
  string streetName;
  string cityName;
  string stateName;
};

class AddressManager {
  unordered_map<int, vector<int>> numMap;
  unordered_map<string, vector<int>> streetMap;
  unordered_map<string, vector<int>> cityMap;
  unordered_map<string, vector<int>> stateMap;
  vector<Address> addressBook; // 🛠️ Renamed class member to avoid shadowing traps

public:
  void initAddress(vector<Address> inputAddress) {
    addressBook = inputAddress; // 🛠️ FIX: Correctly populate the member container

    int i;
    int n = addressBook.size();
    for(i = 0; i < n; i++) {
      numMap[addressBook[i].number].push_back(i);
      streetMap[addressBook[i].streetName].push_back(i);
      cityMap[addressBook[i].cityName].push_back(i);
      stateMap[addressBook[i].stateName].push_back(i);

      // Map wildcards to collect all records
      numMap[0].push_back(i);
      streetMap[""].push_back(i);
      cityMap[""].push_back(i);
      stateMap[""].push_back(i);
    }
  }

  pair<bool, Address> queryAddress(Address query) {
    // 🛠️ FIX: Swapped out NULL comparison for clear wildcard value tracking
    if(query.number != 0 && numMap.find(query.number) == numMap.end()) return {false, {}};
    if(query.streetName != "" && streetMap.find(query.streetName) == streetMap.end()) return {false, {}};
    if(query.cityName != "" && cityMap.find(query.cityName) == cityMap.end()) return {false, {}};
    if(query.stateName != "" && stateMap.find(query.stateName) == stateMap.end()) return {false, {}};

    unordered_map<int, int> indexFreq;
    
    for(auto a: numMap[query.number])   indexFreq[a]++;
    for(auto a: streetMap[query.streetName]) indexFreq[a]++;
    for(auto a: cityMap[query.cityName])   indexFreq[a]++;
    for(auto a: stateMap[query.stateName]) indexFreq[a]++;

    int maxFreq = -1;
    int index = -1;
    for(auto t: indexFreq) {
      if(t.second > maxFreq) {
        maxFreq = t.second;
        index = t.first;
      }
    }
    
    // 🛠️ FIX: Ensure it matched ALL 4 criteria components exactly
    if (maxFreq != 4 || index == -1) {
        return {false, {}};
    }
    
    return {true, addressBook[index]};
  }
};


// Memory improvement techniques
// String -> Int map to decrease memory footprint
// Geo Hash Sharding based on State name, 2nd priority cityName
// Delta encoding for storing frequency in vector
//
