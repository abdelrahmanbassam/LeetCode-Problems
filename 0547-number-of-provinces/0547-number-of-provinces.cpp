class Solution {
public:
    void dfs(vector<vector<int>>& graph ,int &node, vector<bool> &vis){
        if(vis[node])
            return;
        vis[node] = true;
        for(int i = 0 ;i < graph[node].size();i++)
            if(!vis[i] && graph[node][i] == 1)
                dfs(graph,i,vis);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        vector<bool>vis(isConnected.size());
        for(int i = 0 ;i < isConnected.size();i++){
            if(!vis[i] ){
                ans++;
                dfs(isConnected,i,vis);
            }

        }
        return ans;

    }
};