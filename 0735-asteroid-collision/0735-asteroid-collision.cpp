class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        for(auto a : asteroids){
            if(s.empty() || a > 0) //if going right take care
                s.push(a);
            else{
                if(s.top()<0){
                    s.push(a);
                    continue;
                }
                while(s.size() && s.top() > 0 && s.top() < -1 * a)
                    s.pop();
                
                if(s.size() && s.top() >= -1 * a){
                    if(s.top() == -1 * a)   
                        s.pop();
                    continue;
                }
                s.push(a);
            }
        }
        vector<int> res(s.size());
        for(int i = s.size() - 1; i >= 0; i--) {
            res[i] = s.top();
            s.pop();
        }
        return res;
    }
};