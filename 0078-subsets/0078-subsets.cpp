class Solution {
public:
    vector<vector<int>> allSubsets;
    void constructSubset(int i,vector<int>& nums,vector<int> &curSubset){
        if(i == nums.size()){
            allSubsets.push_back(curSubset);
            return;
        }
        curSubset.push_back(nums[i]);
        constructSubset(i+1,nums,curSubset);
        curSubset.pop_back();
        constructSubset(i+1,nums,curSubset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curSubset;
        constructSubset(0,nums,curSubset);
        return allSubsets;

    }
};