// Program to Find Average of Each Level of a Binary Tree
// https://leetcode.com/problems/average-of-levels-in-binary-tree/

class Solution{
public:
    vector<double> averageOfLevels(TreeNode* root) {
        
        queue<TreeNode *>q;
        q.push(root);
        vector<double>v;
        double sum=0;
        while(!q.empty()){
            int s=q.size();
            sum=0;
            for(int i=0;i<s;i++){
                TreeNode *temp=q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            double x=sum/s;
            v.push_back(x);
        }
        return v;
    }
};