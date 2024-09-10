#include <string>
#include <stack>
#include <cctype>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        stack<string> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']') {
                // If it's a digit, read the full number
                if (isdigit(s[i])) {
                    string num = "";
                    while (isdigit(s[i])) {
                        num += s[i];
                        i++;
                    }
                    i--;
                    st.push(num);
                } else {
                    st.push(string(1, s[i]));
                }
            } else {
                // Process the substring within the brackets
                string subStr = "";
                while (!st.empty() && st.top() != "[") {
                    subStr = st.top() + subStr;
                    st.pop();
                }
                st.pop(); // Pop the '['

                // Get the number (k) that precedes the substring
                string k = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    k = st.top() + k;
                    st.pop();
                }
                int times = stoi(k);
                string temp = "";
                for (int j = 0; j < times; j++) {
                    temp += subStr;
                }
                st.push(temp);
            }
        }

        // Construct the final answer
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
