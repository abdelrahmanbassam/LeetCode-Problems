class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int curInd = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]!=0){
                nums[curInd] = nums[i];
                curInd++;
            }
        }
        for(int i = curInd ; i < nums.size() ; i++)
           nums[i] = 0;
            
    }
};