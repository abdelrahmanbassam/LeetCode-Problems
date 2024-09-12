class Solution {
public:
    void dfs(vector<vector<pair<int,int>>> &adj,vector<bool> &vis,int &ans,int node){
        vis[node] = true;
        for(auto i : adj[node]){
            if(!vis[i.first]){
                ans += i.second;
                dfs(adj,vis,ans,i.first);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto i : connections){
            adj[i[0]].push_back({i[1],1});
            adj[i[1]].push_back({i[0],0});
        }
        vector<bool> vis(n,false);
        int ans = 0;
        dfs(adj,vis,ans,0);
        return ans;
        
    }
};
