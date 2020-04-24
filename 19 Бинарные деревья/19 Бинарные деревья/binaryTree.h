#include <iostream>

using namespace std;

struct Node {
    Node *left, *right;
    int data;
};


void add(int x, Node*& root) {
    if (NULL == root) {
        root = new Node;
        root -> data = x;
        root -> left = root -> right = NULL;
        return;
    }
    
    if (x > root -> data) add(x, root -> right);
    else add(x, root -> left);
}


void print(Node*& root, int lvl = 0) {
    if (root -> right != 0) print(root -> right, lvl + 1);
    for (int i = 0; i < lvl; ++i) cout << "    ";
    cout << root->data << endl;
    if (root->left != 0)    print(root->left, lvl + 1);
}

void sumRecourse(Node *&root, long &sum, int &count) {
    if(!root) return;
    sum = sum + root -> data;
    count++;
    sumRecourse(root -> left, sum, count);
    sumRecourse(root -> right, sum, count);
}

long sum(Node *&root) {
    long sum = 0;
    int count = 0;
    sumRecourse(root, sum, count);
    return sum / count;
}
