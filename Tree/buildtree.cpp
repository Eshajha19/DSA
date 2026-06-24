// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class node{
    public:
       int data;
       node*left;
       node*right;
       node(int d){
           this->data=d;
           this->right=NULL;
           this->left=NULL;
       }
};
node*buildtree(){
    int d;
    cin>>d;
    node *root=new node(d);
    if(root->data==-1)
      return NULL;
    cout<<"Enter data for left of "<<root->data<<":";
    root->left=buildtree();
    cout<<"Enter data for right of "<<root->data<<":";
    root->right=buildtree();
    return root;
}
int main() {
    buildtree();
    return 0;
}
