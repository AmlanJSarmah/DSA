#include <iostream>
#include "hash_map.h"

HTNode::HTNode(std::string key, int value){
    this->key = key;
    this->value = value;
    next = nullptr;
}

HashMap::HashMap(){
    std::cout << "Hash Map Created!" << std::endl;
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
        std::cout << i << ":" << std::endl;
        if(map[i]){
            HTNode* temp = map[i];
            while(temp){
                std::cout << "{ " << temp->key << " : " << temp->value << " }" << std::endl;
                temp = temp->next;
            }
        }
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
