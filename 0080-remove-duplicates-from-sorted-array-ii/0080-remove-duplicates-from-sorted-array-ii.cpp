class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> freq;
        int j = 1;
        freq[nums[0]]++;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1] || freq[nums[i]] < 2){
                nums[j++] = nums[i];
                freq[nums[i]]++;
            }
        }
        return j;
    }
};