class Solution {
public:
    int maxArea(vector<int>& h) {
        int l = 0,  r = h.size()-1;
        int maxArea = 0;
        while(l < r){
            maxArea = max(maxArea,min(h[r],h[l]) * (r - l));
            if(h[l]<=h[r])
                l++;
            else
                r--;
        }
        return maxArea;
    }
};