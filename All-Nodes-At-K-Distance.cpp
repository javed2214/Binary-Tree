// All Nodes at K Distance from Target Node
// https://leetcode.com/articles/all-nodes-distance-k-in-binary-tree/
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

// ALGORITHM :-
// 1. Run DFS and Find parent of All the Nodes
// 2. Now, Run BFS from the Target Node

// Conclusion -> First Convert the Tree into Graph and with the Help of BFS We can Find all the Nodes at 'K' distance from
// 				 the Target Node

class Solution {
public:
    
    unordered_map<TreeNode *, TreeNode *> parent;
    unordered_map<TreeNode *, int> vis;
    vector<int> v;
    
    void findParent(TreeNode *root){
        
        if(root == NULL) return;
        if(root->left){
            parent[root->left] = root;
            findParent(root->left);
        }
        if(root->right){
            parent[root->right] = root;
            findParent(root->right);
        }
    }
    
    void bfs(TreeNode *root, int K){
        
        queue <TreeNode *> q;
        q.push(root);
        
        vis[root] = 1;
        
        while(!q.empty()){
            
            int siz = q.size();
            K -= 1;
            
            for(int i=0;i<siz;i++){
                
                TreeNode *temp = q.front();
                q.pop();
                
                if(K == 0 and temp != NULL) v.push_back(temp->val);
                
                if(temp and temp->left and vis[temp->left] == 0){
                    vis[temp->left] = 1;
                    q.push(temp->left);
                }
                if(temp and temp->right and vis[temp->right] == 0){
                    vis[temp->right] = 1;
                    q.push(temp->right);
                }
                if(temp and vis[parent[temp]] == 0){
                    vis[parent[temp]] = 1;
                    q.push(parent[temp]);
                }
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        
        if(root == NULL) return {};
        
        findParent(root);
        bfs(target, K + 1);
        
        return v;
    }
};

