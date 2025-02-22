#include <iostream>
#include <limits.h>
#include "heap.h"

Heap::Heap(){
    std::cout << "Heap Created!" << std::endl;
    heap.push_back(INT_MIN);
}

int Heap::left_child(int index){
    return 2*index;
}

int Heap::right_child(int index){
    return 2*index+1;
}

int Heap::parent(int index){
    return index/2;
}

void Heap::swap(int index1, int index2){
   int temp = heap.at(index1);
   heap[index1] = heap.at(index2);
   heap[index2] = temp;
}

void Heap::traverse(){
    std::cout << "Data stored in Heap \n";
    for(int i = 1; i < heap.size(); i++){
        std::cout << heap.at(i) << " ";
    }
    std::cout << "\n";
}

void Heap::insert(int value){
    heap.push_back(value);
    int cur = heap.size() - 1;
    while(cur > 1 && heap.at(cur) > heap.at(parent(cur))){
        swap(cur, parent(cur));
        cur = parent(cur);
    }
}

void Heap::sink_down(int index){
    int max_index = index;
    while(true){
        int left_index = left_child(index);
        int right_index = right_child(index);
        
        if(left_index < heap.size() && heap.at(left_index) > heap.at(max_index))
            max_index = left_index;

        if(right_index < heap.size() && heap.at(right_index) > heap.at(max_index))
            max_index = right_index;

        if(max_index != index){
            swap(index, max_index);
            index = max_index;
        }
        else
            return;
    }
}

int Heap::remove(){
    if(heap.empty())
        return INT_MIN;
    int max_value = heap.front();
    if(heap.size() == 1)
        heap.pop_back();
    else{
        heap[0] = heap.back();
        heap.pop_back();
        sink_down(0);
    }
    return max_value;
}
