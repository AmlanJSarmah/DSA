#include <climits>
#include <iostream>
#include "hash_map.h"

HTNode::HTNode(std::string key, int value){
    this->key = key;
    this->value = value;
    next = nullptr;
}

HashMap::HashMap(){
    std::cout << "Hash Map Created!" << std::endl;
    // We assign each position to be nullpointer initially
    for(int i = 0; i < SIZE; i++){
        map[i] = nullptr;
    }
}

HashMap::~HashMap(){
    std::cout << "Hash Map Destroyed!" << std::endl;
    for(int i = 0; i < SIZE; i++){
        HTNode* head = map[i];
        HTNode* temp = head;
        while(head){
            head = head->next;
            delete temp;
            temp = head;
        }
    }
}

void HashMap::print_table(){
    for(int i = 0; i < SIZE; i++){
        std::cout << i << ": ";
        if(map[i]){
            HTNode* temp = map[i];
            while(temp){
                std::cout << "{ " << temp->key << " : " << temp->value << " } " << std::endl;
                temp = temp->next;
            }
        }
        else
            std::cout << "\n";
    }
}

int HashMap::hash(std::string key){
    int hash = 0;
    for(int i = 0; i < key.length(); i++){
        int ascii_value = (int)key[i];
        hash = (hash + ascii_value * 23) % SIZE;
    }
    return hash;
}

bool HashMap::set(std::string key, int value){
    bool is_set = false;
    HTNode* kv_pair = new HTNode(key, value);
    int index = hash(key);
    std::cout << index << std::endl;
    if(map[index] == nullptr){
        map[index] = kv_pair;
    }
    else{
        HTNode* temp = map[index];
        while(temp->next)
            temp = temp->next;
        temp->next = kv_pair;
    }
    is_set = true;
    return is_set;
}

int HashMap::get(std::string key){
    int index = hash(key);
    HTNode* temp = map[index];
    while(temp){
        if(temp->key == key)
            return temp->value;
        temp = temp->next;
    }
    return INT_MIN;
}

std::vector<std::string> HashMap::keys(){
    std::vector<std::string> all_keys;
    for(int i = 0; i < SIZE; i++){
       HTNode* temp = map[i];
       while(temp){
           all_keys.push_back(temp->key);
           temp = temp->next;
       }
    }
    return all_keys;
}

void HashMap::remove_key(std::string key){
    int index = hash(key);
    HTNode* temp = map[index];
    HTNode* prev = nullptr;
    while(temp){
        if(temp->key == key){
            // In case of multiple nodes
            if(prev && temp->next){
                prev->next = temp->next;
                delete temp;
            }
            // In case of two node
            else if(!prev && temp->next){
                map[index] = temp->next;
                delete temp;
            }
            // In case of one node
            else{
                map[index] = nullptr;
                delete temp;
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}
