class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long unsigned >> dp(n + 1, vector<long long unsigned >(amount + 1, 0)); 
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for(int c = 1 ; c <= n; c++){
            for(int a = 0; a <= amount; a++){
                dp[c][a] = dp[c-1][a];
                if(a >= coins[c-1]){
                    dp[c][a] += dp[c][a-coins[c-1]];
                }
            }
        }
        return dp[n][amount];
    }
};
