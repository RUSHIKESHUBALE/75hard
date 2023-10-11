// Find the shortest path between two given nodes

#include<bits/stdc++.h>
using namespace std;

struct node{
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

node* getLCA( node* root, int n1, int n2 )
{
    if ( root == NULL ) return NULL;

    if ( root->data == n1 || root->data == n2 ) return root;

    // check if you can find the given node 
    node* lr = getLCA( root->left, n1, n2 );
    node* rr = getLCA( root->right, n1, n2 );

    if ( lr == NULL && rr == NULL ) return NULL; // if given nodes not found on either side return null

    else if ( lr != NULL && rr != NULL ) return root; // if given nodes found on opposite sides then root is common ancester

    else if ( lr == NULL && rr != NULL ) return rr; // if given nodes found on right side

    else{
        return lr; // if given nodes found on left sides 
    }

}

int distTillGivenNode( node* root, int n1, int dist )
{
    if ( root == NULL ) return -1;

    if ( root->data == n1 )
    {
        return dist;
    }
    
    int lh = distTillGivenNode( root->left, n1, dist+1 );
    int rh = distTillGivenNode( root->right, n1, dist+1 );

    return max( lh, rh );
}

int main()
{
    node* root = new node( 1 );
    root->left = new node( 2 );
    root->right = new node( 3 );
    root->right->left = new node( 5 );
    root->right->left->left = new node( 7 );
    root->right->right = new node( 6 );
    root->left->left = new node( 4 );

    node* lowestCommonAncestor = getLCA( root, 7, 6 );
    int d1 = distTillGivenNode( lowestCommonAncestor, 7, 0 );
    int d2 = distTillGivenNode( lowestCommonAncestor, 6, 0 );

    cout<<d1+d2<<endl;
}