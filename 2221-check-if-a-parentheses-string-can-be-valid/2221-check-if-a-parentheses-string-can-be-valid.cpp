class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> openStack, wildcardStack;
        int n = s.size();

        if (n % 2 ) 
            return false;

        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') {
                wildcardStack.push(i);
            } else if (s[i] == '(') {
                openStack.push(i);
            } else {
               
                if (!openStack.empty()) {
                    openStack.pop(); 
                } else if (!wildcardStack.empty()) {
                    wildcardStack.pop(); 
                } else {
                    return false; 
                }
            }
        }

        while (!openStack.empty() && !wildcardStack.empty() &&
               openStack.top() < wildcardStack.top()) {
            openStack.pop();
            wildcardStack.pop();
        }

        return openStack.empty();
    }
};
