#include <iostream>

enum class Animal {Dog, Cat, Pig, Mokey};
enum class Animal2:unsigned int {Dog, Cat, Pig, Mokey};


using namespace std;

int main() {

//    Animal pat = Dog; // 0
//    Animal pat;
//    pat = Cat; // 1

//    cout << pat;
    cout << static_cast<unsigned int >(Animal2::Cat);

    return 0;
}
