#pragma once

#include <vector>

class Heap{
    std::vector<int> heap;
    int left_child(int index);
    int right_child(int index);
    int parent(int index);
    void swap(int index1, int index2);
    void sink_down(int index);
public:
    Heap();
    void traverse();
    void insert(int value);
    int remove();
};
