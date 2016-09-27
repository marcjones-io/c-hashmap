#include "LinkedNode.h"

LinkedNode::LinkedNode() {
    next = nullptr;
    prev = nullptr;
}

LinkedNode::LinkedNode(string k, int v, LinkedNode *p) {
    key = k;
    value = v;
    next = nullptr;
    prev = p;
}

LinkedNode::~LinkedNode() { }
