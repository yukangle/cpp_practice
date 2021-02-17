#include <string>
#include <vector>
#include <iostream>
#include "queue.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main()
{
    Queue<string> q;
    q.push("Hello");
    q.push("Tom");
    q.push("Yu");

    cout << q << endl;

    short a[4] = { 0, 3, 4, 9 };
    Queue<int> qi(a, a+4);

    vector<int> vi(a, a+4);

    qi.assign(vi.begin(), vi.end());

    cout << qi << endl;

}