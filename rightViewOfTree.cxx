// for given binary tree print all the nodes if seen from right side of tree
//    1
//   / \
//  2   3
// Here nodes visible from right are 1 and 3

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

void getRightView( node* root )
{
   queue<node*> q;
   q.push( root );

   while( !q.empty() )
   {
        int n = q.size();
        for ( int i = 0; i < n; i++ )
        {
            if ( i == n - 1 )
            {
                cout<<q.front()->data<<" ";
            }
            if( q.front()->left ) q.push( q.front()->left );
            if( q.front()->right ) q.push( q.front()->right );
            q.pop();
        }
   } 
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

    getRightView( root );
}