#include <iostream>
#include "HashMap.h"
using namespace std;

int main() {
    HashMap * map = new HashMap(6);
    map->set(7,7);
    map->set(18,18);
    map->set(41,41);
    map->set(34,34);
    map->set(12,12);
    map->set(6,6);
    map->set(6,8);
    map->set(12,2);
    map->set(-1,-1);

    if (map->get(12) != nullptr) cout << "found " << *map->get(12) << endl;
    else cout << "12 not found" << endl;
    if (map->get(14) != nullptr) cout << "found " << *map->get(14) << endl;
    else cout << "14 not found" << endl;
    map->print();
    ;

    if (map->del(12) != nullptr) cout << "12 deleted" << endl;
    else cout << "12 delete unsuccessful" << endl;
    map->print();


    if (map->del(6) != nullptr) cout << "6 deleted" << endl;
    else cout << "6 delete unsuccessful" << endl;
    map->print();

    if (map->del(-1) != nullptr) cout << "-1 deleted" << endl;
    else cout << "-1 delete unsuccessful" << endl;
    map->print();


//
//    if (map->get(18) != nullptr) cout << "found " << *map->get(18) << endl;
//    else cout << "18 not found" << endl;
//
//    if (map->del(12) != nullptr) cout << "12 deleted" << endl;
//    else cout << "12 delete unsuccessful" << endl;
//
//    map->print();
//
//    if (map->get(12) != nullptr) cout << "found " << *map->get(12) << endl;
//    else cout << "12 not found" << endl;

//    if (map->del(-1) != nullptr) cout << "-1 deleted" << endl;
//    else cout << "-1 delete unsuccessful" << endl;
//    map->del(-1);
//
//    if (map->del(14) != nullptr) cout << "14 deleted" << endl;
//    else cout << "14 delete unsuccessful" << endl;
////    map->del(-1);
//
//    map->print();
//
//    if (map->get(14) != nullptr) cout << "found " << *map->get(14) << endl;
//    else cout << "14 not found" << endl;

    return 0;
}