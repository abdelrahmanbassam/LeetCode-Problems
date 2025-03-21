class Solution {
public:
    unordered_map<string,int> recipeToInd;
    unordered_map<string,bool> canMakeRecipe;
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> possibleRecipes;
        for(auto &supply : supplies){
            canMakeRecipe[supply] = true;
        }
        for (int idx = 0; idx < recipes.size(); idx++) {
            recipeToInd[recipes[idx]] = idx;
        }
        for(auto &rec : recipes){
            unordered_set<string> visited;
            canMakeIt(rec, visited, ingredients);
            if(canMakeRecipe[rec])
                possibleRecipes.push_back(rec);
        }
        return possibleRecipes;
    }
    bool canMakeIt(string curRec, unordered_set<string> &visited,vector<vector<string>>& ingredients){
        if(canMakeRecipe[curRec])
            return true;
        auto idxIt = recipeToInd.find(curRec);
        if (idxIt == recipeToInd.end() || visited.count(curRec)) {
            canMakeRecipe[curRec] = false;
            return false;
        }
        visited.insert(curRec);
        for(auto &ing : ingredients[idxIt->second]){
            if(!canMakeIt(ing,visited,ingredients)){
                canMakeRecipe[curRec] = false;
                return false;
            }
        }
        return canMakeRecipe[curRec] = true;
    }
};