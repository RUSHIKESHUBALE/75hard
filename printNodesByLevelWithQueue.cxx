// For a given binary tree, print the nodes level by level
//       1
//      / \
//     2   3
//    /    /\
//   4    6  7
//  ans will be : 1, 
//                2, 3, 
//                4, 6, 7

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

void printTreeByLevel( node* root )
{
    if ( root == NULL ) return ;
    queue< node* > q;
    q.push( root );
    q.push( NULL );

    while( !q.empty() )
    {
        if ( q.front() != NULL )
        {
            cout<<q.front()->data<<" ";

            if ( q.front()->left != NULL )
            {
                q.push( q.front()->left );
            }
            if ( q.front()->right != NULL )
            {
                q.push( q.front() -> right );
            }
            q.pop();
        }
        else{
            cout<<endl;
            q.pop();
            if ( !q.empty( ) ) q.push( NULL );
            
        }
    }


}

int main()
{
    node* root = new node( 1 );
    root->left = new node( 2 );
    root->right = new node( 3 );
    root->left->left = new node( 4 );
    root->right->left = new node( 5 );
    root->left->left->left = new node( 7 );
    root->right->right = new node( 6 );
    root->right->left->left = new node( 8 );

    queue<int> q;

    printTreeByLevel( root );


}