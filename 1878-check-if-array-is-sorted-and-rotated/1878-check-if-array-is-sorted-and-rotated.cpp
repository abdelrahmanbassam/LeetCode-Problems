class Solution {
public:
    bool check(vector<int>& nums) {
        int inv = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1] ){
                inv++;
            }
        }
        inv += nums[0] < nums.back();
        return inv < 2;
    }
};