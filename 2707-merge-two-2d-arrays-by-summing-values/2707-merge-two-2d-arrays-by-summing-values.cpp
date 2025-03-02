class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> mergedArray;
        int p1 = 0 , p2 = 0;
        while(p1 < nums1.size() && p2 < nums2.size()){
            if(nums1[p1][0] == nums2[p2][0]){
                mergedArray.push_back({nums2[p2][0],nums1[p1][1] + nums2[p2][1]});
                p1++;
                p2++;
            }
            else if(nums1[p1][0] < nums2[p2][0]){
                mergedArray.push_back({nums1[p1][0],nums1[p1][1]});
                p1++;
            }
            else{
                mergedArray.push_back({nums2[p2][0], nums2[p2][1]});
                p2++;
            }

        }
        while(p1 < nums1.size()){
            mergedArray.push_back({nums1[p1][0],nums1[p1][1]});
            p1++;
        }
        while(p2 < nums2.size()){
            mergedArray.push_back({nums2[p2][0],nums2[p2][1]});
            p2++;
        }
        return mergedArray;
    }

};