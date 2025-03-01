class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            if(nums[i] == nums[i+1]){
                nums[i] *=2;
                nums[i + 1] = 0;
            }
        }
        int z = 0,e = 0;
        while(e < n && z < n){
            while(z < n && nums[z] != 0)
                z++;                
            while(e < n && nums[e] == 0)
                e++;
            e = max(e, z + 1);
            if(e < n && z < n && e > z)
                swap(nums[e],nums[z]);
        }
        
        return nums;
    }
};