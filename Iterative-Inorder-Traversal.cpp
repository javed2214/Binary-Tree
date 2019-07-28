// // https://www.interviewbit.com/problems/inorder-traversal/
// Algorithm:-
// 1. If node is not NULL, Push it into the Stack and Move to its Left Child
// 2. If node is NULL Pop Element from the Stack and Move to its Right Child
// 3. Else break

vector<int> Solution::inorderTraversal(TreeNode* root) {
        
    stack <TreeNode *> S;
    vector<int> v;
    
    TreeNode *p = root;

    while(true){
        
        if(p!=NULL){
            S.push(p);
            p=p->left;
        }
        else{
            if(!S.empty()){
                p = S.top();
                S.pop();
                int vx = p->val;
                v.push_back(vx);
                p=p->right;
                
            }
            else break;
        }
    }
    return v;
}
