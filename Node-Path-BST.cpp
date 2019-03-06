// Print Path from Root to a Given Node in Binary Search Tree
// BackTracking Application

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int n){

	node *root=(node *)malloc(sizeof(node));
	root->data=n;
	root->left=NULL;
	root->right=NULL;

	return root;
}

node *sortedArrayToBST(int *a, int start, int end){

	if(start > end) return NULL;
	int mid=(start+end)/2;
	node *root=createNode(a[mid]);
	root->left=sortedArrayToBST(a,start,mid-1);
	root->right=sortedArrayToBST(a,mid+1,end);

	return root;
}

bool findPath(node *root, int k, std::vector<int> &v){

	if(root==NULL) return false;
	v.push_back(root->data);
	if(root->data==k) return true;
	
	if(k < root->data){
		if(findPath(root->left,k,v)) return true;
	}
	else{
		if(findPath(root->right,k,v)) return true;
	}
	v.pop_back();
	return false;
}

int main(){

	int a[]={1,2,3,4,5,6,7,8,9,10};
	int n=sizeof(a)/sizeof(int);

	node *root=sortedArrayToBST(a,0,n-1);

	int k;
	cin>>k;
	std::vector<int> v;
	if(findPath(root,k,v)){
		for(auto it: v) cout<<it<<" ";
	}
	else cout<<"Node Not Found!";

	return 0;
}