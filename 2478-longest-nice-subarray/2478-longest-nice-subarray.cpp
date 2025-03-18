class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int usedBits = 0;   
        int windowStart = 0;
        int maxLength = 0;    
       for(int i = 0; i < nums.size();i++){
        while((usedBits & nums[i])){
            usedBits ^= nums[windowStart++];
        }
        usedBits |= nums[i];
        maxLength = max(maxLength, i - windowStart + 1);

       } 
       return maxLength;
    }
};