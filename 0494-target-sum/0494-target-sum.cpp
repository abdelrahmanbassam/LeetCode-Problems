class Solution {
public:
    int topDown (vector<vector<int>> &dp,int i,vector<int>& nums, int target, int curSum,int totalSum){
        if(i == nums.size()){
            return curSum == target;
        }
        if(dp[i][curSum + totalSum] != -1){
            return dp[i][curSum + totalSum];
        }
        return dp[i][curSum+ totalSum] = topDown(dp,i+1,nums,target,curSum + nums[i],totalSum) + topDown(dp,i+1,nums,target,curSum - nums[i],totalSum);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> dp(nums.size() + 1, vector<int>(totalSum * 2 + 1,-1));
        topDown(dp,0,nums,target,0,totalSum);
        return dp[0][totalSum];
        // for(int i = 0; i <= n; i++){
        //     dp[i][0] = 1;
        // }
        // for(int i = 1; i <= n; i++){
        //     for(int a = 1; a <= target; a++){
        //         dp[i][a] += dp[i]
        //     }
        // }
        // return dp[n][target];
    }
};