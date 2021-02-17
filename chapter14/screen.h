#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::cout;
using std::endl;

class Screen
{
public:
    typedef string::size_type index;

    Screen(index ht, index wd) : height(ht), width(wd), cursor(0) {
        contents.assign(ht * wd, ' ');
    }

    char get() const { return contents[cursor]; }
    inline char get(index ht, index wd) const;
    index get_cursor() const;

    Screen& move(index r, index c);
    Screen& set(char);
    Screen& set(index, index, char);

    Screen& display(ostream &os) {
        do_display(os);
        return *this;
    }

    const Screen& display(ostream &os) const {
        do_display(os);
        return *this;
    }

private:
    string contents;
    index cursor;
    index height, width;
    mutable size_t access_ctr;

    void do_display(ostream &os) const {
        ++access_ctr;
        os << contents << endl;
    }
};
