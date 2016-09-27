#ifndef C_HASHMAP_HASHMAP_H
#define C_HASHMAP_HASHMAP_H
#include "LinkedNode.h"

class HashMap {
private:
    LinkedNode **table;
    int entries, buckets;
    int hashSum(string);
public:
    HashMap(int size);
    bool set(string,int);
    int *get(string);
    int *del(string);
    float load();
    void print();
};

#endif //C_HASHMAP_HASHMAP_H
