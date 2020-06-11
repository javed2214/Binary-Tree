// Kth Smallest Element in BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst

class Solution {
public:

    int cnt = 0, x = -1;
    
    void go(TreeNode *root, int k){
        if(root){
            go(root->left, k);
            cnt += 1;
            if(cnt == k){
                x = root->val;
                return;
            }
            go(root->right, k);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        go(root, k);
        return x;
    }
};
