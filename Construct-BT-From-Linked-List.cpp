// Construct Binary Tree from Linked List
// Algo => Store Linked List in an Array, and then Convert that Array into Binary Tree

#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode{
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

typedef struct ListNode{
	int data;
	struct ListNode *next;
}ListNode;

ListNode *createList(int *a, int n){

	ListNode *head=NULL, *p;
	for(int i=0;i<n;i++){
		ListNode *temp=(ListNode *)malloc(sizeof(ListNode));
		temp->data=a[i];
		temp->next=NULL;

		if(head==NULL) head=temp;
		else{
			p=head;
			while(p->next!=NULL)
				p=p->next;
			p->next=temp;
		}
	}
	return head;
}

void storeList(ListNode *head, vector <ListNode *> &v){

	while(head!=NULL){
		v.push_back(head);
		head=head->next;
	}
}

TreeNode *createNode(int n){

	TreeNode *root=(TreeNode *)malloc(sizeof(TreeNode));
	root->data=n;
	root->left=NULL;
	root->right=NULL;

	return root;
}

TreeNode *convertIntoBinaryTree(vector <ListNode *> &v, int start, int end){

	if(start > end) return NULL;

	int mid=(start + end)/2;
	TreeNode *root=createNode(v[mid]->data);
	root->left=convertIntoBinaryTree(v,start,mid-1);
	root->right=convertIntoBinaryTree(v,mid+1,end);

	return root;
}

void preOrder(TreeNode *root){

	if(root){
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main(){

	int a[]={1,2,3,4,5,6,7,8};
	int n=sizeof(a)/sizeof(int);
	ListNode *head=createList(a,n);

	vector <ListNode *> v;
	storeList(head,v);

	TreeNode *root=NULL;
	int start=0;
	int end=v.size()-1;
	root=convertIntoBinaryTree(v,start,end);
	preOrder(root);

	return 0;
}