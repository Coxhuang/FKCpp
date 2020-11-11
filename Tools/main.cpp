#include <iostream>

class Node{
public:
    int b =1;
};


int main() {
    std::cout << "Hello, Tools!" << std::endl;
    Node a = Node();
    std::cout << a.b << std::endl;

    return 0;
}
