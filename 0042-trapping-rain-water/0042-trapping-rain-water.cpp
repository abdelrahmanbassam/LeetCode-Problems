class Solution {
public:
    int trap(vector<int>& h) {
        int trappedWater = 0;
        int n = h.size(),leftMax = h[0], rightMax = h[n-1];
        int l = 0 , r = n - 1;
        while(l < r){
            if(leftMax < rightMax){
                l++;
                leftMax = max(leftMax,h[l]);
                trappedWater += leftMax - h[l];
            }
            else{
                r--;
                rightMax = max(rightMax,h[r]);
                trappedWater += rightMax - h[r];
            }
        }
        return trappedWater;
    }
};