#include <iostream>
#include <climits>
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
    
    bool isBST(Node* root, int minVal, int maxVal){
        if(root==nullptr)
            return true;
        
        if(root->data<=minVal||root->data>=maxVal)
            return false;
        
        return isBST(root->left, minVal, root->data) && isBST(root->right, root->data, maxVal);
    }
    
    //inorder traversal for checking
    void inorder(Node* node){
        if(node==nullptr)
            return;
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }
};

int main()
{
    BinaryTree tree;
    tree.root=new Node(50);
    tree.root->left=new Node(40);
    tree.root->right=new Node(60);
    tree.root->left->left=new Node(30);
    tree.root->left->right=new Node(42);
    tree.root->right->left=new Node(55);
    tree.root->right->right=new Node(90);

    cout<<endl<<"inorder traversal: ";
    tree.inorder(tree.root);
    cout<<endl;
    
    if(tree.isBST(tree.root, INT_MIN, INT_MAX))
        cout<<"given binary tree is BST."<<endl;
    else
        cout<<"given binary tree is not BST."<<endl;

    return 0;
}