/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    //pre order traverse
    void dfsSerialize(TreeNode* node, vector<string>& res){
        if(!node){
            res.push_back("N"); // NULL
            return;
        }
        res.push_back(to_string(node->val));
        dfsSerialize(node->left,res); 
        dfsSerialize(node->right,res); 
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        dfsSerialize(root, res);
        return join(res, ",");
    }

    TreeNode* deserialize(string data) {
        vector<string> vals = split(data, ',');
        int i = 0;
        return dfsDeserialize(vals, i);
    }

    TreeNode* dfsDeserialize(vector<string>& res,int &indx){
        if(res[indx] == "N"){
            indx++;
            return NULL;
        }
        TreeNode* newNode = new TreeNode(stoi(res[indx]));  
        indx++;
        newNode->left = dfsDeserialize(res,indx);
        newNode->right = dfsDeserialize(res,indx);
        return newNode;
    }

    

vector<string> split(const string &s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }
    string join(const vector<string> &v, const string &delim) {
        ostringstream s;
        for (const auto &i : v) {
            if (&i != &v[0])
                s << delim;
            s << i;
        }
        return s.str();
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));