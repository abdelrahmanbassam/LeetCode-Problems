class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mult = 1;
        int z =0 ;
        for(auto &e : nums){
            if(e == 0)
                z++;
            else 
                mult *= e;
        }
        if(z > 1)
            mult = 0;

        vector<int> ans;
         for(auto &e : nums){
            if(e == 0)
                ans.push_back(mult);
            else if(!z)
                ans.push_back(mult/e);
            else
                ans.push_back(0);
        }
        return ans;
                
    }
};