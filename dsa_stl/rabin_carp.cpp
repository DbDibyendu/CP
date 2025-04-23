#include <iostream>
#include <string>
using namespace std;

const int d = 256;        // d: size of the input alphabet (e.g., 256 for extended ASCII)
const int q = 101;        // q: a large prime number used to mod the hash values (to reduce collisions)

/*
 * Rabin-Karp Algorithm
 * --------------------
 * A string searching algorithm used to find all occurrences of a "pattern" within a "text".
 * It uses hashing to compare substrings of the text with the pattern efficiently.
 *
 * Core Idea:
 * - Compute the hash of the pattern.
 * - Compute rolling hashes of all substrings of text of length m (pattern length).
 * - If hash matches, then compare the actual strings to confirm (due to possible collisions).
 *
 * Hash Formula:
 *   hash(s) = (s[0]*d^(m-1) + s[1]*d^(m-2) + ... + s[m-1]*d^0) % q
 * Rolling hash update:
 *   new_hash = (d * (old_hash - leading_char * h) + trailing_char) % q
 *   where h = d^(m-1) % q
 *
 * Time Complexity:
 * - Average Case: O(n + m)
 * - Worst Case:  O(n * m)  (if too many hash collisions)
 * - Space:       O(1) extra (excluding input)
 */

void rabinKarp(string text, string pattern) {
    int n = text.length();    // length of the text
    int m = pattern.length(); // length of the pattern

    int p = 0; // hash value for pattern
    int t = 0; // hash value for current text window
    int h = 1; // d^(m-1) % q, used to remove leading digit in rolling hash

    // Precompute h = pow(d, m-1) % q
    // This helps in removing the leading character efficiently during rolling hash
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate initial hash values for pattern and first window of text
    // hash(s) = (s[0]*d^(m-1) + s[1]*d^(m-2) + ... + s[m-1]*d^0) % q
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over the text one character at a time
    for (int i = 0; i <= n - m; i++) {
        // If the hash values match, check characters one by one
        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match)
                cout << "Pattern found at index " << i << endl;
        }

        // Rolling hash: update hash value for next window
        if (i < n - m) {
            // Remove leading char, add trailing char
            // t = (d*(t - text[i]*h) + text[i + m]) % q
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // Ensure positive hash
            if (t < 0)
                t += q;
        }
    }
}

int main() {
    string text = "ABCCDDAEFG";
    string pattern = "CDD";
    rabinKarp(text, pattern);
    return 0;
}
