class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> vis;
        for (auto word : wordDict) {
            vis[word] = true;
        }

        vector<bool> dp(s.size() + 1, false); 
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j]) {
                    string word = s.substr(j, i - j); 
                    if (vis.find(word) != vis.end()) { 
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[s.size()];
    }
};
