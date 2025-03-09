class Solution {
public:
    unordered_map<int, vector<int>> preMap;
    unordered_map<int, bool> taken;
    unordered_set<int> visiting;
    vector<int> ans;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i < numCourses; i++){
            preMap[i] = {};
        }
        for(auto &edge : prerequisites ){
            preMap[edge[0]].push_back(edge[1]);
        }
         for(int i = 0; i < numCourses; i++){
            if(!dfs(i))
                return {};
        }
        return ans;
    }
    bool dfs(int curCourse){
        // cout<<curCourse<<" ";
        // cout<<preMap[curCourse].size()<<" dd\n";
      
        if(visiting.count(curCourse))
            return false;

        visiting.insert(curCourse);
        for(auto &dep : preMap[curCourse]){
            if (!dfs(dep))
                return false;
        }
        visiting.erase(curCourse);
        preMap[curCourse].clear();
        if(!taken[curCourse]){
            ans.push_back(curCourse);
            taken[curCourse] = true;
        }
        return true;

    }
};