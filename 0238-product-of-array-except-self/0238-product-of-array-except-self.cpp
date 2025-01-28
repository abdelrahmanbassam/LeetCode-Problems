class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        bool isZero = 0 ;
        for(auto &e: nums){
            if(e == 0){
                if(isZero){
                    prod = 0;
                    break;
                }
                isZero = 1;
            }
            else
                prod *= e;
        }
        vector<int> ans;
        int val = 0;
        for(auto &e: nums){            
            if(e && isZero)
                val = 0;
            else if(!e)
                val = prod;
            else
                val = prod / e;
            ans.push_back(val);
        }
        return ans;
    }
};