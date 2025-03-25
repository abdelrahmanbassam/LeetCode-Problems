class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<vector<int>> modified;

        for(int i = 0; i < meetings.size(); i++){
            int st = meetings[i][0];
            int end = meetings[i][1];

            while(i+1 < meetings.size() && meetings[i+1][0] <= end){
                end =  max(end,meetings[i+1][1]);
                i++;
            }

            modified.push_back({st,end});
        }
        int ans = days;
        for(int i = 0; i < modified.size(); i++){
            // cout<<modified[i][0]<<" "<<modified[i][1]<<" ";
            ans -= (modified[i][1] - modified[i][0] + 1);
        }
        return ans;
    }
};