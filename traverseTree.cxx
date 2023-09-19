// Day 1
// Traverse through the tree. Whole left branch first then root and then right branch


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

void preOrderTree( node* root )
{
   if ( root == NULL)
   {
      return ;
   }
   preOrderTree( root->left );
   cout<<root->data<<" ";
   preOrderTree( root->right );
}

int main()
{
   node* root = new node( 1 );
   root->left = new node( 2 );
   root->right = new node( 3 );
   root->left->left = new node( 4 );
   root->left->right = new node( 5 );
   root->right->left = new node( 6 );
   root->right->right = new node( 7 );

   preOrderTree( root );
}