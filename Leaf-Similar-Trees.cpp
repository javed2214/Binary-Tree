// Leaf Similar Trees
// https://leetcode.com/problems/leaf-similar-trees/

// Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.
// Two binary trees are considered leaf-similar if their leaf value sequence is the same.
// Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

class Solution {
public:
    
    void getLeaves(TreeNode *root, vector<int> &v){
        
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL) v.push_back(root->val);
        getLeaves(root->left,v);
        getLeaves(root->right,v);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;
        getLeaves(root1,v1);
        getLeaves(root2,v2);
        return v1==v2;
    }
};