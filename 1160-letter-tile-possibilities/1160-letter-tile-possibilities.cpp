class Solution {
public:
    int freq[26];
    int totalPoss = 0; 
    int numTilePossibilities(string tiles) {
        for(auto &c : tiles)
            freq[c-'A']++;
        backtrackingHelper();
        return totalPoss;
    }
    void backtrackingHelper(){
        for (int i = 0; i < 26; i++) {
            if(freq[i]){
                totalPoss++;
                freq[i]--;
                backtrackingHelper();
                freq[i]++;
            }
        }
    }
};