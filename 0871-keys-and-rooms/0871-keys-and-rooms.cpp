class Solution {
public:
    void dfs(int i, vector<vector<int>> & rooms, vector<int> &vis){
        vis[i]=1;
        for(auto key: rooms[i])
            if(!vis[key])
                dfs(key, rooms, vis);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(), 0);
        dfs(0, rooms, vis);
        int acc = accumulate(vis.begin(),vis.end(),0);
        return acc == rooms.size();

    }
};