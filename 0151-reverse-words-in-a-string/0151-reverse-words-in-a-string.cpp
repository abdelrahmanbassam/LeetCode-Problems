class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int wordStart = 0;
        while(wordStart < s.size()){
            int wordEnd = wordStart;
            // while(wordStart == ' ')
            //     wordStart++;
            while(wordEnd < s.size() && s[wordEnd] != ' ' )
                wordEnd++;

            reverse(s.begin() + wordStart,s.begin() + wordEnd);
            wordStart = wordEnd + 1;
        }  
        return cleanSpaces(s,s.size());
            
    }
    string cleanSpaces(string a, int n) {
        int i = 0, j = 0;
        while (j < n) {
            while (j < n && a[j] == ' ') j++;             // skip spaces
            while (j < n && a[j] != ' ') a[i++] = a[j++]; // keep non spaces
            while (j < n && a[j] == ' ') j++;             // skip spaces
            if (j < n) a[i++] = ' ';                      // keep only one space
        }
        return a.substr(0, i);
    }
};
