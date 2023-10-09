// get the maximum diameter possible in the tree
// for tree given
//             1
//            / \
//           2   3
//              /\
//             4  5
//            /    \
//           6      7
// for this tree longest diameter is 6,4,3,5,7 so ans is 5.

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

int getLHeight( node* root )
{
    if ( root == NULL )
    {
        return 0;
    }
    return getLHeight( root->left ) + 1;
}

int getRHeight( node* root )
{
    if ( root == NULL )
    {
        return 0;
    }
    return getRHeight( root->right ) + 1;
}

int getDiameterOfTree( node* root )
{
    if ( root == NULL )
    {
        return 0;
    }

    int lh = getLHeight( root->left );
    int rh = getRHeight( root->right );
    cout<<"lh: "<<lh<<" rh: "<<rh<<endl;

    return max ( max(lh + rh +1, getDiameterOfTree( root->left )), getDiameterOfTree( root->right ));
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

    int dia = getDiameterOfTree( root );

    cout<<dia<<endl;
}