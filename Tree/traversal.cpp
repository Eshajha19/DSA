// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include<queue>
class node{
    public:
       int data;
       node*left;
       node*right;
       node(int d){
           this->data=d;
           this->left=NULL;
           this->right=NULL;
       }
};
node *buildtree(){
    int data;
    cin>>data;
    if(data==-1)
      return NULL;
    node*root=new node(data);
    cout<<"Enter data for left of "<<root->data<<":";
    root->left=buildtree();
    cout<<"Enter data for right of "<<root->data<<":";
    root->right=buildtree();
    return root;
}
void levelorder(node *root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty())
              q.push(NULL);
        }
        else{
            cout << temp->data << " "; 
            if(temp->left)
              q.push(temp->left);
            if(temp->right)
              q.push(temp->right);
        }
    }
}
void inorder(node *root){
    if(root==NULL)
      return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node *root){
    if(root==NULL)
      return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root){
    if(root==NULL)
      return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main() {
    node*root=buildtree();
    levelorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    return 0;
}
