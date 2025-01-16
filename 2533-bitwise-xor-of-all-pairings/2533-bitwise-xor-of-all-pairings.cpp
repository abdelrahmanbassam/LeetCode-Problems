class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),xor1 = 0;
        int m = nums2.size(),xor2 = 0 ;

        for (int &num : nums1)
            xor1 ^= num;

        for (int &num : nums2)
            xor2 ^= num;

        if(n%2 && m%2) 
            return xor1 ^ xor2;
        if(n%2) 
            return xor2;
        if(m%2)    
            return xor1;
        return 0;
    }
};