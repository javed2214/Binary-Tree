class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root==NULL) return {};
        vector<vector<int>>res;
        vector<int>v;
        queue<TreeNode *>q;
        q.push(root);
        int count=1;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode *temp=q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            if(count%2==0)
                reverse(v.begin(),v.end());
            res.push_back(v);
            v.clear();
            count++;
        }
        return res;
    }
};