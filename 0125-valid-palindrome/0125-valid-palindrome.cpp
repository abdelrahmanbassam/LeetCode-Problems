class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,r=s.size()-1;
        while(true){ 
            while(r >= 0 && !isalnum(s[r]))
                r--;
            while(l < s.size() && !isalnum(s[l]))
                l++;
                
            if(l >= s.size() || r < 0)
                break;

            if(tolower(s[r]) != tolower(s[l]) )
                return false;    
            l++;
            r--;
        }
        return true;
    }
};