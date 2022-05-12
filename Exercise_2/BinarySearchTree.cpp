#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};
Node* createNode (int input){
    Node* temp = new Node;
    temp->data = input;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(Node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->data<<" ";
		inorder(root->right);
	}
}
struct Node* insert (struct Node* node, int key){
    if (node == NULL)
    return createNode (key);
<<<<<<< Updated upstream
    
    if (key <= node->data)
    node->left = insert (node->left, key);
    else node->right = insert (node->right, key);
=======

    if (key < node->data)
    node -> left = insert (node -> left, key);
    else node -> right = insert (node -> right, key);
>>>>>>> Stashed changes
    return node;
}
bool ifNodeExists(struct Node* node, int key)
{
    if (node == NULL)
        return false;

    if (node->data == key)
        return true;

    /* then recur on left subtree */
    bool res1 = ifNodeExists(node->left, key);
    // node found, no need to look further
    if(res1) return true;

    /* node is not found in left,
    so recur on right subtree */
    bool res2 = ifNodeExists(node->right, key);

    return res2;
}
int* create_array(int length)
{
    int b = 500, a= 1;
    srand((unsigned) time(0));
    int* data = (int*) malloc(sizeof(int)*length);
    for (int i=0;i<length;++i)
    {
        data[i]=rand()%(b-a+1)+a;
    }
    return data;
}
int FindMin(Node* root)
{
    while(root->left!=NULL)
        root=root->left; //go to the left until minimum value
    return root->data;
}
Node* Delete(struct Node *root, int data)
{
    if(root==NULL) return root; //empty tree
    else if(data < root->data)
        root->left=Delete(root->left,data);
    else if(data > root->data)
        root->right=Delete(root->right,data);
    else
    {
        //C1: No child
        if(root->left==NULL&&root->right==NULL)
            {
            delete root;
            root=NULL;
            return root;
            }

        //C2: 1 child
        else if(root->left==NULL)
        {
            struct Node *temp=root;
            root=root->right; //make right child new root of subtree
            delete temp;
        }
        else if(root->right==NULL)
        {
            struct Node *temp=root;
            root=root->left; //make left child new root of subtree
            delete temp;
        }

        //C3: 2 children
        else
        {
            int temp= FindMin(root->right); //start from right child of root
            root->data=temp;
            root->right=Delete(root->right,temp);
        }
    }
    return root;
}

void breadth_first_traversal(Node* root){ 
    //print all the element on each level
    if(root == NULL) cout << "This tree is empty stupid";
    else{
        queue<Node*> Q; //why new not work in here ?>??
        Q.push(root);
        while(!Q.empty()){
            Node* current = Q.front();
            cout << current->data << "  ";
            if(current->left != NULL) Q.push(current->left);
            if(current->right != NULL) Q.push(current->right);
            Q.pop();
        }
    }
    cout <<endl;
}
Node* BSTforming(Node *root, int* array, int length)
{
	for (int i=0;i<length;i++)
	{
	    root = insert(root,array[i]);
	}
	return root;
}
int main() {
    Node* root = NULL;

	//Create an array of 25 elements
	int array_length = 25;
	int* random_array = create_array(array_length);
    
    root = BSTforming(root,random_array,array_length);

	//Forming and performing preorder traversal of a 25-node tree
    cout << "Inorder traversal of the given tree:" << endl;
	inorder(root);
    cout <<endl;
    // Delete a value in root;
    root = Delete(root, root->data);
<<<<<<< Updated upstream
    root = Delete(root, root->data);
    root = Delete(root, root->data);
    root = Delete(root, root->data);
    root = Delete(root, root->data);
    root = Delete(root, root->data);
=======
>>>>>>> Stashed changes
    cout << "Inorder traversal of the given tree:" << endl;
    inorder(root);
    return 0;
}
