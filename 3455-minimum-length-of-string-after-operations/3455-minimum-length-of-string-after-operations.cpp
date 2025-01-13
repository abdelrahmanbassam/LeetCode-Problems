class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int deleted = 0;
        unordered_map<char, int> freqs;
        for(int i = 0; i < n; i++)
            freqs[s[i]]++;
        
        for(auto c : freqs){
            int freq = c.second;
            if(freq%2)
                deleted += freq - 1 ;
            else
                deleted += freq - 2;
        }
        return n - deleted;
    }
};