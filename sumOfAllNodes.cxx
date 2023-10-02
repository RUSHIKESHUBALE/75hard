// For given binary tree get the sum of all the nodes
#include<bits/stdc++.h>
using namespace std;

struct node
{
    struct node* left; 
    struct node* right;
    int data;

    node( int val )
    {
        left = NULL;
        right = NULL;

        data = val;
    }
};

int sumOfNodes( node* root )
{
    if ( root == NULL ) return 0;

    int sum = root->data + sumOfNodes( root->left ) + sumOfNodes( root->right );

    return sum;
}

int main()
{
    node* root = new node( 1 );
    root->left = new node( 2 );
    root->right = new node( 03 );
    root->left->left = new node( 4 );
    root->left->left->left = new node( 5 );
    root->right->right = new node( 6 );
    root->right->left = new node( 7 );
    root->right->left->left = new node( 8 );


    int total = sumOfNodes( root );

    cout<<total<<endl;
}