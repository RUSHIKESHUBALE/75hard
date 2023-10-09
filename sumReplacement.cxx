// replace the node with the sum of value of left and right value and value 
// of itself 

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

void sumReplace( node* &root )
{
    if ( root == NULL ) return;

    sumReplace( root->left );
    sumReplace( root->right );

    int lv = 0, rv = 0;

    if ( root->right ) rv = root->right->data;
    if ( root->left ) lv = root->left->data;

    root->data = lv + rv + root->data;
}

void printTree( node* root )
{
    if ( root == NULL ) return ;

    printTree( root -> left );
    
    cout<<root->data<<" ";

    printTree( root -> right );

}

int main()
{
    node* root = new node( 1 );
    root->left = new node( 2 );
    root->right = new node( 3 );
    root->left->left = new node( 4 );
    root->left->right = new node( 5 );

    sumReplace( root );

    printTree( root );
}