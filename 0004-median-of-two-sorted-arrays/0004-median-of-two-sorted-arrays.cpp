class Solution {
public:
    int kths(vector<int>& nums1, vector<int>& nums2, int s1, int e1, int s2, int e2, int k) {
        // Base cases: If one array is exhausted, return the k-th element from the other array
        if (s1 > e1)
            return nums2[s2 + k];
        if (s2 > e2)
            return nums1[s1 + k];

        // Calculate the middle indices
        int m1 = (e1 - s1) / 2;
        int m2 = (e2 - s2) / 2;

        if (k > m1 + m2) { 
            if (nums1[s1 + m1] > nums2[s2 + m2]) {
                return kths(nums1, nums2, s1, e1, s2 + m2 + 1, e2, k - (m2 + 1));
            } else {
                return kths(nums1, nums2, s1 + m1 + 1, e1, s2, e2, k - (m1 + 1));
            }
        } else {
            if (nums1[s1 + m1] > nums2[s2 + m2]) {
                return kths(nums1, nums2, s1, s1 + m1 - 1, s2, e2, k);
            } else {
                return kths(nums1, nums2, s1, e1, s2, s2 + m2 - 1, k);
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int total = n1 + n2;

        if (total % 2 == 1) {
            return kths(nums1, nums2, 0, n1 - 1, 0, n2 - 1, total / 2);
        } else {
            int left = kths(nums1, nums2, 0, n1 - 1, 0, n2 - 1, total / 2 - 1);
            int right = kths(nums1, nums2, 0, n1 - 1, 0, n2 - 1, total / 2);
            return (left + right) / 2.0;
        }
    }
};
