class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        vector<bool> dp(s.size() + 1, false); 
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++) {
            for(auto &x : wordDict) {
                int j = i - x.size() ;
                if (j >= 0 && dp[j]&& s.substr(j,x.size()) == x) {
                    dp[i] = true;
                    break;
                }
                
            }
        }

        return dp[s.size()];
    }
};
