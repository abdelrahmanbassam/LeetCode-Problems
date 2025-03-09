class Solution {
public:
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visiting;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i < numCourses; i++){
            preMap[i] = {};
        }
        for(auto &edge : prerequisites ){
            preMap[edge[0]].push_back(edge[1]);
        }
         for(int i = 0; i < numCourses; i++){
            if(!dfs(i))
                return false;
        }
        return true;
    }
    bool dfs(int curCourse){
        if(visiting.count(curCourse))
            return false;
        visiting.insert(curCourse);
        for(auto &dep : preMap[curCourse]){
            if (!dfs(dep))
                return false;
        }
        visiting.erase(curCourse);
        preMap[curCourse].clear();

        return true;

    }
};