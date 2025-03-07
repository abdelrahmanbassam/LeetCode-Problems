class Solution {
public:
    int dirx[4] = {1, -1, 0, 0};
    int diry[4] = {0, 0, 1, -1};

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        
        vector<vector<bool>> freeO(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                freeO[i][0] = true;
                q.push({i, 0});
            }
            if (board[i][m - 1] == 'O') {
                freeO[i][m - 1] = true;
                q.push({i, m - 1});
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O') {
                freeO[0][i] = true;
                q.push({0, i});
            }
            if (board[n - 1][i] == 'O') {
                freeO[n - 1][i] = true;
                q.push({n - 1, i});
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newX = x + dirx[i];
                int newY = y + diry[i];
                if (newX >= 0 && newY >= 0 && newX < n && newY < m && board[newX][newY] == 'O' && !freeO[newX][newY]) {
                    freeO[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!freeO[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';  
                }
            }
        }
    }
};
