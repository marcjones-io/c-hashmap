#include <iostream>
#include "HashMap.h"
using namespace std;

int main() {
    HashMap * map = new HashMap(6);
    map->set("seven",7);
    map->set("eighteen",18);
    map->set("fourtyone",41);
    map->set("thirtyfour",34);
    map->set("twelve",12);
    map->set("six",6);
    map->set("six",8);
    map->set("twelve",2);
    map->set("negative one",-1);

    if (map->get("twelve") != nullptr) cout << "found " << *map->get("twelve") << endl;
    else cout << "12 not found" << endl;
    if (map->get("fourteen") != nullptr) cout << "found " << *map->get("fourteen") << endl;
    else cout << "14 not found" << endl;
    map->print();
    ;

    if (map->del("twelve") != nullptr) cout << "12 deleted" << endl;
    else cout << "12 delete unsuccessful" << endl;
    map->print();


    if (map->del("six") != nullptr) cout << "6 deleted" << endl;
    else cout << "6 delete unsuccessful" << endl;
    map->print();

    if (map->del("negative one") != nullptr) cout << "-1 deleted" << endl;
    else cout << "-1 delete unsuccessful" << endl;
    map->print();


    return 0;
}