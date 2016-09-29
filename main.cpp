#include <iostream>
#include <fstream>
#include "HashMap.h"
using namespace std;


int main(int argc, char* argv[]) {

    //flow of control variables
    int tablesize = 0, choice = 0;
    string filename = "";

    //command line arguments
    for(int i=0; i<argc; i++){
        string flag = argv[i];

        if (flag == "-sample"){
            //tablesize = 43;
            choice = 1;
            filename = "sample.txt";
        } else if (flag == "-size") {
            tablesize = atoi(argv[i+1]);
            while(tablesize <= 0) {
                cout << "input must be a greater than 0, try again" << endl;
                cin >> tablesize;
            }
        }
    }

    //user interaction
    if (tablesize == 0) {
        cout << "Enter an integer to initialize the hash table to size" << endl;
        cin >> tablesize;
        while(tablesize <= 0) {
            cout << "input must be a greater than 0, try again" << endl;
            cin >> tablesize;
        }
    }

    //initialize hashmap
    HashMap * map = new HashMap(tablesize);

    //user interaction
    if (choice == 0){
        cout << "Choose: 1) Import entries from text file 2) Enter key, value pairs manually" << endl;
        cin >> choice;
        while(choice != 1 && choice != 2) {
            cout << "Choose '1' or '2'" << endl;
            cin >> choice;
        }
    }

    //load in file data from "input.txt"
    if (choice == 1) {
        int linetotal = 0;
        string entry;

        if (filename == "") filename = "input.txt";
        ifstream input (filename);
        if (input.is_open()) {
            int i=0;
            while (getline(input,entry)) {
                i++;
                map->set(entry.substr(0,entry.find_first_of(',')),
                         atoi(entry.substr(entry.find_first_of(',')+1,entry.length()).c_str()));
            }
            input.close();
        }
        else {
            cout << "Unable to open '"<< filename << "', be sure the file is in the same directory as the executable" << endl;
            exit(1);
        }
    } //load entries manually
    else if (choice == 2) {
        bool proceed = true;

        cout << "Enter key value pairs with a comma, followed by a space, separating them. Example: 'Jon Doe, 1234567' " << endl;
        cout << "When you are finished type 'done'." << endl;
        do {
            string entry;
            getline(cin, entry);
            cout << "entry = '" << entry << "'" << endl;
            if (entry == "") ;
            else if(entry == "done")
                proceed = false;
            else map->set(entry.substr(0,entry.find_first_of(',')),
                     atoi(entry.substr(entry.find_first_of(',')+1,entry.length()).c_str()));
        } while(proceed);
    }

    map->print();
    return 0;
}