// Program to Merge Two BST

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createTree(node *root, int n){

	if(root==NULL){
		root=(node *)malloc(sizeof(node));
		root->data=n;
		root->left=NULL;
		root->right=NULL;

		return root;
	}
	else if(n < root->data)
		root->left=createTree(root->left,n);
	else if(n > root->data)
		root->right=createTree(root->right,n);

	return root;
}

void buildVector(node *root, std::vector<int> &v){

	if(root){
		buildVector(root->left,v);
		v.push_back(root->data);
		buildVector(root->right,v);
	}
}

std::vector<int> mergeVector(std::vector<int> &v1, std::vector<int> &v2){

	std::vector<int> v;
	int i=0,j=0;

	while(i<v1.size() and j<v2.size()){
		if(v1[i] < v2[j])
			v.push_back(v1[i++]);
		else if(v1[i] > v2[j])
			v.push_back(v2[j++]);
	}
	while(i<v1.size())
		v.push_back(v1[i++]);
	while(j<v2.size())
		v.push_back(v2[j++]);

	return v;
}

node *createNode(int n){

	node *root=(node *)malloc(sizeof(node));
	root->data=n;
	root->left=NULL;
	root->right=NULL;

	return root;
}

node *buildTree(std::vector<int> &v, int start, int end){

	if(start > end) return NULL;  // Base Case
	
	int mid=(start+end)/2;
	node *root=createNode(v[mid]);
	root->left=buildTree(v,start,mid-1);
	root->right=buildTree(v,mid+1,end);

	return root;
}

void inOrder(node *root){

	if(root){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

int main(){

	int a[]={30,10,50,60};
	int b[]={20,5,35,70};
	int n1=sizeof(a)/sizeof(int);
	int n2=sizeof(b)/sizeof(int);

	std::vector<int> v1,v2;

	node *root1=NULL,*root2=NULL;

	for(int i=0;i<n1;i++)
		root1=createTree(root1,a[i]);

	cout<<"Root 1: ";
	inOrder(root1);

	for(int i=0;i<n2;i++)
		root2=createTree(root2,b[i]);

	cout<<"\nRoot 2: ";
	inOrder(root2);

	buildVector(root1,v1);
	buildVector(root2,v2);

	std::vector<int> v;

	v=mergeVector(v1,v2);

	node *root=NULL;
	int siz=v.size()-1;
	root=buildTree(v,0,siz);

	cout<<"\nAns: ";
	inOrder(root);

	return 0;
}