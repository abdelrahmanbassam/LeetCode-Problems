class Solution {
public:
    int dirX[4] ={-1,1,0,0};
    int dirY[4] ={0,0,-1,1};
    
    bool dfs(vector<vector<char>>& board, string &word,vector<vector<bool>>& visited,int curX,int curY,int wI){
        
        if(wI == word.size())
            return true;
        
        // if(!word.find(curWord) != word::npos) 
        //     return false;

        visited[curX][curY] = true;

        for(int d = 0; d < 4; d++){
            int newX = curX + dirX[d];
            int newY = curY + dirY[d];
            if(newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size()){
                if(visited[newX][newY])
                    continue;
                char c = board[newX][newY];

                if(c != word[wI])
                    continue;
                    
                if(dfs(board,word,visited,newX,newY,wI + 1))
                    return true;
                // curWord.pop_back();
            }
        }
        visited[curX][curY] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n =board.size(), m = board[0].size();
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    vector<vector<bool>> visited(n,vector<bool>(m,false));
                    if(dfs(board,word,visited,i,j,1))
                        return true;
                }
            }
        }
        return false;
    }
};