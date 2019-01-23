// Program to Check if Two Trees are Identical or Not.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(node *, int);
void displayTree(node *);
void compareTree(node *, node *);

void main()
{
	node *root1=NULL, *root2=NULL;
	int n, n1, n2, choice;

	clrscr();

	while(1)
	{
		printf("\n1. Enter Data for Tree 1: ");
		printf("\n2. Enter Data for Tree 2: ");
		printf("\n3. Inorder Traversal of Tree 1: ");
		printf("\n4. Inorder Traversal of Tree 2: ");
		printf("\n5. Compare Both Trees");
		printf("\n6. Exit\n");

		printf("\nEnter your Choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter Data to Insert: ");
				scanf("%d",&n1);
				root1=createNode(root1, n1);
				break;

			case 2:
				printf("\nEnter Data to Insert: ");
				scanf("%d",&n2);
				root2=createNode(root2, n2);
				break;

			case 3:
				printf("\n");
				displayTree(root1);
				printf("\n");
				break;

			case 4:
				printf("\n");
				displayTree(root2);
				printf("\n");
				break;

			case 5:
				compareTree(root1, root2);
				break;
				
			case 6:
				exit(1);
		}
	}
	getch();
}

node *createNode(node *root, int n)
{
	if(root==NULL)
	{
		root=(node *)malloc(sizeof(node));
		root->data=n;
		root->right=NULL;
		root->left=NULL;
	}
	else if(n < root->data)
		root->left=createNode(root->left, n);
	else
		root->right=createNode(root->right, n);

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
void compareTree(node *root1, node *root2)
{
	int flag=0;

	while(root1->right!=NULL && root2->right!=NULL)
	{
		if(root1->data != root2->data)
		{
			flag=1;
			break;
		}
		else
			continue;
	}
	if(flag==0)
		printf("\nTREES are Identical\n");
	else
		printf("\nTREES are not Identical\n");
}