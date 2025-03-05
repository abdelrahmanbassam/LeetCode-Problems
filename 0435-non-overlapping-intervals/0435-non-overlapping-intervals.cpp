class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int overlaping = 0;
        sort(intervals.begin(),intervals.end());
        int l = intervals[0][0], r = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < r){
                overlaping++;
                r = min(intervals[i][1],r);
           }
            else{
                r = intervals[i][1];
            }
        }
        return overlaping;
    }
};