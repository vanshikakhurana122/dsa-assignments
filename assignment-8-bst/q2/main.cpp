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
        
        return node;
    }
    void insert(int value){
        root=insert(root, value);
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
    
    //non-recursive search
    Node* nonrecursiveSearch(Node* node, int value){
        while(node!=nullptr){
            if(node->data==value)
                return node;
            if(value<node->data)
                node=node->left;
            else
            node=node->right;
        }
        return nullptr;
    }
    
    //find max
    Node* findMax(Node* node){
        if(node==nullptr)
            return nullptr;
        
        while(node->right!=nullptr)
            node=node->right;
        
        return node;
    }
    
    //find min
    Node* findMin(Node* node){
        if(node==nullptr)
            return nullptr;
        
        while(node->left!=nullptr)
            node=node->left;
        
        return node;
    }
    
    //inorder successor
    Node* inorderSuccessor(Node* root, int value){
        Node* target=recursiveSearch(root, value);
        
        if(target==nullptr)
            return nullptr;
        
        //node has right subtree
        if(target->right!=nullptr)
            return findMin(target->right);
        
        //node doesnt have a right subtree, successor is an element in upper levels
        Node* successor=nullptr;
        Node* ancestor=root;
        while(ancestor!=target){
            if(target->data<ancestor->data){
                successor=ancestor;
                ancestor=ancestor->left;
            }
            else
                ancestor=ancestor->right;
        }
        return successor;
    }
    
    //inorder predecessor
    Node* inorderPredecessor(Node* root, int value){
        Node* target=recursiveSearch(root, value);
        
        if(target==nullptr)
            return nullptr;
        
        //node has left subtree
        if(target->left!=nullptr)
            return findMax(target->left);
        
        //node doesnt have a left subtree, successor is an element in upper levels
        Node* predecessor=nullptr;
        Node* ancestor=root;
        while(ancestor!=target){
            if(target->data>ancestor->data){
                predecessor=ancestor;
                ancestor=ancestor->right;
            }
            else
                ancestor=ancestor->left;
        }
        return predecessor;
    }
    
    //inorder traversal for checking
    void inorder(Node* root){
        if(root==nullptr)
            return;
        
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};

int main()
{
    BST tree;
    //inserting elements
    tree.insert(50);
    tree.insert(40);
    tree.insert(30);
    tree.insert(70);
    tree.insert(10);
    tree.insert(60);
    tree.insert(15);
    
    //inorder traversal for checking
    cout<<"inorder traversal of tree: ";
    tree.inorder(tree.root);
    cout<<endl;
    
    //search recurisve
    int key1=15;
    Node* nodeRecursive=tree.recursiveSearch(tree.root, key1);
    if(nodeRecursive)
        cout<<"node "<<key1<<" found in BST"<<endl;
    else
        cout<<"node "<<key1<<" not found in BST"<<endl;
    
    //search nonrecurisve
    int key2=56;
    Node* nodenonRecursive=tree.nonrecursiveSearch(tree.root, key2);
    if(nodenonRecursive)
        cout<<"node "<<key2<<" found in BST"<<endl;
    else
        cout<<"node "<<key2<<" not found in BST"<<endl;
    
    //find max
    Node* maxNode=tree.findMax(tree.root);
    cout<<"max node of the BST is "<<maxNode->data<<endl;
    
    //find min
    Node* minNode=tree.findMin(tree.root);
    cout<<"min node of the BST is "<<minNode->data<<endl;
    
    //inorder successor
    int target1;
    cout<<endl;
    cout<<"enter key for inorder successor: ";
    cin>>target1;
    Node* successor=tree.inorderSuccessor(tree.root, target1);
    if(successor)
        cout<<"inorder successor of "<<target1<<" is: "<<successor->data<<endl;
    else
        cout<<"there is no inorder successor of "<<target1<<endl;
    
    //inorder predecessor
    int target2;
    cout<<endl;
    cout<<"enter key for inorder predecessor: ";
    cin>>target2;
    Node* predecessor=tree.inorderPredecessor(tree.root, target2);
    if(predecessor)
        cout<<"inorder predecessor of "<<target2<<" is: "<<predecessor->data<<endl;
    else
        cout<<"there is no inorder predecessor of "<<target2<<endl;

    return 0;
}