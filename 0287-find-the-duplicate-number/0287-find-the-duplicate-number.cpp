class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int num = abs(nums[i]) - 1;
            if(nums[num] < 0){
                return num+1;
            }
            nums[num] *= -1;
        }
        return 0;
    }
};