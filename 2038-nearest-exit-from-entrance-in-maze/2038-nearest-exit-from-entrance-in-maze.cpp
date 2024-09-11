class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        pair<int,int> start = {entrance[0],entrance[1]};
        queue<pair<int,pair<int,int>>> q;
        q.push({0,start});
        int n = maze.size();
        int m = maze[0].size();
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            auto [dist,curr] = q.front();
            q.pop();
            if(curr != start && (curr.first == 0 || curr.first == n-1 || curr.second == 0 || curr.second == m-1)){
                return dist;
            }
            for(int i = 0 ; i < 4 ; i++){
                int x = curr.first + dir[i][0];
                int y = curr.second + dir[i][1];
                if(x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == '.'){
                    maze[x][y] = '+';
                    q.push({dist+1,{x,y}});
                }
            }
        }
        return -1;
    }
};