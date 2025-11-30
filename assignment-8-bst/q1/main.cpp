#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;
  
  Node(int value){
      data=value;
      left=nullptr;
      right=nullptr;
  }
};

class BinaryTree{
    public:
    Node* root;
    
    BinaryTree(){
        root=nullptr;
    }
    
    //preorder traversal
    void preorder(Node* node){
        if(node==nullptr)
            return;
        cout<<node->data<<" ";
        preorder(node->left);
        preorder(node->right);
    }
    
    //inorder traversal
    void inorder(Node* node){
        if(node==nullptr)
            return;
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }
    
    //postorder traversal
    void postorder(Node* node){
        if(node==nullptr)
            return;
        postorder(node->left);
        postorder(node->right);
        cout<<node->data<<" ";
    }
};

int main()
{
    BinaryTree tree;
    tree.root=new Node(50);
    tree.root->left=new Node(10);
    tree.root->right=new Node(20);
    tree.root->left->left=new Node(30);
    tree.root->left->right=new Node(40);
    tree.root->right->left=new Node(15);
    tree.root->right->right=new Node(60);
    
    cout<<endl<<"preorder traversal: ";
    tree.preorder(tree.root);
    cout<<endl<<"inorder traversal: ";
    tree.inorder(tree.root);
    cout<<endl<<"postorder traversal: ";
    tree.postorder(tree.root);

    return 0;
}