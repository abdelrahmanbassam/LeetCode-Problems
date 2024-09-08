class Solution {
public:
    int helper(int i,vector<int>&dp,vector<int>&cost,int &n){
        if(i >= n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        return dp[i]  = min(helper(i+1,dp,cost,n),helper(i+2,dp,cost,n))+cost[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
       return min(helper(0,dp,cost,n),helper(1,dp,cost,n));
    }
};
