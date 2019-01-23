// Breadth First Search Algorithm
#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(node *, int);
void inorderTraversal(node *);
void BFStraversal(node *);
void DFStraversal(node *);

queue <node *> Q;

int main(){
	int n,ch,a[20];
	node *root=NULL;
	while(1){
		cout<<"1. Create Node: ";
		cout<<"\n2. Inorder Traversal";
		cout<<"\n3. BFS Traversal";
		cout<<"\n4. DFS Traversal";
		cout<<"\nChoice: ";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter No of Nodes: ";
				cin>>n;
				for(int i=0;i<n;i++){
					cin>>a[i];
					root=createNode(root, a[i]);
				}
				break;
			case 2:
				inorderTraversal(root);
				break;
			case 3:
				BFStraversal(root);
				break;
			case 4:
				DFStraversal(root);
				break;
		}
	}

	return 0;
}
node *createNode(node *root, int n){
	if(root==NULL){
		root=new node;
		root->data=n;
		root->left=root->right=NULL;
	}
	else if(n < root->data)
		root->left=createNode(root->left, n);
	else if(n > root->data)
		root->right=createNode(root->right, n);
	return root;
}
void inorderTraversal(node *root){
	if(root==NULL)
		return;
	else{
		inorderTraversal(root->left);
		cout<<root->data<<" ";
		inorderTraversal(root->right);
	}
}
void BFStraversal(node *root){
	node *p=root;
	if(root==NULL)
		cout<<"TREE is Empty!";
	else{
		Q.push(p);
		while(!Q.empty()){
			p=Q.front();
			Q.pop();
			cout<<p->data<<" ";
			if(p->left!=NULL)
				Q.push(p->left);
			if(p->right!=NULL)
				Q.push(p->right);
		}
	}
}
void DFStraversal(node *root){
	if(root==NULL)
		return;
	else{
		cout<<root->data<<" ";
		if(root->left!=NULL)
			DFStraversal(root->left);
		if(root->right!=NULL)
			DFStraversal(root->right);
	}
}