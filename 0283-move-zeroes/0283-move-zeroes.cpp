class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zp = 0,np = 0,sz = nums.size(); //zero pointer and number pointer
        while(zp < sz && nums[zp] != 0)
            zp++;
        np = zp + 1;
        while(np < sz){
            if(nums[np] != 0){
                while(zp < sz && nums[zp] != 0)
                    zp++;
                if(zp < np)
                    swap(nums[np],nums[zp]);
            }
            np++;
        }
    }
};