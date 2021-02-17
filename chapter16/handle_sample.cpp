#include <iostream>
#include "handle.h"

using std::cout;
using std::endl;

int main()
{
    Handle<int> hp(new int(42));
    {
        Handle<int> hp2 = hp;
        cout << *hp << " " << *hp2 << endl;
        *hp2 = 10;
    }
    cout << *hp << endl;

}