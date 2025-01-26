#include<bits/stdc++.h>

struct Node 
{
	int data;
	Node* right;
    Node* left;
	
	Node( int val )
	{
		data = val;
		right = NULL;
		left = NULL;
	}
};

void printSubTreeNodesAtDist( Node* root, int k )
{
	if ( root == NULL || k < 0 )
		return;
	
	if ( k == 0 ) 
		std::cout<<root->data<<" ";
	printSubTreeNodesAtDist( root->left, k-1 );
	printSubTreeNodesAtDist( root->right, k-1 );
}

int printNodesAtDist( Node* root, Node* target, int k )
{
	if ( root == NULL || k < 0 )
		return 0;
	
	if ( root->data == target->data )
	{
		printSubTreeNodesAtDist( root, k );
		return 1;
	}
	
	int leftFound = printNodesAtDist( root->left, target, k );
	if ( leftFound > 0 )
    {
        if ( k-leftFound == 0 )
            std::cout<<root->data<<" ";
        else
        {
            printSubTreeNodesAtDist( root->right, k-leftFound -1 );
            return leftFound+1;
        }
    }
	int rightFound = printNodesAtDist( root->right, target, k );
	if ( rightFound > 0 )
    {
        if ( k-rightFound == 0 )
            std::cout<<root->data<<" ";
        else{
            printSubTreeNodesAtDist( root->left, k-rightFound -1 );
            return rightFound+1;
        }
    }

	return 0;
}

int main()
{
	Node* root  = new Node(1);
    root->left = new Node(5);
    root->left->left  = new Node(6);
    root->left->left->right  = new Node(7);
    root->left->left->right->left  = new Node(8);
    root->left->left->right->right  = new Node(9);
    root->right = new Node(2);
    root->right->left = new Node(3);
    root->right->right = new Node(4);
	
	int a = printNodesAtDist( root, root->right->left, 4 );

    a +=1;
}