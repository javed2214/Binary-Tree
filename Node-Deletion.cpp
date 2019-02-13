// Deletion of Node from BST

class Solution {
public:
    
    TreeNode *minNode(TreeNode *root){
        
        while(root->left!=NULL)
            root=root->left;
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL) return NULL;
        else if(key < root->val)
            root->left=deleteNode(root->left,key);
        else if(key > root->val)
            root->right=deleteNode(root->right,key);
        else{
            if(root->left==NULL and root->right==NULL){
                delete(root);
                return NULL;
            }
            else if(root->left==NULL){
                TreeNode *temp=root->right;
                delete(root);
                return temp;
            }
            else if(root->right==NULL){
                TreeNode *temp=root->left;
                delete(root);
                return temp;
            }
            else{
                TreeNode *temp=minNode(root->right);
                root->val=temp->val;
                root->right=deleteNode(root->right,temp->val);
            }
        }
        return root;
    }
};
