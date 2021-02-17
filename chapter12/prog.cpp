#include <iostream>
#include "Person.h"

using std::cin;
using std::cout;
using std::endl;


int main()
{
	Person person("Tom Yu", "Shanghai, China");
	cout << person.getInfo() << endl;
}
