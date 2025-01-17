class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xorr = 0;
        for (auto &e : derived) 
            xorr=xorr ^ e;     
        return !xorr;
    }
};