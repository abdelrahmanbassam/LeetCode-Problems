class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0,maxDig = 0;
        for(auto &d : dimensions){
            int curDig = d[0]*d[0] + d[1]*d[1];
            int curArea = d[0] * d[1];
            if(maxDig < curDig){
                maxDig = curDig;
                maxArea = curArea;
            }
            else if(maxDig == curDig){
                maxArea = max(maxArea,curArea);
            }
        }
        return maxArea;

    }
};