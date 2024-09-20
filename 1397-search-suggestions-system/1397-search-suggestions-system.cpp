
class TrieNode{
public:
    TrieNode* children[26];
    bool isWord ;
    TrieNode(){
        for(int i = 0 ; i < 26 ; ++i)
            children[i] = NULL;
        isWord = false;    
    }
};
class Trie {
public:
    vector<string>threeWords;
    Trie() {
        root = new TrieNode();
    }
    void clear(){
        threeWords.clear();
    }
    void dfs(TrieNode* curNode, string word){
        if(threeWords.size() == 3)
            return;
        if(curNode ->isWord)
            threeWords.push_back(word);
        for(int i = 0 ; i < 26 ; ++i){
            if(curNode ->children[i] != NULL)
                dfs(curNode ->children[i], word + char('a' + i));
        }
    }
    void insert(string word) {
        TrieNode* curNode = root;
        int ind = 0;
        for(auto &c : word){
            ind = c -'a';
            if(curNode ->children[ind] == NULL)
                curNode ->children[ind] = new TrieNode();
            curNode = curNode ->children[ind];
        }    
        curNode ->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* curNode = root;
        int ind = 0;
        for(auto c : word){
            ind = c -'a';
            if(curNode ->children[ind] == NULL)
                return false;
            curNode = curNode ->children[ind];    
        }
        return curNode->isWord;
    }
    
    vector<string> startsWith(string prefix) {
        clear();
        TrieNode* curNode = root;
        int ind = 0;
        for(auto c : prefix){
            ind = c -'a';
             if(curNode ->children[ind] == NULL)
                return threeWords;
            curNode = curNode ->children[ind];   
        }

        dfs(curNode, prefix);
        return threeWords;

    }
    private:
        TrieNode* root;
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        for(auto &product : products)
            trie.insert(product);
        vector<vector<string>>ans;
        string prefix;
        for(auto &c : searchWord){
            prefix += c;
            ans.push_back(trie.startsWith(prefix));
        }
        return ans;
    }
};