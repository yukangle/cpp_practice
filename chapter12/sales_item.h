#include <istream>
#include <string>

using std::string;
using std::istream;

class Sales_item 
{
public:
    explicit Sales_item(const string &book = ""):
        isbn(book), units_sold(0), revenue(0.0) {}
    explicit Sales_item(istream&);
    // operatinos
    inline double avg_price() const;
private:
    string isbn;
    unsigned units_sold;
    double revenue;
    double price;
};

double Sales_item::avg_price() const {
    if (units_sold) {
        return revenue / units_sold;
    } else {
        return 0;
    }
}

Sales_item::Sales_item(istream& is) {
    is >> this->isbn >> this->units_sold >> this->price;
}