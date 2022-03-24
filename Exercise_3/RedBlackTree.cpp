#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node {
    int data;
    int isRed;
    Node *left, *right, *parent;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = this->parent = NULL;
        this->isRed = 1;
    }
};

class RBTree {
private:
    Node *root;

protected:
    void rotateLeft(Node *&root, Node *&pt);
    void rotateRight(Node *&root, Node *&pt);
    void fixTree(Node *&root, Node *&pt);

public:
    RBTree()
    {
        root = NULL;
    }
    void insert(int data);
    void levelOrder();
    void inOrder();
    void search(int key);
};

Node *insertUtil(Node *&root, Node *&pt)
{
    if (root == NULL)
        return pt;
    if (root->data >= pt->data) {
        root->left = insertUtil(root->left, pt);
        root->left->parent = root;
    }
    else {
        root->right = insertUtil(root->right, pt);
        root->right->parent = root;
    }
    return root;
}

void RBTree::insert(int data)
{
    Node *pt = new Node(data);
    root = insertUtil(root, pt);
    fixTree(root, pt);
}

void RBTree::rotateRight(Node *&root, Node *&pt)
{
    Node *pt_left = pt->left;
    pt->left = pt_left->right; // set right child of pt_left as left child of pt
    if (pt->left != NULL) {    // check if right child of pt_left is NULL if not then set pt as parent of it
        pt->left->parent = pt;
    }
    pt_left->parent = pt->parent;
    if (pt->parent == NULL) {
        root = pt_left;
    }
    else if (pt_left->parent->left == pt) // if the parent of pt is not NULL and pt is the left child of its parent
    {
        pt_left->parent->left = pt_left; // set new child
    }
    else // if pt is the right child of its parent
    {
        pt_left->parent->right = pt_left;
    }
    pt_left->right = pt; // now set pt as right child of pt_left
    pt->parent = pt_left;
}

void RBTree::rotateLeft(Node *&root, Node *&pt)
{
    Node *pt_right = pt->right;
    pt->right = pt_right->left;
    if (pt->right != NULL) {
        pt->right->parent = pt;
    }
    pt_right->parent = pt->parent;
    if (pt_right->parent == NULL) {
        root = pt_right;
    }
    else if (pt_right->parent->left == pt) {
        pt_right->parent->left = pt_right;
    }
    else {
        pt_right->parent->right = pt_right;
    }
    pt_right->left = pt;
    pt->parent = pt_right;
}

void RBTree::fixTree(Node *&root, Node *&pt)
{
    Node *pt_parent = NULL;
    Node *pt_grandparent = NULL;
    while ((pt != root) && (pt->isRed == 1) && (pt->parent->isRed == 1)) {
        pt_parent = pt->parent;
        pt_grandparent = pt_parent->parent;
        if (pt_parent == pt_grandparent->left) {
            Node *pt_aunt = pt_grandparent->right;
            if (pt_aunt != NULL && pt_aunt->isRed == 1) {
                pt_grandparent->isRed = 1;
                pt_parent->isRed = 0;
                pt_aunt->isRed = 0;
                pt = pt_grandparent;
            }
            else {
                if (pt == pt_parent->right) {
                    rotateLeft(root, pt_parent);
                    pt = pt_parent;
                    pt_parent = pt->parent;
                }
                rotateRight(root, pt_grandparent);
                swap(pt_grandparent->isRed, pt_parent->isRed);
                pt = pt_parent;
            }
        }
        else {
            Node *pt_aunt = pt_grandparent->left;
            if (pt_aunt != NULL && pt_aunt->isRed == 1) {
                pt_grandparent->isRed = 1;
                pt_parent->isRed = 0;
                pt_aunt->isRed = 0;
                pt = pt_grandparent;
            }
            else {
                if (pt == pt_parent->left) {
                    rotateRight(root, pt_parent);
                    pt = pt_parent;
                    pt_parent = pt->parent;
                }
                rotateLeft(root, pt_grandparent);
                swap(pt_grandparent->isRed, pt_parent->isRed);
                pt = pt_parent;
            }

        }
    }
    root->isRed = 0;
}

void levelOrderUtil(Node *root){
    if(root == NULL) cout << "This tree is empty stupid";
    else{
        queue<Node*> Q; //why new not work in here ?>??
        Q.push(root);
        while(!Q.empty()){
            Node* current = Q.front();
            string a;
            if(current->isRed) a = "(R)";
            else a = "(B)";
            cout << current->data << a << "  " ;
            if(current->left != NULL) Q.push(current->left);
            if(current->right != NULL) Q.push(current->right);
            Q.pop();
        }
    }
    cout <<endl;
}

void inOrderUtil(Node *root){
    string a = "(B)";
    if(root == NULL) return;
    inOrderUtil(root->left);
    if(root->isRed) a = "(R)";
    cout << root->data << a << "  ";
    inOrderUtil(root->right);
}
int search_bst(Node* root, int key){
    if(root == NULL) return 0;
    else if(root->data == key) return 1;
    else if(root->data > key) return search_bst(root->left, key);
    else return search_bst(root->right, key);
}

void RBTree::search(int key){
    cout << endl;
    int ans = search_bst(root, key);
    if(ans) cout << "The tree have this value!" << endl;
    else cout << "the value " << key << " not found in the tree!" << endl;
}
void RBTree::levelOrder(){
    levelOrderUtil(root);
}
void RBTree::inOrder(){
    inOrderUtil(root);
}
int main()
{
    cout << "Note: "<< endl << "B: Black, R: Red" << endl;
    RBTree tree;
    tree.insert(7);
    tree.insert(69);
    tree.insert(68);
    tree.insert(96);
    tree.insert(45);
    tree.insert(5);
    tree.insert(42);
    tree.insert(32);
    tree.insert(21);
    tree.insert(10);
    tree.insert(12);
    tree.insert(9);
    tree.insert(3);
    cout << "\nLevel Order Traversal of Created Tree\n";
    tree.levelOrder();
    tree.search(6);
    tree.search(8);
    cout << "\nIn Order Traversal of Created Tree\n";
    tree.inOrder();
    return 0;
}
