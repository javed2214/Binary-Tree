// TREE Data Structure Implementation

#include<stdio.h>
#include<conio.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(node *, int);
void displayTree(node *);

void main()
{
	int choice, n;
	node *root=NULL;

	while(1)
	{
		printf("\n1. Enter 1 for Insertion");
		printf("\n2. Enter 2 for Preorder Traversal");
		printf("\n3. Exit\n");

		printf("\nEnter your Choice: ");
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
				displayTree(root);
				break;

			case 3:
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
	else if(n <= root->data)
	{
		root->left=createNode(root->left, n);
	}
	else
	{
		root->right=createNode(root->right, n);
	}
	return root;
}
void displayTree(node *root)
{
	if(root==NULL)
		return;
	else
	{
		printf("%d\t",root->data);
		displayTree(root->left);
		displayTree(root->right);
	}
}
