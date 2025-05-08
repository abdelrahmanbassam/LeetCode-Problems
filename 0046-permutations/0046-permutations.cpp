class Solution {
public:
    vector<vector<int>> permuteHelper(vector<int>& nums){
        if(!nums.size())
            return {{}};


        vector<int> temp = vector<int>(nums.begin()+1, nums.end());
        vector<vector<int>> curPerms = permuteHelper(temp);
        vector<vector<int>> res;
        for(auto &p : curPerms){
            for(int i = 0; i <= p.size(); i++){
                vector<int> p_copy = p;
                p_copy.insert(p_copy.begin() + i, nums[0]);//adding first  elemnt of the nums 
                res.push_back(p_copy);
            }
        }
        return res;

    }
    vector<vector<int>> permute(vector<int>& nums) {
        return permuteHelper(nums);
    }
};