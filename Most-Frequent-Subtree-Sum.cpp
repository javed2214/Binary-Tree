// Most Frequent Subtree Sum - LeetCode
// https://leetcode.com/problems/most-frequent-subtree-sum/

class Solution {
public:
    
    unordered_map <int,int> Map;
    int maxCount = 0;
        
    int dfs(TreeNode *root){
        
        if(root == NULL) return 0;
        int currsum = root->val + dfs(root->left) + dfs(root->right);
        maxCount = max(maxCount, ++Map[currsum]);
        return currsum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        dfs(root);
        
        vector <int> v;
        
        for(auto it:Map)
            if(it.second == maxCount)
                v.push_back(it.first);
        
        return v;
    }
};