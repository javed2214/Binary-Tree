// Program to Delete Leaf Nodes from a Binary Search Tree.

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
node *deleteNode(node *root);

void main()
{
	node *root=NULL;
	int choice, n;

	clrscr();

	while(1)
	{
		printf("\n1. Press 1 to Create Node");
		printf("\n2. Inorder Traversal");
		printf("\n3. Delete Leaf Nodes");
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
				root=deleteNode(root);
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
node *deleteNode(node *root)
{
	if(root==NULL)
		return 0;

	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			free(root);
			return 0;
		}
		
		root->left=deleteNode(root->left);
		root->right=deleteNode(root->right);
	}

	return root;
}