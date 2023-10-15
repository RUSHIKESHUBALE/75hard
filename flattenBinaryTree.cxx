// Given binary tree
//       1
//      / \
//     2   3
//    /    /\
//   4    6  7
//
// after flattening 1->2->4->3->6->7
// Convert the same tree to linkedlist

#include<bits/stdc++.h>
using namespace std;

struct node{
    node* right;
    node* left;
    int data;

    node( int val )
    {
        left = NULL;
        right = NULL;
        data = val;
    }
};

node* flattenTree( node* &root )
{
    if ( root == NULL ) return NULL;
    
    node* newLeftNode = NULL ; node* newRightNode = NULL;

    if ( root->left ) newLeftNode = flattenTree( root->left ); 
    if ( root->right ) newRightNode = flattenTree( root->right ); 

    root->right = newLeftNode;
    node* temp = root;
    while( temp->right )
    {
        temp = temp->right;
    }
    temp->right = newRightNode;

    root->left = NULL;

    return root;
}

void printTree( node* root )
{
    while( root != NULL )
    {
        cout<<root->data<<"-> ";
        root = root->right;
    }
}

int main()
{
    node* root = new node( 1 );
    root->left = new node( 2 );
    root->left->right = new node( 8 );
    root->left->right->left = new node( 9 );
    root->left->right->right = new node( 10 );
    root->left->left = new node( 4 );
    root->right = new node( 3 );
    root->right->left = new node( 6 );
    root->right->right = new node( 7 );

    node* newRoot = flattenTree( root );
    printTree( root );
}