#ifndef C_HASHMAP_LINKEDNODE_H
#define C_HASHMAP_LINKEDNODE_H

class LinkedNode {
        private:
        public:
        int value, key;
        LinkedNode *next;
        LinkedNode *prev;
        LinkedNode(); //null object
        LinkedNode(int, int, LinkedNode *);
        ~LinkedNode();
};

#endif //C_HASHMAP_LINKEDNODE_H
