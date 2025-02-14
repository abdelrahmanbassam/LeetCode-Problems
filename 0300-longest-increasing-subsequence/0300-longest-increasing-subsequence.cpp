class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        for(int i = nums.size(); i >= 0; i-- ){
            for(int j = i+1 ; j < nums.size(); j++){
                if(nums[j]>nums[i]){
                    dp[i]=max(dp[j]+1,dp[i]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};