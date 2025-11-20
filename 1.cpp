#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
Node* insert(Node* root,int val){
if(root==nullptr){
    return new Node(val);
}
if(val< root->data){
root->left=insert(root->left,val);
}
else if(val>root->data){
    root->right=insert(root->right,val);
    
}
return root;
};
void preorder(Node* root){
    if(root==NULL) return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node*root){
     if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node* root){
    if(root==NULL)return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
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
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);


}