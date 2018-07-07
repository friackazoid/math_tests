#include <list>
#include <iostream>
#include <algorithm>

#include <vector>
#include <ctime>

int main () {
    const int N = std::rand() % 10 + 1;
    std::cout << "Found and remove N=" << N << std::endl;

    std::list<int> l(10);
    std::srand(time(NULL));
    std::generate(l.begin(), l.end(), [](){ return std::rand() % 10 + 1; });

    std::cout << "Random generated list: ";
    for (int i: l) {
        std::cout << i << " ";
    }
    std::cout << "\n";


    l.remove(N);

    std::cout << "List after std::list::remove: ";
    for (int i: l) {
        std::cout << i << " ";
    }
    std::cout << "\n";


    std::vector<int> v(10);
    std::srand(std::time(nullptr));
    std::generate(v.begin(), v.end(), [](){return std::rand()%10 + 1;});

    std::cout << "Random generated vector: ";
    for (const auto &vi: v)
        std::cout << vi << " ";
    std::cout << std::endl;

    v.erase(std::remove(v.begin(), v.end(), N), v.end());
    
    std::cout << "Vector after erase-remove idiom: ";
    for (const auto &vi: v)
        std::cout << vi << " ";
    std::cout << std::endl;
}
