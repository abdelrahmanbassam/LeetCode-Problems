class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_set<int> seen;
        vector<int> result(n, 0);
        int commonCount = 0;

        for (int i = 0; i < n; i++) {
            if (!seen.insert(nums1[i]).second) 
                commonCount++;
            if (!seen.insert(nums2[i]).second) 
                commonCount++;
            result[i] = commonCount;
        }

        return result;
    }
};
