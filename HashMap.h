#ifndef C_HASHMAP_HASHMAP_H
#define C_HASHMAP_HASHMAP_H
#include "LinkedNode.h"

class HashMap {
private:
    LinkedNode **table;
    int entries, buckets;
public:
    HashMap(int size);
    bool set(int,int);
    int *get(int);
    int *del(int);
    float load();
    void print();
};

#endif //C_HASHMAP_HASHMAP_H
