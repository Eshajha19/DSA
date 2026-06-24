#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildtree() {
    int d;
    cin >> d;
    if (d == -1)
        return NULL;
    node* root = new node(d);
    cout << "Enter data for left of " << root->data << ": ";
    root->left = buildtree();
    cout << "Enter data for right of " << root->data << ": ";
    root->right = buildtree();
    return root;
}

void levelorder(node* root) {
    if (root == NULL)
        return;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        if (temp == NULL) {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

int main() {
    cout << "Enter tree data (-1 for NULL):" << endl;
    node* root = buildtree();
    cout << "\nLevel Order Traversal:\n";
    levelorder(root);
    return 0;
}
