#include "HashMap.h"

using namespace std;

HashMap::HashMap(int size){
    buckets = size;
    table = new LinkedNode*[size];
    for(int i=0; i<size; i++){
        table[i] = new LinkedNode();
    }
};

bool HashMap::set(string key, int value){
    int location = abs(((hashSum(key)) % buckets)); //hash function
    if (table[location]->next == nullptr) { //if spot is empty place entry
        table[location]->next = new LinkedNode(key, value, table[location]);
        entries++;
    }
    else { //otherwise initialize an iterator to find last node in chain
        LinkedNode *itr = table[location]->next;
        if (itr->key == key) { // check first node in chain for key, if true update the key value pair & exit method
            itr->value = value;
            return true;
        } //otherwise check down the chain for the key until there are no more
        while (itr->next != nullptr) {
            itr = itr->next;
            if (itr->key == key) //if the key is found break the loop
                break;
        }
        if (itr->key == key) //if item previously hashed, update its value
            itr->value = value;
        else {//otherwise place entry at the end of the chain
            itr->next = new LinkedNode(key, value, itr);
            entries++;
        }

    }
    return true; //by using seperate chaining, it is impossible for the set function to fail
};

int *HashMap::get(string key) {
    int location = abs(((hashSum(key)) % buckets)); //hash function
    if (table[location]->next == nullptr) //if spot is empty
        return nullptr; //return nil to indicate that the entry was not found
    else { //otherwise initialize an iterator to look in chain for desired entry
        LinkedNode *itr = table[location]->next;
        do {
            if (itr->key == key) //if key found return value
                return &itr->value;
            else //otherwise cycle down the chain
                itr = itr->next;
        } while (itr->next != nullptr);
        if (itr->key == key) //check last key found before returning a failed search
            return &itr->value;
        return nullptr;
    }
}


int *HashMap::del(string key) {
    int location = abs(((hashSum(key)) % buckets)); //hash function
    if (table[location]->next == nullptr) //if spot is empty
        return nullptr; //return nil to indicate that the entry was not found and delete was unsuccessful
    else { //otherwise initialize an iterator to look in chain for desired entry
        LinkedNode *itr = table[location]->next;
        do {
            if (itr->key == key) {
                break;
//                int temp = itr->value;
//                int *tempPtr = &temp;
//                if (itr->next != nullptr) {
//                    itr->next->prev = itr->prev;
//                    itr->prev->next = itr->next;
//                    entries--;
//                } else {
//                    itr->prev->next = itr->next;
//                    entries--;
//                }
//                return tempPtr;
            }
            itr = itr->next;
        } while(itr->next != nullptr);

        if (itr->key == key) { //check item in chain
            int temp = itr->value;
            int *tempPtr = &temp;
            if (itr->next != nullptr) {
                itr->next->prev = itr->prev; //delete entry by rearranging pointers
                itr->prev->next = itr->next;
                delete itr; // deallocate memory
                entries--;
            } else {
                itr->prev->next = itr->next;
                entries--;
            }
            return tempPtr;
        }
    }
    return nullptr;
}

float HashMap::load(){
    return entries /(float)buckets;
};

int HashMap::hashSum(string str){ //sums the character values of a string to produce a value to be hashed
    int hashSum = 0;
    if (str.size() == 0)
        return -1; //causes segfault to prevent user from entering empty keys
    for(int i=0; i < str.size(); i++){
        hashSum += str[i];
    }
    return hashSum;
}

void HashMap::print(){
    cout << "entries = " << entries << " buckets = " << buckets << " load factor = " << load() << endl;
    for(int i=0; i < buckets; i++){
        if (table[i]->next == nullptr)
            cout << "[" << i+1 << "] = nil" << endl;
        else {
            LinkedNode *itr = table[i]->next;
            cout << "[" << i+1 << "] = (" << itr->key << ", " << itr->value << ")" ;
            while (itr->next != nullptr) {
                itr = itr->next;
                cout << " - (" << itr->key << ", " << itr->value << ")" ;
            } cout << endl;
        }
    }
};