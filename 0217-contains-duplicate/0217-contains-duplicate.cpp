class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       unordered_set<int> found;
       for(int i = 0; i <nums.size(); i++){
            if(found.count(nums[i]))
                return true;
            found.insert(nums[i]);
       }
       return false;
    }
};