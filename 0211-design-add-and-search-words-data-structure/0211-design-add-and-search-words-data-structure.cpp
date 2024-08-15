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
class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
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
        return helper(word,root,0);
    }
    bool helper(string &word,TrieNode* root,int ind){
         TrieNode* curNode = root;
        int c = 0;
        for(int i = ind  ; i < word.size() ;i++){
            c = word[i] -'a';
            if(word[i] == '.'){
                for(auto &node : curNode->children)
                    if(node != NULL && helper(word,node,i+1))
                        return true;

            }
            if(word[i] == '.'||curNode ->children[c] == NULL)
                return false;
            curNode = curNode ->children[c];    
        }
        return curNode->isWord;
    }
    private:
        TrieNode* root;
};