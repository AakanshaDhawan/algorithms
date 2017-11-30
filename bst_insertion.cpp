#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};
 
Node* newNode(int key)
{
	Node* node = new Node;
	node->data = key;
	node->left = node->right = NULL;
 
	return node;
}
 
 void inorder(Node* root)
{
	if (root == NULL)
		return;
 
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
 

void insertIterative(Node*& root, int key)
{

	Node *curr = root;

	Node *parent = NULL;
	if (root == NULL)
	{
		root = newNode(key);
		return;
	}
 	while (curr != NULL)
	{
		parent = curr;
        if (key < curr->data)
			curr = curr->left;
		else
			curr = curr->right;
	}
	if (key < parent->data)
		parent->left = newNode(key);
	else
		parent->right = newNode(key);
}
 
// main function
int main()
{
	Node* root = NULL;
	int keys[] = { 15, 10, 20, 8, 12, 16, 25 }; 
	for (int key=0;key<7;key++)
		insertIterative(root, keys[key]);
 	inorder(root);
 	return 0;
}
 
