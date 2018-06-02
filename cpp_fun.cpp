#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

#include <math.h>
#include <algorithm> // __gcd greatest common 
#include <numeric>

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define watch_coll(coll) std::cout << (#coll) << ':' << std::endl; for (auto i: (coll)) std::cout << i << "; "; std::cout << std::endl;

int main () {
    int x = 10;
    int c = 100;

    watch(x);
    watch(c);

    const double pi = 2 * acos(0.0);
    watch(pi);

    int oo = 0x3f3f3f3f;
    watch(oo);

    double inf = 1.0/0.0;
    watch(inf);
    watch(2*inf);

    watch(std::__gcd(6, 20));
    watch(std::__gcd(x,c));

    std::vector<int> vec(10);
    std::iota (vec.begin(), vec.end(), x);
   
    watch_coll(vec);
}
