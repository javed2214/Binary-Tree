// Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
// Program to Find If the Two Nodes are Cousins or Not
// https://leetcode.com/problems/cousins-in-binary-tree/

class Solution {
public:
    
    int parent[100001];
    int level[100001];
    
    void bfs(TreeNode *root){
        
	queue <TreeNode *> q;
        q.push(root);
	    
        while(!q.empty()){
            
	    TreeNode *temp = q.front();
            q.pop();
		
            if(temp->left){
                level[temp->left->val] = 1 + level[temp->val];
                parent[temp->left->val] = temp->val;
                q.push(temp->left);
            }
		
            if(temp->right){
                level[temp->right->val] = 1 + level[temp->val];
                parent[temp->right->val] = temp->val;
                q.push(temp->right);
            }
        }
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        
        bfs(root);
        
        if(level[x] == level[y] and parent[x] != parent[y]) return true;
        return false;
    }
};


