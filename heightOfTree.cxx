// For given binary tree count the number of nodes present 

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

int getHeight( node* root, int height )
{
    if ( root == NULL ) return height ;

    height++;

    int leftHeight = getHeight( root->left, height );
    int rightHeight = getHeight( root->right, height );

    return max( leftHeight, rightHeight );
}

int main()
{
    node* root = new node( 51 );
    root->left = new node( 25 );
    root->right = new node( 03 );
    root->left->left = new node( 5354 );
    root->left->left->left = new node( 535465464 );
    root->right->right = new node( 37 );
    root->right->left = new node( 653 );
    root->right->left->left = new node( 565464 );

    int height = getHeight( root, 0 );

    cout<<height<<endl;

}