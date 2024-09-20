class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans = 0,n = points.size();
        for(int i = 0 ; i < n-1 ; i++){
            int r = points[i][1];
            while(i+1 < n && points[i+1][0] <= r){
                ans++;
                r = min(r,points[i+1][1]);
                i++;
            }
        }
        return n-ans;
    }
};