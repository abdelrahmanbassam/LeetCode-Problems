class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int smaller = 0,bigger = nums.size() - 1, equal = 0;
        vector <int> ans(nums.size()); 
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < pivot)
                ans[smaller++] = nums[i];
            equal += nums[i] == pivot;
        }
        while(equal--)
            ans[smaller++] = pivot;
            
        for(int i = bigger; i >= 0; i--){
            if(nums[i] > pivot)
                ans[bigger--] = nums[i];
        }
        return ans;

    }
};