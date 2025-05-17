class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return match(0, 0, s, p, dp);
    }

    bool match(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if (dp[i][j] != -1)
            return dp[i][j];

        if (j == p.size())
            return dp[i][j] = (i == s.size());

        bool currentMatch = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Skip the "x*" OR match one occurrence if characters match
            return dp[i][j] = (match(i, j + 2, s, p, dp) || (currentMatch && match(i + 1, j, s, p, dp)));
        } else {
            // Regular match move forward
            return dp[i][j] = (currentMatch && match(i + 1, j + 1, s, p, dp));
        }
    }
};
