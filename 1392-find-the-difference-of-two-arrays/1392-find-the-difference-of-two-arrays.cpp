class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool>oc1,oc2;
        vector<vector<int>>ans(2);

        for(auto &x : nums1) oc1[x]=true;     
        for(auto &x : nums2) oc2[x]=true;     
        
        for(auto &x : oc1)
            if(!oc2[x.first])
                ans[0].push_back(x.first);
        
        for(auto &x : oc2)
            if(!oc1[x.first])
                ans[1].push_back(x.first);
        return ans;
    }
};