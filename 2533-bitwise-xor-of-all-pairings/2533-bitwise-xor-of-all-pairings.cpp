class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, long> freq;
        int ans = 0;
        int n = nums1.size();
        int m = nums2.size();

        for (int num : nums1)
            freq[num] += m;
            
        for (int num : nums2) 
            freq[num] += n;

        for (auto& x : freq) {
            if (x.second%2) 
                ans ^= x.first;
        }

        return ans;
    }
};