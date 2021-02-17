#include <string>

using std::string;

class Person
{
public:
	Person(const string &name, const string &address) : _name(name), _address(address) {}
	string getInfo() const { return "Name: " + _name + "\nAddress: " + _address; }

private:
	string _name;
	string _address;
};
