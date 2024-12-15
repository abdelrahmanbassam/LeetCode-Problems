class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for(auto &e: nums){
            if(!v.size() || v.back() < e )
                v.push_back(e);
            else{
                int replaceInd = lower_bound(v.begin(),v.end(),e) - v.begin();
                v[replaceInd] = e;
            }
        }
        return v.size();
    }
};