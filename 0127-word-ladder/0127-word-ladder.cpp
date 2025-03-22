class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end() || beginWord == endWord) 
            return 0; 
        unordered_set<string> allowedWords(wordList.begin(),wordList.end());
        queue<string>q;
        q.push(beginWord);
        int steps = 0;
        while(q.size()){
            int len  = q.size();
            steps++;
            for(int i = 0; i < len; i++){
                string curWord = q.front();
                q.pop();
                if(curWord == endWord)
                    return steps;

                for (int j = 0; j < curWord.length(); j++) {
                    char oc = curWord[j];
                    for(char c = 'a'; c <= 'z'; c++){
                        if(c == oc)
                            continue;
                        string newWord = curWord;
                        newWord[j] = c;
                        if(allowedWords.count(newWord)){
                            q.push(newWord);
                            allowedWords.erase(newWord);
                        }
                    }
                }
            }
        }
        return 0;
    }
};