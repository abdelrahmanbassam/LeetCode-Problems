class Solution {
public:
    int minOperations(vector<int>& nums) {
        int e0 = 0,e1 = 1,e2 = 2,ans = 0;
        for(int i = 2; i < nums.size(); i++){
            if(nums[e0] == 0){
                nums[e0] = nums[e0] == 0; 
                nums[e1] = nums[e1] == 0; 
                nums[e2] = nums[e2] == 0; 
                ans++;
            }
            e0++;e1++;e2++;

        } 
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                return -1;
            }
        } 
        return ans;

    }
};