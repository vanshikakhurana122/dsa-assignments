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

class BST{
    public:
    Node* root;
    
    BST(){
        root=nullptr;
    }
    
    //insert Node
    Node* insert(Node* node, int value){
        if(node==nullptr)
            return new Node(value);
        
        if(value<node->data)
            node->left=insert(node->left, value);
        
        else if(value>node->data)
            node->right=insert(node->right, value);
        
        else
            cout<<"duplicate value "<<value<<" not allowed."<<endl;
        
        return node;
    }
    void insert(int value){
        root=insert(root, value);
    }
    
    //inorder traversal for checking
    void inorder(Node* root){
        if(root==nullptr)
            return;
        
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    
    //recursive search
    Node* recursiveSearch(Node* node, int value){
        if(node==nullptr||node->data==value)
            return node;
        
        if(value<node->data)
            return recursiveSearch(node->left, value);
        else
        return recursiveSearch(node->right, value);
    }
    
    //find min for deleting node woth 2 children
    Node* findMin(Node* node){
        if(node==nullptr)
            return node;
        
        while(node->left!=nullptr)
            node=node->left;
        
        return node;
    }
    
    //deleting Node
    Node* deleteNode(Node* node, int key){
        if(node==nullptr)
            return node;
        
        //search for node
        if(key<node->data)
            node->left=deleteNode(node->left, key);
        else if(key>node->data)
            node->right=deleteNode(node->right, key);
        else{ //node found
            //no child, leaf node
            if(node->left==nullptr&&node->right==nullptr){
                cout<<"deleting node "<<node->data<<endl;
                delete node;
                return nullptr;
            }
            
            //one child, only right child
            else if(node->left==nullptr){
                cout<<"deleting node "<<node->data<<endl;
                Node*temp=node->right;
                delete node;
                return temp;
            }
            
            //one child, only left child
            else if(node->right==nullptr){
                cout<<"deleting node "<<node->data<<endl;
                Node*temp=node->left;
                delete node;
                return temp;
            }
            
            //two children
            else{
                cout<<"deleting node "<<node->data<<endl;
                Node*temp=findMin(node->right);
                node->data=temp->data;
                node->right=deleteNode(node->right, temp->data);
            }
        }
        return node;
    }
    void deleteNode(int key){
        root=deleteNode(root, key);
    }
    
    //max depth
    int maxDepth(Node* node){
        if(node==nullptr)
            return 0;
        
        int leftDepth=maxDepth(node->left);
        int rightDepth=maxDepth(node->right);
        
        if(leftDepth>rightDepth)
            return leftDepth+1;
        else
            return rightDepth+1;
    }
    
    int minDepth(Node* node){
        if(node==nullptr)
            return 0;
        
        //if single child, consider existing subtree
        if(node->left==nullptr)
            return 1+minDepth(node->right);
        if(node->right==nullptr)
            return 1+minDepth(node->left);
        
        int leftDepth=minDepth(node->left);
        int rightDepth=minDepth(node->right);
        
        if(leftDepth<rightDepth)
            return leftDepth+1;
        else
            return rightDepth+1;
    }
};

int main()
{
    BST tree;
    
    //insert nodes
    int n;
    cout<<"enter number of nodes: ";
    cin>>n;
    
    int key;
    for(int i=0; i<n; i++){
        cout<<"enter value of node "<<i+1<<": ";
        cin>>key;
        tree.insert(key);
    }
    
    //traversal
    cout<<endl<<"inorder traversal: ";
    tree.inorder(tree.root);
    cout<<endl;
    
    //maxDepth and minDepth
    cout<<"max depth of BST: "<<tree.maxDepth(tree.root)<<endl;
    cout<<"min depth of BST: "<<tree.minDepth(tree.root)<<endl;
    
    //delete
    int del;
    cout<<"enter node to delete: ";
    cin>>del;
    tree.deleteNode(del);
    
    //traversal after deletion
    cout<<endl<<"inorder traversal after deletion: ";
    tree.inorder(tree.root);
    cout<<endl;

    return 0;
}