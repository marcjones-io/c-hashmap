# c-hashmap
Simple hash map with seperate chaining implemented in C++, using only primitive types (the 'main.cpp' file uses a bit more than primitives in order to read in from files or accept user input).

### instructions:
* Compile the program by navigating to the directory, calling your compiler followed by the '*.cpp' indicator to ensure all C++ files in the directory should be linked in the final executable. Example: "clang++ *.cpp"
* Run the program using the resulting 'a.out' executable. The program will prompt you to choose a size to initialize your hash map to and ask for a means of data entry
* The program will allow you to enter _< key, value >_ pairs individually on the command kine or through an **"input.txt"** file. Keys are **string** objects, while values are **integers**.
* Ensure that _< key, value >_ pairs are in the form "Key, Value" (minus the quotes), where a comma - _followed by a space_ - seperate the two.
* Include the optional **"-sample"** flag to run the program with the included sample file and sample table size. Example: "./a.out -sample"
* Include the optional **"-size"** flag _(followed by an integer)_ to use the command line to inform the program of the hash map's table size. Example: "./a.out -size 31"
* Both flags may be used if you wish to use the provided sample data set with a table size of your choosing

### notes:
Considering the importance of table size in any hash function (where prime values are ideal for efficient distribution), and the fact that the user is responsible establishing its size, I used seperate chaining over open addressing because of there is no guarantee that the user will infact provide an optimal table size. This project was based off the specification problem for the [Kleiner Perkins Caufield & Byers (KPCB) Engineering Fellows application.](http://kpcbfellows.com "KBPC Fellows Homepage") The ambiguity over the term "arbitrary data object" in the specification led me to choose integers as the value data object type. If the program is to be flexible for _all_ data types (as opposed to an arbitrary one), it would simply be a matter of changing the value type in the 'HashMap.cpp' class from integers to void pointer (__void *__)