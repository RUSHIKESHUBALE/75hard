// Build a tree from PreOrder and Inorder 
// Given Preorder array 1 2 4 3 6 7 and 
// Inorder array        4 2 1 6 3 7
// Build a tree from that 
//       1
//      / \
//     2   3
//    /    /\
//   4    6  7


#include<bits/stdc++.h>
using namespace std;

struct node
{
    node* right;
    node* left;
    int data;

    node( int val )
    {
        right = NULL;
        left = NULL;
        data = val;
    }
};


node* buildTree( vector<int> preOrder, vector<int> inOrder, int start, int end )
{
    static int i = 0;
    
    if ( start > end || i == preOrder.size() )
    {
        return NULL;
    }

    node* root = new node( preOrder[i] );
    int current = preOrder[i];
    i++;

    if ( start == end ) return root;

    int pos = -1;
    for ( int j = start; j <= end; j++ )
    {
        if( current == inOrder[j] )
        {
            pos = j;
            break;
        }
    }

    if( pos == -1 ) return NULL;

    root->left = buildTree( preOrder, inOrder, start, pos-1 );
    root->right = buildTree( preOrder, inOrder, pos+1, end );

    return root;
}

void buildPre( node* root )
{
    if ( root == NULL ) return ;
    cout<<root->data<<" ";
    buildPre( root->left );
    buildPre( root->right );
}

void printInOrder( node* root )
{
    if ( root == NULL ) return;

    printInOrder( root->left );
    cout<<root->data<<" ";
    printInOrder( root->right );
}


int main()
{
    vector<int> preOrder = { 1, 2, 4, 3, 6, 7 };
    vector<int> inOrder = { 4, 2, 1, 6, 3, 7 };

    node* root = buildTree( preOrder, inOrder, 0, inOrder.size()-1 );

    buildPre( root );
    cout<<endl;
    printInOrder( root );
}