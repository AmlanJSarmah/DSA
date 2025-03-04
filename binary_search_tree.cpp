#include <iostream>
#include <queue>
#include "binary_search_tree.h"

BST_Node::BST_Node(int value){
    this->value = value;
    left = nullptr;
    right = nullptr;
}

BST::BST(){
    std::cout << "Binary Search Tree Created" << std::endl;
    root = nullptr;
}

BST::~BST(){
    destroy(root);
}

void BST::destroy(BST_Node* cur_node){
    if(cur_node->left)
        destroy(cur_node->left);
    if(cur_node->right)
        destroy(cur_node->right);
    delete cur_node;
}

bool BST::contains(BST_Node* cur, int value){
    if(!cur)
        return false;
    if(cur->value == value)
        return true;
    if(cur->value > value)
        return contains(cur->left, value);
    else
        return contains(cur->right, value);
}

bool BST::contains(int value){
    return contains(root, value);
}

BST_Node* BST::insert(BST_Node* cur, int value){
    if(cur == nullptr)
        return new BST_Node(value);
    if(value < cur->value)
        cur->left = insert(cur->left, value);
    else
        cur->right = insert(cur->right, value);
    return cur;
}

void BST::insert(int value){
    if(root == nullptr){
        root = new BST_Node(value);
        return;
    }
    insert(root, value);
}

void BST::inorder(BST_Node* cur){
    if(cur){
        inorder(cur->left);
        std::cout << cur->value << " ";
        inorder(cur->right);
    }
}

void BST::inorder(){
    if(!root){
        std::cout << "Empty" << std::endl;
        return;
    }
    inorder(root);
    std::cout << "\n";
}

void BST::postorder(BST_Node* cur){
    if(cur){
        postorder(cur->left);
        postorder(cur->right);
        std::cout << cur->value << " ";
    }
}

void BST::postorder(){
    if(!root){
        std::cout << "Empty" << std::endl;
        return;
    }
    postorder(root);
    std::cout << "\n";
}

void BST::preorder(BST_Node* cur){
    if(cur){
        std::cout << cur->value << " ";
        preorder(cur->left);
        preorder(cur->right);
    }
}

void BST::preorder(){
    if(!root){
        std::cout << "Empty" << std::endl;
        return;
    }
    preorder(root);
    std::cout << "\n";
}

void BST::bfs(){
    BST_Node* cur = root;
    std::queue<BST_Node*> bst_queue;
    bst_queue.push(cur);
    while(bst_queue.size() > 0){
        cur = bst_queue.front();
        bst_queue.pop();
        std::cout << cur->value << " ";
        if(cur->left)
            bst_queue.push(cur->left);
        if(cur->right)
            bst_queue.push(cur->right);
    }
    std::cout << "\n";
}

void BST::delete_node(int value){
    if(root == nullptr){
        std::cout << "Empty Tree" << std::endl;
        return;
    }
    if(contains(value))
        root = delete_node(root, value);
}

BST_Node* BST::delete_node(BST_Node* cur, int value){
    //Finding the element to be deleted
    if(cur == nullptr)
        return cur;
    //If element in left subtree
    else if(cur->value < value) cur->right = delete_node(cur->right, value);
    //If element in right subtree
    else if(cur->value > value) cur->left = delete_node(cur->left, value);
    //Element is found
    else{
        //No children
        if(!cur->left && !cur->right){
            BST_Node* temp = cur;
            cur = nullptr;
            delete temp;
        }
        //One children
        else if(cur->left && !cur->right){
            BST_Node* temp = cur;
            cur = cur->left;
            delete temp;
        }
        else if(!cur->left && cur->right){
            BST_Node* temp = cur;
            cur = cur->right;
            delete temp;
        }
        //Two Children
        else{
            //Find leftmost element of right subree
            BST_Node* temp = find_min(cur->right);
            // Assign value of the node to value of leftmost root in right subtree
            cur->value = temp->value;
            // Deleting the leftmost root in right subtree
            cur->right = delete_node(cur->right, temp->value);
        }
    }
    return cur;
}

BST_Node* BST::find_min(BST_Node* cur){
    if(!cur->left)
        return cur;
    find_min(cur->left);
    return cur;
}
