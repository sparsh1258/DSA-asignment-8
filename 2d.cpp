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
Node* findMin(Node* root) {
    while(root->left != NULL)
        root = root->left;
    return root;
}
Node* findMax(Node* root) {
    while(root->right != NULL)
        root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, int key) {
    Node* successor = NULL;

    while(root != NULL) {

        if(key < root->data) {
            successor = root;   // possible successor
            root = root->left;
        } 
        else if(key > root->data) {
            root = root->right;
        } 
        else {
            // Node found
            if(root->right != NULL) {
                successor = findMin(root->right);
            }
            break;
        }
    }

    return successor;
}

int main(){
    int a[100];
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
    inorderSuccessor(root,42);
    

}