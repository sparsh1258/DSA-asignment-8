#include <iostream>
using namespace std;
class Node{
    public:
    Node*left;
    Node* right;
    int data;
    Node(int val){
        left=right=NULL;
        data=val;
    }
};
Node* insert(Node* root,int val){
    if(root==nullptr) return new Node(val);
    if(val<root->data){
        root->left=insert(root->left,val);
    } 
    else if(root->data<val){
        root->right=insert(root->right,val);;
    }
    return root;
}
void min(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    cout<<root->data<<"is the min "<<" ";

}
int main(){
    Node* root=NULL;
    root=insert(root,60);
    root=insert(root,41);
    root=insert(root,74);
    root=insert(root,18);
    root=insert(root,53);
    root=insert(root,65);
    root=insert(root,25);
    root=insert(root,46);
    root=insert(root,55);
    root=insert(root,63);
    root=insert(root,70);
    root=insert(root,42);
    root=insert(root,62);
    root=insert(root,64);
    min(root);
}