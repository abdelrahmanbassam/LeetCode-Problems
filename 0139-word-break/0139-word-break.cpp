class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1);
        dp[0] = true;
        for(int  i = 1; i <= n; i++){
            for(auto &word : wordDict){
                int j = i - word.size();
                if(j >= 0 && s.substr(j,word.size()) == word && dp[j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};