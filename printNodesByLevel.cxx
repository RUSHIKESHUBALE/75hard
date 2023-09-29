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

void printTreeByLevel( node* root, int k, vector< pair< int, int> > &ans )
{
    if ( root == NULL ) return ;

    // cout<<"Level: "<<k<<" Value: "<<root->data<<endl;
    pair<int, int> node;
    node.first = k;
    node.second = root->data;
    ans.push_back(node);

    k++;

    printTreeByLevel( root->left, k, ans ); 
    printTreeByLevel( root->right, k, ans ); 
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

    vector< pair<int, int> > ans;

    printTreeByLevel( root, 0, ans );

    auto customCompare = [] ( const pair<int, int> &a, const pair<int, int> &b){
        return a.first < b.first;
    };

    sort( ans.begin(), ans.end(), customCompare );
    int curr = ans[0].first;

    for ( int i = 0; i < ans.size(); i++ )
    {
        if ( curr != ans[i].first )
        {
            curr = ans[i].first;
            cout<<endl;
        }
        cout<<ans[i].second<<", ";
    }
}