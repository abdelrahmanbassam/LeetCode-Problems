class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool canJ = true;
        int zeroIndx = 0;
        for(int i = nums.size() - 2; i >= 0 ; i--){
            if(nums[i] == 0){
                zeroIndx = max(zeroIndx,i);
                canJ = false;
            }
            else{
                if(nums[i] + i > zeroIndx){
                    canJ = true;
                    zeroIndx = 0;
                }
            }
        }
        return canJ;
    }
};