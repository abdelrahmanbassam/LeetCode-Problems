class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> freq(501,0);
        for(auto &e : nums)
            freq[e]++;
        for(int i = 0; i < 501; i++){
            if(freq[i]%2)
                return false;
        }
        return true;
    }
};