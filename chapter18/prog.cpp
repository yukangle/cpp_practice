#include <iostream>
#include "vector.h"

using std::cout;
using std::endl;
using kangleyu::Vector;

int main() {
    Vector<int> vi;

    for (int i = 0; i < 100; ++i) {
        vi.push_back(i);
    }

    cout << "finish initialize vector with 100 elements" << endl;
    return 0;
}