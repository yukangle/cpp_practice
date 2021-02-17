#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

struct IfElse
{
    string operator()(bool condition, const string &true_value, const string &false_value) {
        if (condition) {
            return true_value;
        } else {
            return false_value;
        }
    }
};

int main()
{
    IfElse ifElObj;
    cout << ifElObj(1 > 2, "1 is less than 2", "1 is not less than 2") << endl;
}