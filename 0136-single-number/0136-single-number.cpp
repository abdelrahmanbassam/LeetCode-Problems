class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr = 0;
        for(auto &e : nums){
            xorr ^= e;
        }
        return xorr;
    }
};