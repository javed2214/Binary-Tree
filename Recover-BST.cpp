// Recover Binary Search Tree
// https://leetcode.com/problems/recover-binary-search-tree/
// https://leetcode.com/problems/recover-binary-search-tree/discuss/349700/C%2B%2B-16-ms-97-solution-Morris-traversal-for-O(1)-space

class Solution {
public:
    
    TreeNode *prev,*a,*b;
    
    void inorder(TreeNode *root){
        
        if(root){
            inorder(root->left);
            if(prev and prev->val > root->val){
                if(!a) a = prev;
                b = root;
            }
            prev = root;
            inorder(root->right);
        }
    }
    
    void recoverTree(TreeNode* root) {
        
        inorder(root);
        swap(a->val, b->val);
    }
};