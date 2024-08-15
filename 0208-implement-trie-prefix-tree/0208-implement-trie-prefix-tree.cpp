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
    Trie() {
        root = new TrieNode();
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
    
    bool startsWith(string prefix) {
        TrieNode* curNode = root;
        int ind = 0;
        for(auto c : prefix){
            ind = c -'a';
             if(curNode ->children[ind] == NULL)
                return false;
            curNode = curNode ->children[ind];   
        }
        return true;
    }
    private:
        TrieNode* root;
};