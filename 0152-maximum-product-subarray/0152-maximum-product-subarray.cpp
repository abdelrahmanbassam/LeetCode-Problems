class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = 1, curMin = 1, res = nums[0];
        for(auto &e : nums){
            int preMax = curMax;
            curMax = max(max(preMax * e,curMin * e),e);
            curMin = min(min(preMax * e,curMin * e),e);
            res = max(res,curMax);
        }
        return res;
    }
};