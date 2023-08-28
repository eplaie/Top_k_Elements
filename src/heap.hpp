#ifndef heap_HPP
#define heap_HPP

#include "hash.hpp"

using namespace std;

struct DataPair {
    string palavra;
    int frequencies;

    DataPair(const string &p, int f) : palavra(p), frequencies(f) {}
};

class HeapMAX {
private:
    vector<DataPair> heap;
    void HeapiFy(size_t index); 

public:
    HeapMAX() {}
    int cont;
    void tamanho() { cout << heap.size() << endl; }
    void insertt(const DataPair &pair);
    DataPair getheap(int i) {return heap [i];} 
    DataPair PMax();
    bool Vazia();
    int getsize () { return heap.size (); }
};

void HeapMAX::insertt(const DataPair &pair) {
    heap.push_back(pair);
    int index = heap.size() - 1;
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[index].frequencies > heap[parentIndex].frequencies) {
            swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        } else {
            break;
        }
    }
}

DataPair HeapMAX::PMax() {
    DataPair Max = heap.front();
    if (heap.size() > 1) {
        heap[0] = heap.back();
        heap.pop_back();
        HeapiFy(0);
    } else {
        heap.pop_back();
    }
    return Max;
}

bool HeapMAX::Vazia() {
    return heap.empty();
}

void HeapMAX::HeapiFy(size_t index) {
    size_t lNumIndex = (index + 1) * 2 -1;
    size_t rNumIndex = (index + 1) * 2;
    size_t largestNumIndex = index;

    if (lNumIndex < heap.size() && heap[lNumIndex].frequencies > heap[largestNumIndex].frequencies) {
        largestNumIndex = lNumIndex;
    }
    if (rNumIndex < heap.size() && heap[rNumIndex].frequencies > heap[largestNumIndex].frequencies) {
        largestNumIndex = rNumIndex;
    }
    if (largestNumIndex != index) {
        swap(heap[index], heap[largestNumIndex]);
        HeapiFy(largestNumIndex);
    }
}
#endif 

