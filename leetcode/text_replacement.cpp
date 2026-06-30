class Solution {

public:
    unordered_map<string, string> mp;
    unordered_map<string, string> memo; // ✅ added cache

    string dfs(const string& s) {

        // ✅ check cache first
        if (memo.count(s)) {
            return memo[s];
        }

        size_t start = s.find('%');

        if (start == string::npos) {
            return memo[s] = s;
        }

        size_t end = s.find('%', start + 1);

        if (end == string::npos) {
            return memo[s] = s;
        }

        string key = s.substr(start + 1, end - start - 1);

        string replacement = dfs(mp[key]);

        return memo[s] =
            s.substr(0, start) +
            replacement +
            dfs(s.substr(end + 1));
    }

    string applySubstitutions(
        vector<vector<string>>& replacements,
        string text) {

        for (auto& r : replacements) {
            mp[r[0]] = r[1];
        }

        return dfs(text);
    }
};
