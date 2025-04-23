class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int upperIndx = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
        int lowerIndx = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        if(lowerIndx >= 0 && upperIndx <= nums.size() && upperIndx > 0 && nums[upperIndx-1] == target)
            return {lowerIndx,upperIndx-1};
        else
            return {-1,-1};
    }
};