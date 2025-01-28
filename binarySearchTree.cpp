#include<bits/stdc++.h>

struct Node
{
	int data;
	Node* left;
	Node* right;
	
	Node( int val )
	{
		data = val;
		right = NULL;
		left = NULL;
	}
};

void addToTree( Node* &root, int num )
{
	if ( root == NULL )
	{
		root = new Node( num );
		return;
	}
	
	if ( root->data > num )
		addToTree( root->left, num );
	else
		addToTree( root->right, num );
}

Node* convertToTree( int* arr, int size )
{
	Node* root = NULL;
	for ( int i = 0; i < size; i++ )
	{
		addToTree( root, arr[i] );
	}
	return root;
}
		
void printTree( Node* root )
{
	if ( root == NULL )
		return;
	
	printTree( root->left );
	std::cout<<root->data<<" ";
	printTree( root->right );
}

int main()
{
	int arr[] = { 5, 1, 3, 4, 2, 7, -6, 33, 0, 9, 8, 6 };
	
	Node* root = convertToTree( arr, sizeof(arr)/sizeof(arr[0]) );
	
	printTree( root );
	return 0;
}
	