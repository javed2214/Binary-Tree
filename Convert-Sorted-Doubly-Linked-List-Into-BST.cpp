// Convert Sorted Doubly Linked List into Balanced BST
// https://www.techiedelight.com/construct-height-balanced-bst-from-sorted-doubly-linked-list/
// https://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/
// EPI Page No - 448

#include<bits/stdc++.h>
using namespace std;

struct node{

	int data;
	struct node *left;
	struct node *right;
};

node *createDLL(int *a, int n){

	node *head = NULL, *p = head;

	for(int i=0;i<n;i++){

		node *temp = (node *)malloc(sizeof(node));
		temp->data = a[i];
		temp->left = NULL;
		temp->right = NULL;

		if(head == NULL) head = temp, p = head;
		else{
			p->right = temp;
			temp->left = p;
			p = temp;
		}
	}
	return head;
}

void printList(node *head){

	while(head){

		cout<<head->data<<"<=>";
		head = head->right;
	}
	cout << endl;
}

void inorder(node *root){

	if(root){

		cout<<root->data<<" ";
		inorder(root->left);
		inorder(root->right);
	}
}

node *sortedDLLtoBST(node *&headRef, int n){

	if(n <= 0) return NULL;

	node *leftSubtree = sortedDLLtoBST(headRef, n / 2);

	node *root = headRef;
	root->left = leftSubtree;
	headRef = headRef->right;

	root->right = sortedDLLtoBST(headRef, n - (n / 2 + 1));

	return root;	
}

int main(){

	int a[] = {1,2,3,4,5,6,7,8};
	int n = sizeof(a) / sizeof(int);

	node *head = createDLL(a,n);

	printList(head);

	node *root = sortedDLLtoBST(head, n);

	inorder(root);

	return 0;
}