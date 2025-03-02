class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> pMap = {{']', '['}, {'}', '{'}, {')', '('}}; 
        for(int i = 0 ; i <s.size(); i++){
            if(s[i] == ']' || s[i] == '}' || s[i] == ')'){
                if(st.empty() || st.top() != pMap[s[i]])
                    return false;
                st.pop();
            }
            else
                st.push(s[i]);
        }
        return st.empty();
    }
};