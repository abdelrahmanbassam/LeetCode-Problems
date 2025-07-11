class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1,vector<int>(2,0));
        dp[1][0] = -1 * prices[0];
        for(int i = 2; i <= n; i++){
            dp[i][1] = max(dp[i - 1][0] + prices[i-1], dp[i-1][1]);
            
            dp[i][0] = max(dp[i-2][1] - prices[i-1],dp[i-1][0]);
        }
        return dp[n][1];
    }
};