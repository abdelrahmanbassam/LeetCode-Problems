class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> nonOverlapping;
        bool taken = 0;
        int n = intervals.size();
        for(int i = 0; i < n; i++){

            if(intervals[i][1] < newInterval[0] || taken){
                nonOverlapping.push_back(intervals[i]);
            }
            else if(intervals[i][0] > newInterval[1]){
                nonOverlapping.push_back(newInterval);
                taken = 1;
                while(i < n){
                    nonOverlapping.push_back(intervals[i]);
                    i++;
                }
            }
            else{
                int st = min(intervals[i][0] , newInterval[0]);
                int end = max(intervals[i][1] , newInterval[1]);
                while(i < n && intervals[i][0] <= end && intervals[i][0] >= st){
                    st = min(intervals[i][0] , st);
                    end = max(intervals[i][1] , end);
                    i++;
                }
                nonOverlapping.push_back({st,end});
                i--;
                taken = 1;
            }
        }
        if(!taken)
            nonOverlapping.push_back(newInterval);
        return nonOverlapping;
    }
};