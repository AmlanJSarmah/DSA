#pragma once
#include <string>

class HTNode{
public:
    std::string key;
    int value;
    HTNode* next;
    HTNode(std::string key, int value);
};

class HashMap{
    static const int SIZE = 7;
    HTNode* map[SIZE];
    int hash(std::string key);
public:
    HashMap();
    ~HashMap();
    void print_table();
};
