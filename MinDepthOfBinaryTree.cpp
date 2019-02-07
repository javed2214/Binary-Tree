// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
/*
 	3
   / \
  9  20
    /  \
   15   7

Return its minimum depth = 2.

*/


class Solution {
public:
    int minDepth(TreeNode* root) {
        
        if(root==NULL) return 0;
        else if(root->left==NULL and root->right==NULL) return 1;
        else if(root->left!=NULL and root->right==NULL) return 1+minDepth(root->left);
        else if(root->left==NULL and root->right!=NULL) return 1+minDepth(root->right);
        else return min(minDepth(root->left),minDepth(root->right))+1;
    }
};