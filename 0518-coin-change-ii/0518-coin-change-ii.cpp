class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long unsigned >> dp(amount + 1, vector<long long unsigned >(n + 1, 0)); 
        for (int i = 0; i <= n; i++) {
            dp[0][i] = 1;
        }

        for (int i = 1; i <= amount; i++) {
            for (int c = n - 1; c >= 0; c--) {
                dp[i][c] = dp[i][c + 1];
                if (i >= coins[c]) {
                    dp[i][c] += dp[i - coins[c]][c]; 
                }
            }
        }

        return dp[amount][0];
    }
};
