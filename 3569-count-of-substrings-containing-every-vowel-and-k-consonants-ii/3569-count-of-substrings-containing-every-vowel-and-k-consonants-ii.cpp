class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int vSum(unordered_map<char,int> &vowels){
        int ans = 0;
        for(auto &v : vowels)
            ans += v.second != 0;
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        long long validSubs = 0, s = 0, e = 0,consCount = 0,nextConsInd = word.size();
        vector<int> nextCons(word.size());
        for(int i = word.size() - 1; i >= 0; i--){
            nextCons[i] = nextConsInd;
            nextConsInd = isVowel(word[i]) ? nextConsInd : i;
        }
        unordered_map<char,int> vowels;
        while(e < word.size()){

            if(isVowel(word[e]))
                vowels[word[e]]++;
            else
                consCount++;

            while(consCount > k){
                if(isVowel(word[s]))
                    vowels[word[s]]--;
                else
                    consCount--;
                s++;
            }
            while(consCount == k && vSum(vowels) == 5){
                int nextCon = nextCons[e];
                validSubs += nextCon - e;
                if(isVowel(word[s]))
                    vowels[word[s]]--;
                else
                    consCount--;
                s++;
            }
            e++;
        }
        return validSubs;
    }
};