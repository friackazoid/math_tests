#include <list>
#include <iostream>
#include <algorithm>

int main () {
    std::list<int> l(10);
    std::srand(time(NULL));
    std::generate(l.begin(), l.end(), [] () mutable { return std::rand() % 10 + 1; });

    std::cout << "list: ";
    for (int i: l) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    l.remove(3);

    std::cout << "list: ";
    for (int i: l) {
        std::cout << i << " ";
    }
    std::cout << "\n";


}
