#include <iostream>
#include <list>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::list;

int main()
{
    int ia[] { 1, 2, 3, 4, 5, 6, 7, 8 };

    list<int> lst(ia, ia+8);

    list<int>::const_iterator it = lst.end();

    while(--it != lst.begin()) {
        cout << *it << " ";
    }

    cout << *it << endl;

}