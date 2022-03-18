#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int a=1;
int b=500;

//Forming the basic structure of the tree
struct node 
{
	int key;
	struct node *left, *right;
};

// A utility function to allocate memory and define a new BST node
struct node *newNode(int item)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
	if (root != NULL) 
	{
		inorder(root->left);
		cout << root->key<<" ";
		inorder(root->right);
	}
}

// A utility function to allocate memory and create
// array of randomized integer values
int* create_array(int length)
{
    srand((unsigned) time(0));
    int* data = (int*) malloc(sizeof(int)*length);
    for (int i=0;i<length;++i)
    {
        data[i]=rand()%(b-a+1)+a;
    }
    return data;
}

// A utility function to insert a new node 
// with given key in BST
struct node *insert(struct node *node, int key)
{
	//return a new node should the tree be empty
	if (node == NULL)
		return newNode(key);

	//recur down the tree if otherwise
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	//return the (unchanged) node pointer
	return node;
}

// A utility function forming a binary search tree from a
// given array of randomized elements by using Insertion method
struct node* BSTforming(struct node *root, int* array, int length)
{
	for (int i=0;i<length;i++)
	{
	    root = insert(root,array[i]);
	}
	return root;
}

// Driver Code
int main()
{
	//Setting the root of the tree
	struct node* root = NULL;

	//Create an array of 25 elements
	int array_length = 25;
	int* random_array = create_array(array_length);

	//Forming and performing preorder traversal of a 25-node tree
    root = BSTforming(root,random_array,array_length);
	cout << "Inorder traversal of the given tree:" << endl;
	inorder(root);
	cout << endl;
	system("pause");
	return 0;
}
