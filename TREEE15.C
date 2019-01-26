// Program to Find Inorder Successor of any Specific Node without Traversing the Whole Tree.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(node *root, int);
void traverse(node *root);
node *searchNode(node *root, int);
void inorderSuccessor(node *root, int n);

void main()
{
	node *root=NULL;
	int choice, n, x;

	clrscr();

	while(1)
	{
		printf("\n1. Press 1 to Create Node");
		printf("\n2. Inorder Traversal");
		printf("\n3. Inorder Successor");
		printf("\n4. Exit");

		printf("\n\nEnter your Choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter Data to Insert: ");
				scanf("%d",&n);
				root=createNode(root, n);
				break;

			case 2:
				printf("\n");
				traverse(root);
				printf("\n");
				break;

			case 3:
				printf("\nEnter Node of which You Want to Find Inorder Predecessor: ");
				scanf("%d",&x);
				inorderSuccessor(root, x);
				break;

			case 4:
				exit(1);
		}
	}
}
node *createNode(node *root, int n)
{
	if(root==NULL)
	{
		root=(node *)malloc(sizeof(node));
		root->data=n;
		root->left=NULL;
		root->right=NULL;
	}
	else if(n < root->data)
	{
		root->left=createNode(root->left, n);
	}
	else if(n > root->data)
	{
		root->right=createNode(root->right, n);
	}
	else
	{
		printf("\nDuplicate Nodes!");
		delay(1000);
		exit(1);
	}
	return root;
}
void traverse(node *root)
{
	if(root==NULL)
	    return;
	else
	{
		traverse(root->left);
		printf("%d\t",root->data);
		traverse(root->right);
	}
}
node *searchNode(node *root, int x)
{
	node *p=NULL;
	if(root==NULL)
		return 0;

	if(x==root->data)
	{
		p=root;
		return p;
	}

	else if(x < root->data)
		searchNode(root->left, x);

	else if(x > root->data)
		searchNode(root->right, x);
}
void inorderSuccessor(node *root, int n)
{
	node *q, *temp, *r;
	r=root;
	q=searchNode(root,n);
	if(q!=NULL)
	{
		if(q->right!=NULL)
		{
			temp=q->right;
			while(temp->left!=NULL)
				temp=temp->left;
			printf("\nInorder Successor of %d is: %d\n",n,temp->data);
		}
		if(q->left==NULL)
		{
			while(q->data!=r->data)
			{
				if(q->data <= r->data)
				{
					temp=r;
					r=r->left;
				}
				else
					r=r->right;
			}
			printf("\nInorder Successorr of %d is: %d\n",n,temp->data);
		}
	}
	else
		printf("\nNode Not Found!\n");
}