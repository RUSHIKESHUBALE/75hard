#include<bits/stdc++.h>

struct Node{
	int data;
	Node* left;
	Node* right;
	
	Node( int val )
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};

int getMaxSumAndPath( Node* root, int & lastNode )
{
	if ( root == NULL )
	{
		return 0;
	}
	
	int leftNode = INT_MIN;
	int rightNode = INT_MIN;
	int sumLeft = getMaxSumAndPath( root->left, leftNode );
	int sumRight = getMaxSumAndPath( root->right, rightNode );
	
	if ( root->left == NULL && root->right == NULL ) 
		lastNode = root->data;
	else
		lastNode = sumLeft > sumRight ? leftNode : rightNode;
	
    int maxSum = std::max( root->data, root->data + std::max( sumLeft, sumRight ) );

    if ( maxSum == root->data )
        lastNode = root->data;
	return maxSum;
}

int main()
{
	Node* root = new Node(1);
    root->left = new Node(-12);
    root->left->left = new Node(4);
    root->right = new Node(3);
    root->right->right = new Node(-6);
    root->right->left = new Node(-5);
	
	int lastNode = INT_MIN;
	int maxSum = getMaxSumAndPath( root, lastNode );
	
	std::cout<<"Max sum: "<<maxSum<<" path: "<<lastNode;
}