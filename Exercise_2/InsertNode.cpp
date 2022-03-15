#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    struct Node *left, *right;
};
struct Node* createNode (int input){
    Node* temp = new Node;
    temp -> key = input;
    temp -> left = temp -> right = NULL;
    return temp;
}

struct Node* insert (struct Node* node, int key){
    if (node == NULL)
    return createNode (key);
    
    if (key < node->key)
    node -> left = insert (node -> left, key);
    else node -> right = insert (node -> right, key);
    return node;
}

int main() {
    Node* root = NULL;
    root = insert (root, 13);
    root = insert (root, 6);
    root = insert (root, 15);
    root = insert (root, 17);
    root = insert (root, 20);
    root = insert (root, 9);
    root = insert (root, 4);
    root = insert (root, 3);
    root = insert (root, 7);
    root = insert (root, 2);
    return 0;
}
