// Count Subtree that Sum up to a Given Value K
// https://www.geeksforgeeks.org/count-subtress-sum-given-value-x/

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

node *createNode(int x){

    node *temp = (node *)malloc(sizeof(node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

int subtreeSum(node *root, int k, int &cnt){

    if(root == NULL) return 0;
    int x = root->data;
    x += subtreeSum(root->left, k, cnt);
    x += subtreeSum(root->right, k, cnt);
    if(x == k) cnt += 1;
    return x;
}

int main(){

    node *root = createNode(5);
    root->left = createNode(-10);
    root->right = createNode(3);
    root->left->left = createNode(9);
    root->left->right = createNode(8);
    root->right->left = createNode(-4);
    root->right->right = createNode(7);

    int k = 7, cnt = 0;

    subtreeSum(root, k, cnt);
    cout << cnt;

    return 0;
}