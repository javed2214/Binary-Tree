// All Nodes at K Distance from Target Node
// https://leetcode.com/articles/all-nodes-distance-k-in-binary-tree/
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

// ALGORITHM :-
// 1. Run DFS and Find parent of All the Nodes
// 2. Now, Run BFS from the Target Node

// Conclusion -> First Convert the Tree into Graph and with the Help of BFS We can Find all the Nodes at 'K' distance from
// 				 the Target Node

#include<bits/stdc++.h>
using namespace std;


class Solution {
    
    public:
    
    unordered_map<TreeNode *, int> vis;
    unordered_map<TreeNode *, TreeNode *> parent;
    vector <int> v;
    
    void dfs(TreeNode *root){
        
        if(root){
            
            vis[root] = 1;
            if(root->left and vis[root->left] == 0) parent[root->left] = root, dfs(root->left);
            if(root->right and vis[root->right] == 0) parent[root->right] = root, dfs(root->right);
        }
    }
    
    void bfs(TreeNode *root, int k){
        
        queue <TreeNode *> q;
        q.push(root);
        
        vis.clear();
        
        vis[root] = 1;
        
        while(!q.empty()){
            
            int s = q.size();
            k -= 1;
            for(int i=0;i<s;i++){
                
                TreeNode *temp = q.front();
                q.pop();
                
                if(k == 0 and temp) v.push_back(temp->val);
                
                if(temp and temp->left and vis[temp->left] == 0) vis[temp->left] = 1, q.push(temp->left);
                if(temp and temp->right and vis[temp->right] == 0) vis[temp->right] = 1, q.push(temp->right);
                if(temp and vis[parent[temp]] == 0) vis[parent[temp]] = 1, q.push(parent[temp]);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        
        if(!root) return {};
        
        dfs(root);
        parent[root] = NULL;
        
        bfs(target,K+1);
        
        return v;
    }
};