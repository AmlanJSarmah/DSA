#pragma once

class BST_Node{
    public:
        int value;
        BST_Node* left;
        BST_Node* right;
        BST_Node(int value);
};

class BST{
    BST_Node* root;
    bool contains(BST_Node* cur, int value);
    BST_Node* insert(BST_Node* cur, int value);
    void inorder(BST_Node* cur);
    void preorder(BST_Node* cur);
    void postorder(BST_Node* cur);
    public:
        BST();
        void destroy(BST_Node* cur_node);
        ~BST();
        bool contains(int value);
        void insert(int value);
        void inorder();
        void preorder();
        void postorder();
        void bfs();
};
