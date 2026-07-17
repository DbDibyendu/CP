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

class MorseCode {
    vector<string> final_ans;
    unordered_map<string, int> dictionary;

    bool isSentenceViaDictionary(int ind, string &sentence) {
        if (ind == sentence.length()) return true;
        if (ind > sentence.length()) return false;

        for (auto d : dictionary) {
            int l_size = d.first.length();

            if (ind + l_size <= sentence.length() && sentence.substr(ind, l_size) == d.first) {
                if (isSentenceViaDictionary(ind + l_size, sentence)) {
                    return true;
                }
            }
        }
        return false;
    }

    void decodeHelper(int ind, map<char, string> &letters, string &morse, string &possible_word) {
        // Base Case Check
        if (ind == morse.length()) {
            if (isSentenceViaDictionary(0, possible_word)) {
                final_ans.push_back(possible_word);
            }
            return; // FIX: Added return here to prevent continuing the loop unnecessarily when exact match is found
        }

        if (ind > morse.length()) return; // break loop

        for (auto a : letters) { // 26
            int letter_size = a.second.length();

            // matches or not
            if (ind + letter_size <= morse.length() && morse.substr(ind, letter_size) == a.second) {
                int init_length = possible_word.length();
                
                possible_word += a.first; // FIX: Appended the Latin letter (a.first) instead of the Morse code sequence (a.second)
                
                decodeHelper(ind + letter_size, letters, morse, possible_word); // only 4 would match at each loop, prefix of length 1, 2, 3, 4
                
                // revert
                possible_word = possible_word.substr(0, init_length);
            }
        }
    }

public: // FIX: Made public so the driver or testing frameworks can invoke the method externally
    vector<string> decodeMorseCode(map<char, string> letters, string morse, vector<string> dict) {
        final_ans.clear(); // Safety: clear state if class instance is used for multiple test cases
        dictionary.clear();
        
        for (auto d : dict) {
            dictionary[d]++;
        }
        string ans = "";
        decodeHelper(0, letters, morse, ans);

        // time : O(B^K) ~ where B is at max 4 and K = (Morse_length/code_length))
        // Space : O(V), V is the number of results
        return final_ans;
    }
};



// memoise via DP

class MorseCodeV2 {
    vector<string> final_ans;
    unordered_map<string, int> dictionary;
    unordered_map<int, vector<string>> dp;

    bool isSentenceViaDictionary(int ind, string &sentence, vector<int> &dp2) {
        if (ind == sentence.length()) return true;
        if (ind > sentence.length()) return false;

        if(dp2[ind] != -1) return dp2[ind];

        for (auto d : dictionary) {
            int l_size = d.first.length();

            if (ind + l_size <= sentence.length() && sentence.substr(ind, l_size) == d.first) {
                if (isSentenceViaDictionary(ind + l_size, sentence, dp2)) {
                    return dp2[ind] = true;
                }
            }
        }
        return dp2[ind] = false;
    }

    // maintain suffixes in dp
    vector<string> decodeHelper(int ind, map<char, string> &letters, string &morse) {
        // Base Case Check
        vector<string> curr_suffix;

        if (ind == morse.length()) {
          return {""}; // base case
        }

        if (ind > morse.length()) return curr_suffix; // break loop

        if(dp.find(ind) != dp.end()) return dp[ind];

        for (auto a : letters) { // 26
            int letter_size = a.second.length();

            // matches or not
            if (ind + letter_size <= morse.length() && morse.substr(ind, letter_size) == a.second) {
                
                vector<string> next_suffix = decodeHelper(ind + letter_size, letters, morse); // only 4 would match at each loop, prefix of length 1, 2, 3, 4
                
                string curr = a.second;

                for(auto el: next_suffix){
                  curr_suffix.push_back(curr + el);
                }
            }
        }
        return dp[ind] = curr_suffix;

    }

public: // FIX: Made public so the driver or testing frameworks can invoke the method externally
    vector<string> decodeMorseCode(map<char, string> letters, string morse, vector<string> dict) {
        final_ans.clear(); // Safety: clear state if class instance is used for multiple test cases
        dictionary.clear();
        dp.clear();
        
        for (auto d : dict) {
            dictionary[d]++;
        }
        string ans = "";
        vector<string> possible_ans = decodeHelper(0, letters, morse);

        for(auto p: possible_ans){
          vector<int> dp2(p.size()+1, -1);
          if(isSentenceViaDictionary(0, p, dp2)){
              final_ans.push_back(p);
          }
        }

        // morse code length = M, V = possible_ans, D = dictionary size, L = length of possible sentence
        // TC : O(M*26 + V*D*L)
        // O({Total Suffix Combinations Generated} + (V \times D \times L))
        // SC : O(M*(Suffixes) + L)
        return final_ans;
    }
};
