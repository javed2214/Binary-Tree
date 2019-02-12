// Program to Convert Binary Search Tree to Doubly Linked List (Not Completed Yet).

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
void traverseTree(node *root);
void convert(node *, node *);

void main()
{
	node *root=NULL;
	node *head=NULL;
	int choice, n, x;

	clrscr();

	while(1)
	{
		printf("\n1. Create Node");
		printf("\n2. Inorder Traversal of Tree");
		printf("\n3. Convert into Doubly Linked List");
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
				traverseTree(root);
				printf("\n");
				break;

			case 3:
				printf("\n");
				convert(root, head);
				printf("\n");
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
void traverseTree(node *root)
{
	if(root==NULL)
	    return;
	else
	{
		traverseTree(root->left);
		printf("%d\t",root->data);
		traverseTree(root->right);
	}
}
void convert(node *root, node *head)
{
	node *p=root;
	static node *prev=NULL;

	if(p==NULL)
		return;

	convert(p->left, head);
	if(head==NULL)
		head=p;
	else
	{
		p->left=prev;
		prev->right=p;
	}
	printf("<=[%d]=>",p->data);
	prev=p;
	convert(p->right, head);
}
