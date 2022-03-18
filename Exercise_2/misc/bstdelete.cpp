#include <iostream>
using namespace std;



struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
int FindMin(Node* root)
{
    while(root->left!=NULL)
        root=root->left; //go to the left until minimum value
    return root->data;
}
struct Node* Delete(struct Node *root, int data)
{
    if(root==NULL) return root; //empty tree
    else if(data<root->data)
        root->left=Delete(root->left,data);
    else if(data>root->data)
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
};
