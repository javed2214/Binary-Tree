// Tilt of Binary Tree
// https://leetcode.com/problems/binary-tree-tilt/

/*
Given a binary tree, return the tilt of the whole tree.

The tilt of a tree node is defined as the absolute difference between the sum of all
left subtree node values and the sum of all right subtree node values. Null node has tilt 0.

The tilt of the whole tree is defined as the sum of all nodes' tilt.

Example:
Input: 
         1
       /   \
      2     3
Output: 1
Explanation: 
Tilt of node 2 : 0
Tilt of node 3 : 0
Tilt of node 1 : |2-3| = 1
Tilt of binary tree : 0 + 0 + 1 = 1
*/


class Solution {
public:
    
    int x = 0;
    
    int tilt(TreeNode *root){
        
        if(!root) return 0;
        
        int left = tilt(root->left);
        int right = tilt(root->right);
        
        x += abs(left - right);
        
        return left + right + root->val;
    }
    
    int findTilt(TreeNode* root) {
        
        tilt(root);
        
        return x;
    }
};




// Slow

class Solution {
public:
    
    int x = 0;
    
    int sum(TreeNode *root){
        if(root == NULL) return 0;
        return root->val + sum(root->left) + sum(root->right);
    }
    
    void nodes(TreeNode *root){
       
       if(root == NULL) return;
        x += abs(sum(root->left) - sum(root->right));
        nodes(root->left);
        nodes(root->right);
    }
    
    int findTilt(TreeNode* root) {
       
        nodes(root);
        
        return x;
    }
};
