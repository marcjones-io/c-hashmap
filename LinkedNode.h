#ifndef C_HASHMAP_LINKEDNODE_H
#define C_HASHMAP_LINKEDNODE_H
#include <iostream>
using namespace std;

class LinkedNode {
        private:
        public:
        string key;
        int value;//, key;
        LinkedNode *next;
        LinkedNode *prev;
        LinkedNode(); //null object
        LinkedNode(string, int, LinkedNode *);
        ~LinkedNode();
};

#endif //C_HASHMAP_LINKEDNODE_H
