#include <iostream>
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

}
