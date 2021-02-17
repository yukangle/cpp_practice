#include <iostream>
#include <string>
#include "utlities.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

template <class Type> class Queue 
{
public:
    Queue();
    Type& front();
    const Type& front() const;
    void push(const Type &);
    void pop();
    bool empty() const;
private:

};

int main()
{
    cout << compare(1.0, 2.0) << endl;
    cout << compare(1, 2) << endl;
}