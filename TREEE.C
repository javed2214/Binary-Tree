// TREE Fundamentals.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int n, node *root);
void displayTree(node *root);

void main()
{
	int n, choice;
	node *root=NULL;

	clrscr();

	while(1)
	{
		printf("\n1. Create Node\n");
		printf("2. Display Tree\n");
		printf("3. Exit\n");
		printf("\nEnter your Choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter Data to Insert: ");
				scanf("%d",&n);
				root=createNode(n,root);
				break;

			case 2:
				printf("\n");
				displayTree(root);
				printf("\n");
				break;

			case 3:
				exit(1);
		}
	}
	getch();
}
node *createNode(int n, node *root)
{
	if(root==NULL)
	{
		root=(node *)malloc(sizeof(node));
		root->data=n;
		root->right=NULL;
		root->left=NULL;
	}
	else if(n < root->data)
		root->left=createNode(n, root->left);
	else if(n > root->data)
		root->right=createNode(n, root->right);
	else
		printf("\nDuplicate Node\n");

	return root;
}
void displayTree(node *root)
{
	if(root==NULL)
		return;
	else
	{
		displayTree(root->left);
		printf("%d\t",root->data);
		displayTree(root->right);
	}
}