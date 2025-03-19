class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for(int i = 2; i < nums.size(); i++){
            if(nums[i-2] == 0){
                nums[i-2] = nums[i-2] == 0; 
                nums[i-1] = nums[i-1] == 0; 
                nums[i] = nums[i] == 0; 
                ans++;
            }
        } 
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                return -1;
            }
        } 
        return ans;

    }
};