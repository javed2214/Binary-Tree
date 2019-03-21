// Convert Binary Tree into DLL Traversing Level by Level

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

void convertIntoDLL(node *root, node **head){

	queue <node *> q;
	node *p;
	q.push(root);
	while(!q.empty()){
		node *temp=q.front();
		q.pop();
		if(*head==NULL){
			*head=createNode(temp->data);
			p=*head;
		}
		else{
			node *t=createNode(temp->data);
			p->right=t;
			t->left=p;
			p=t;
		}
		if(temp->left) q.push(temp->left);
		if(temp->right) q.push(temp->right);
	}
}

void printList(node *head){

	while(head){
		cout<<head->data<<"<=>";
		head=head->right;
	}
}

int main(){

	node *root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->left->right=createNode(5);
	root->right->left=createNode(6);
	root->right->right=createNode(7);

	node *head=NULL;
	convertIntoDLL(root,&head);

	printList(head);

	return 0;
}