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

void getNodes( node* root, int &totalNodes )
{
    if ( root == NULL )
    {
        return ;
    }

    totalNodes++;

    getNodes( root->left, totalNodes );
    getNodes( root->right, totalNodes );
    
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

    int totalNodes = 0;
    getNodes( root, totalNodes );

    cout<<totalNodes;

}