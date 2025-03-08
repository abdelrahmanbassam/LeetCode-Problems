class Solution {
public:
    int totalSum;

    int findTargetSumWays(vector<int>& nums, int target) {
       totalSum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>>dp(nums.size() + 1, vector<int>(totalSum * 2 + 1,-1));
        return memoBacktrack(0, 0, nums, target,dp);
    }
    int memoBacktrack(int i , int curSum, vector<int>& nums, int target, vector<vector<int>>&dp){
        if(i == nums.size())
            return curSum == target;
        if(dp[i][curSum + totalSum] != -1)
            return dp[i][curSum + totalSum];
        return dp[i][curSum + totalSum] =memoBacktrack(i+1,curSum + nums[i],nums,target,dp) +
                                memoBacktrack(i+1,curSum - nums[i],nums,target,dp);
    }
};