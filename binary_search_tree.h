#pragma once

class BST_Node{
    public:
        int value;
        BST_Node* left;
        BST_Node* right;
        BST_Node(int value);
};

class BST{
    public:
        BST_Node* root;
        BST();
        void destroy(BST_Node* cur_node);
        ~BST();
        bool contains(BST_Node* cur, int value);
};
