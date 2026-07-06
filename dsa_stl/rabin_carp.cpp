#include <iostream>
#include <string>
using namespace std;

const int d = 257;        // d: size of the input alphabet (e.g., 256 for extended ASCII), prime
const int q = 1000000007;        // q: a large prime number used to mod the hash values (to reduce collisions), better to keep it 1e9+7

/*
 * Rabin-Karp Algorithm
 * --------------------
 * A string searching algorithm used to find all occurrences of a "pattern" within a "text".
 * It treats strings as large numbers in a positional number system to optimize comparisons.
 *
 * Core Idea:
 * - Compute the hash of the pattern.
 * - Compute rolling hashes of all substrings of text of length m (pattern length).
 * - If hashes match, perform a character-by-character validation to protect against 
 * accidental hash collisions.
 *
 * 1. The Mathematical Framework (String-to-Number Conversion)
 * -----------------------------------------------------------
 * We treat the string like a base-d positional number system (similar to base-10).
 * To prevent immediate integer overflow, the entire polynomial is bound by a large prime modulo q.
 *
 * Formula:
 * hash(s) = (s[0]*d^(m-1) + s[1]*d^(m-2) + ... + s[m-1]*d^0) % q
 *
 * Example: If base d=10, the string "352" maps mathematically to:
 * (3 * 10^2) + (5 * 10^1) + (2 * 10^0) = 352
 *
 * 2. The O(1) Rolling Hash Step (Sliding the Window)
 * --------------------------------------------------
 * When the window slides from an old substring (e.g., "cat") to a new substring (e.g., "ats"),
 * we transform the old hash to the new hash in 3 constant-time algebraic steps:
 *
 * Step A: Subtract the leading character leaving the window.
 * Its positional weight factor is h = d^(m-1) % q.
 * H' = (old_hash - leading_char * h)
 *
 * Step B: Shift left by multiplying by base d.
 * This shifts the place value of all remaining characters leftward by one slot.
 * H'' = H' * d
 *
 * Step C: Add the trailing character entering the lowest-order unit slot.
 * new_hash = H'' + trailing_char
 *
 * Unified Rolling Equation:
 * new_hash = (d * (old_hash - leading_char * h) + trailing_char) % q
 *
 * 3. The C++ Negative Modulo Safeguard
 * ------------------------------------
 * In C++, subtracting numbers inside a modulo can yield a negative result (e.g., -5 % 7 = -5).
 * To guarantee mathematical correctness, we inject the modulo 'q' right after the subtraction
 * to force the value back into positive territory:
 *
 * roll_hash = (roll_hash - (leading_char * h) % q + q) % q; // Step A (Safe)
 * roll_hash = (roll_hash * d + trailing_char) % q;          // Steps B & C
 *
 * Complexities:
 * - Average / Best Case Time: O(n + m) -> Hash operations run in O(1) constant time.
 * - Worst Case Time:          O(n * m) -> Occurs if the text triggers constant hash collisions.
 * - Space Complexity:         O(1) auxiliary extra memory.
 */

// Conceptually it's pretty intuitive actually

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
        p = (d * p + pattern[i]) % q; // (((s[0]*d + s[1])*d + s[2])*d + s[3])
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
