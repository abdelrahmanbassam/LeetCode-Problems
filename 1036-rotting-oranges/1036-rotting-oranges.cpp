class Solution {
public:
    bool isvalid(int i , int j , int n , int m){
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int dir [4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int ans = 0,rot = 0,all = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue <pair<int,pair<int,int>>> pq;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    pq.push({0,{i,j}});
                    rot ++;
                }
                all += grid[i][j] != 0;
            }
        }
        while(pq.size()){
            auto[time,cur] = pq.front();
            pq.pop();
            ans = time;
            for(auto &d : dir){
                int x = cur.first + d[0];
                int y = cur.second + d[1];
                if(isvalid(x,y,n,m)){
                    if(grid[x][y] == 1){
                        pq.push({time+1,{x,y}});
                        grid[x][y] = 2;
                        rot++;
                    }
                }
            }
        }
        if(rot < all) return -1;
        return ans;
    }
};