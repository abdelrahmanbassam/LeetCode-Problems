
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto &c : tokens){
            if(c == "-" || c == "+" || c == "*" || c == "/"){
                int s = st.top();
                st.pop();
                int f = st.top();
                st.pop();
                
                if(c == "-") st.push(f-s);
                if(c == "+") st.push(f+s);
                if(c == "*") st.push(f*s);
                if(c == "/") st.push(f/s);
            }
            else{
                st.push(stoi(c));
                
            }
        }
        return st.top();
    }
};