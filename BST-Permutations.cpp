// Construct All Possible BSTs For Keys 1 to N
// https://www.geeksforgeeks.org/construct-all-possible-bsts-for-keys-1-to-n/
// https://leetcode.com/problems/unique-binary-search-trees-ii/

#include<bits/stdc++.h>
using namespace std;

typedef struct node{

	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int n){

	node *root=new node;
	root->data=n;
	root->left=NULL;
	root->right=NULL;

	return root;
}

void preOrder(node *root){

	if(root){
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

vector<node *> DFS(int l, int r){

	if(l>r) return {NULL};
	
	vector<node *> res;
	for(int i=l;i<=r;i++){
		auto left=DFS(l,i-1);
		auto right=DFS(i+1,r);
		for(auto x:left){
			for(auto y:right){
				node *temp=createNode(i);
				temp->left=x;
				temp->right=y;
				res.push_back(temp);
			}
		}
	}
	return res;
}

int main(){

	int n;
	cin>>n;
	vector<node *> res;
	res=DFS(1,n);

	for(auto it:res){
		preOrder(it);
		cout<<"\n";
	}
	cout<<res.size();
	return 0;
}
