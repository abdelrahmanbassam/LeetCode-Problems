class Solution {
public:
    unordered_set<int> rows;
    unordered_set<int> posD;
    unordered_set<int> negD;
    vector<vector<string>> allBoards;
    void putQueens(int n,int curCol,vector<string> &board){
       
        if(curCol == n){
            allBoards.push_back(board);
            return;
        }

        for(int row = 0; row < board.size(); row++){
            if(rows.count(row) || posD.count(row + curCol) || negD.count(row - curCol)){
                continue;
            }

            rows.insert(row);
            posD.insert(row + curCol);
            negD.insert(row - curCol);
            board[row][curCol] = 'Q';

            putQueens(n,curCol + 1,board);

            // Backtrack
            board[row][curCol] = '.';
            rows.erase(row);
            posD.erase(row + curCol);
            negD.erase(row - curCol);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        putQueens(n,0,board);
        return allBoards;
    }
};