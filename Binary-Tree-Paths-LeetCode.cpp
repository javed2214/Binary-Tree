// Binary Tree Paths LeetCode
// https://leetcode.com/problems/binary-tree-paths/

/*

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

*/

class Solution {
public:
    
    void dfs(TreeNode *root, string s, vector <string> &v){
        
        s += to_string(root->val);
        
        if(!root->left and !root->right){
            v.push_back(s);
            return;
        }
        
        if(root->left) dfs(root->left, s + "->", v);
        if(root->right) dfs(root->right, s + "->", v);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector <string> v;
        if(!root) return v;
        
        dfs(root, "", v);
        
        return v;
    }
};

