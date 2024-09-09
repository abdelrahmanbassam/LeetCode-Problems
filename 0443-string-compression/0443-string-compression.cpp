class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0,n = chars.size();
        int ans = 0;
        while(i < n){
            int curSz = 1;
            chars[ans] = chars[i];
            while(i < n - 1 && chars[i] == chars[i+1]){
                i++;
                curSz++;
            }
            ans++;

            if(curSz > 1)
               for (char c : to_string(curSz)) {
                    chars[ans++] = c;
                }
            i++;
        }
        return ans;
    }
};