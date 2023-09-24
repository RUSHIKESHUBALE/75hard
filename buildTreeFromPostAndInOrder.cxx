#include<bits/stdc++.h>
using namespace std;

struct node
{
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

node* buildTree( vector<int> postOrder, vector<int> inOrder, int start, int end )
{
    static int indx = postOrder.size() -1;

    if ( start > end || indx < 0 ) return NULL;

    int current = postOrder[indx];
    node* root = new node( current );

    indx--;

    if ( start == end ) return root;

    int pos = -1;

    for ( int i = start; i <= end; i++ )
    {
        if ( inOrder[i] == current )
        {
            pos = i;
            break;
        }
    }

    if ( pos == -1 ) return NULL;

    root->right = buildTree( postOrder, inOrder, pos + 1, end );
    root->left = buildTree( postOrder, inOrder, start, pos -1 );

    return root;
}

void printPostOrder( node* root )
{
    if ( root == NULL ) return ;

    printPostOrder( root->left );
    printPostOrder( root->right );
    cout<<root->data<<" ";
}

void printInOrder( node* root )
{
    if ( root == NULL ) return ;

    printInOrder( root->left );
    cout<<root->data<<" ";
    printInOrder( root->right );
}

int main()
{
    vector<int> postOrder = { 4, 2, 5, 3, 1 };
    vector<int> inOrder = { 4, 2, 1, 5, 3 };

    node* root = buildTree( postOrder, inOrder, 0, inOrder.size() -1 );

    printPostOrder( root );
    cout<<endl;
    printInOrder( root );

}