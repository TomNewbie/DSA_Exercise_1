// Search a node of binary tree
#include <iostream>
using namespace std;
 
// Binary tree node
struct Node {
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
 
// Function to traverse the tree in preorder and check if the given node exists in it
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
 
int main()
{
    struct Node* root = new Node(5);
    root->left = new Node(8);
    root->left->left = new Node(9);
    root->left->left->left = new Node(0);
    root->left->right = new Node(1);
    root->left->right->left = new Node(24);
    root->left->right->right = new Node(20);
    root->right = new Node(15);
 
    int key = 4;
 
    if (ifNodeExists(root, key))
        cout << "Binary tree has node " << key;
    else
        cout << "Binary tree don't have node " << key;
 
    return 0;
}
