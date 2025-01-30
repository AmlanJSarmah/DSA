#pragma once
#include <string>
#include <vector>

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
    bool set(std::string key, int value);
    int get(std::string key);
    std::vector<std::string> keys();
};
