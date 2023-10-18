//For given binary tree, for given target node, find the nodes at dist k
//       1
//      / \
//     2   3
//    /     \
//   4       7
//          / \
//         8   9
//  for target node 3, find the nodes at dist 2 from it 
// Ans is 8, 9, 2.

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

void getTargetNode( node* root, int targetValue, node* &targetNode )
{
    if ( root == NULL )return ;
    if ( root->data == targetValue )
    {
        targetNode = root;
        return;
    }

    getTargetNode( root->right, targetValue, targetNode );
    getTargetNode( root->left, targetValue, targetNode );
}

void getParentChild( node* root, vector<pair<node*, node*>> &parentChild )
{
    queue<node*> q;
    q.push( root );
    while( !q.empty() )
    {
        // node* currNode = root;
        for ( int i = 0; i < q.size(); i++ )
        {
            pair<node*, node*> p;
            if( q.front()->left )
            {
                q.push( q.front()->left );
                p.first = q.front()->left;
                p.second = q.front();
                parentChild.push_back( p );
            }
            if( q.front()->right )
            {
                q.push( q.front()->right );
                p.first = q.front()->right;
                p.second = q.front();
                parentChild.push_back( p );
            }
            q.pop();
        }
    }
}

node* getParentNode( node* root, vector<pair<node*, node*>> parentChild )
{
    for ( int i = 0; i < parentChild.size(); i++ )
    {
        if ( parentChild[i].first == root || parentChild[i].first->data == root->data )
        {
            return parentChild[i].second;
        }
    }
    return NULL;
}

bool visited( node* root, vector<node*> &visitedNodes )
{
    for ( int i = 0; i < visitedNodes.size(); i++ )
    {
        if ( visitedNodes[i] == root ) return true;
    }
    visitedNodes.push_back( root );
    return false;
}

void getNodes( node* root, vector<pair<node*, node*>> parentChild, int k, vector<node*> &visitedNodes )
{
    if ( root == NULL || k < 0 )return;
    if ( k == 0 ){ cout<<root->data<<" "; return; }

    if( root->left && !visited( root->left, visitedNodes ) ) getNodes( root->left, parentChild, k-1, visitedNodes );
    if( root->right && !visited( root->right, visitedNodes ) ) getNodes( root->right, parentChild, k-1, visitedNodes );

    node* parentNode = getParentNode( root, parentChild );

    if( parentNode && !visited( parentNode, visitedNodes ) ) getNodes( parentNode, parentChild, k-1, visitedNodes );
}

void findNodesAtK( node* root, int targetValue, int k )
{
    node* targetNode = NULL;
    getTargetNode( root, targetValue, targetNode );

    vector<pair<node*, node*>> parentChild; // first will be child and then its parent.
    getParentChild( root, parentChild );
    
    vector<node*> visitedNodes;
    visitedNodes.push_back(targetNode);
    getNodes( targetNode, parentChild, k, visitedNodes );
}

int main()
{
    // node* root = new node( 1 );
    // root->left = new node( 2 );
    // root->left->left = new node( 4 );
    // root->right = new node( 3 );
    // root->right->right = new node( 7 );
    // root->right->right->left = new node( 8 );
    // root->right->right->right = new node( 9 );

    node* root = new node( 1 );
    root->left = new node( 5 );
    root->left->left = new node( 6 );
    root->left->left->right = new node( 7 );
    root->left->left->right->left = new node( 8 );
    root->left->left->right->right = new node( 9 );
    root->right = new node( 2 );
    root->right->left = new node( 3 );
    root->right->right = new node( 4 );

    findNodesAtK( root, 5, 3 );
}