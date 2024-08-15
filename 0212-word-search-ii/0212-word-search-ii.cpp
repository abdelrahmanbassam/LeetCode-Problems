

struct TrieNode {
    TrieNode* children[26];
    bool isWord;

    TrieNode() : isWord(false) {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class Solution {
public:
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<string> res;
    TrieNode* root; // Declare root here

    Solution() {
        root = new TrieNode(); // Initialize root in the constructor
    }

    bool check(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }   
    
    void dfs(vector<vector<char>>& board, int x, int y, string &s, TrieNode* node, int n, int m) {
        if(!check(x, y, n, m) || board[x][y] == '0')
            return;
        
        char c = board[x][y];
        node = node->children[c - 'a'];

        if(node == nullptr)  // Check if node is null after moving down the trie
            return;
        
        s += c;
        board[x][y] = '0';
        
        if(node->isWord) {
            res.push_back(s);
            node->isWord = false;
        }
        
        for(int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            dfs(board, nx, ny, s, node, n, m);
        }
        
        board[x][y] = c;
        s.pop_back(); // Remove last character when backtracking
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();

        for(const auto &word : words) {
            insert(word);
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                string s = "";
                dfs(board, i, j, s, root, n, m);
            }
        }
        return res;
    }
    
    void insert(const string &word) {
        TrieNode* curNode = root;
        for(const auto &c : word) {
            int ind = c - 'a';
            if(curNode->children[ind] == nullptr) {
                curNode->children[ind] = new TrieNode();
            }
            curNode = curNode->children[ind];
        }
        curNode->isWord = true;
    }
    
    bool search(const string &word) {
        TrieNode* curNode = root;
        for(const auto &c : word) {
            int ind = c - 'a';
            if(curNode->children[ind] == nullptr)
                return false;
            curNode = curNode->children[ind];    
        }
        return curNode->isWord;
    }
    
    bool startsWith(const string &prefix) {
        TrieNode* curNode = root;
        for(const auto &c : prefix) {
            int ind = c - 'a';
            if(curNode->children[ind] == nullptr)
                return false;
            curNode = curNode->children[ind];   
        }
        return true;
    }
};
