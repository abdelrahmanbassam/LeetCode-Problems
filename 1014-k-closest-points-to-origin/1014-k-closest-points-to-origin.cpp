
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i = 0; i < points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x+y*y;
            pq.push({-1*dist,{x,y}});
        }
        while(k--){
            auto p = pq.top();
            pq.pop();
            ans.push_back({p.second.first,p.second.second});
        }
        return ans;
    }
};
