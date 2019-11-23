// Delete Node and Return Forest - Leetcode
// https://leetcode.com/problems/delete-nodes-and-return-forest/
// https://www.youtube.com/watch?v=aaSFzFfOQ0o  	[Best Explanation]


class Solution {
public:
    
    unordered_set <int> S;
    vector <TreeNode *> res;
    
    void dfs(TreeNode *&root){
        
        if(root){
        
            dfs(root->left);
            dfs(root->right);

            if(S.find(root->val) != S.end()){

                if(root->left) res.push_back(root->left);
                if(root->right) res.push_back(root->right);

                root = NULL;
                delete root;
            }
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        for(auto it:to_delete) S.insert(it);
        
        dfs(root);
                
        if(root) res.push_back(root);
        
        return res;
    }
};