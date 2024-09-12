class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int ans = 0,n = intervals.size();
        for(int i = 0 ; i < n-1 ; i++){
            int r = intervals[i][1];
            while(i+1 < n && intervals[i+1][0] < r){
                ans++;
                r = min(r,intervals[i+1][1]);
                i++;
            }
        }
        return ans;
    }

};