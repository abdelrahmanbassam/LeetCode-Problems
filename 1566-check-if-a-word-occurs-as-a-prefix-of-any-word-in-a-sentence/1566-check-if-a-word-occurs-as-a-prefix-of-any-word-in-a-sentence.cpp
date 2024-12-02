class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int l = 0,j,word = 1; 
        for(int i = 0; i < sentence.size(); i++){
            l = 0,j = i;
            while(l < searchWord.size() && j < sentence.size() &&  sentence[j] == searchWord[l]){
                j++;
                l++;
            } 
            if(l == searchWord.size())
                return word;
            
            while(i < sentence.size() && sentence[i] != ' ' )
                i++;
            word++;
        }
        return -1;
    }
};