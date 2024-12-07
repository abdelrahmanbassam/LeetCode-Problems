class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<vector<int>>dp(n+1,vector<int> (2));
        dp[0][0] = 0 ,dp[0][1] = 0;
        dp[1][0] = 0 ,dp[1][1] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            dp[i+1][0] = max(nums[i]+dp[i-1][0],dp[i][0]);
            dp[i+1][1] = max(nums[i]+dp[i-1][1],dp[i][1]);
        }
        return max(dp[n][0],dp[n-1][1]);
    }
};