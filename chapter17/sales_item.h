#include <iostream>
#include <string>
#include <stdexcept>

using std::string;
using std::istream;
using std::ostream;
using std::runtime_error;
using std::logic_error;

namespace kangleyu 
{

    class out_of_stock: public runtime_error {
    public:
        explicit out_of_stock(const string &s): runtime_error(s) { }
    };

    class isbn_mismatch: public logic_error {
    public:
        explicit isbn_mismatch(const string &s): logic_error(s) { }

        isbn_mismatch(const string &s, const string &lhs, const string &rhs):
            logic_error(s), left(lhs), right(rhs) { }
        
        const string left, right;

        virtual ~isbn_mismatch() throw() { }
    };

    class Sales_item 
    {
        friend istream& operator>>(istream&, Sales_item&);
        friend ostream& operator<<(ostream&, const Sales_item&);
        friend bool operator==(const Sales_item&, const Sales_item&);
        friend bool operator!=(const Sales_item &lhs, const Sales_item &rhs);
    public:
        explicit Sales_item(const string &book = ""):
            isbn(book), units_sold(0), revenue(0.0) {}
        explicit Sales_item(istream&);
        // operatinos
        inline double avg_price() const;
        bool same_isbn(const Sales_item &rhs) const;
        // equivalent to the synthesized assignment operator
        Sales_item& operator=(const string &book);
        Sales_item& operator=(const Sales_item &);
        Sales_item& operator+=(const Sales_item &);

        string book() const {
            return isbn;
        }

        ~Sales_item() {}
    private:
        string isbn;
        unsigned units_sold;
        double revenue;
    };

    double Sales_item::avg_price() const {
        if (units_sold) {
            return revenue / units_sold;
        } else {
            return 0;
        }
    }

    bool Sales_item::same_isbn(const Sales_item &rhs) const {
        return this->isbn == rhs.isbn;
    }

    Sales_item::Sales_item(istream& is) {
        double price;
        is >> isbn >> units_sold >> price;

        if (is) {
            revenue = units_sold * price;
        }
    }

    Sales_item& Sales_item::operator=(const string &book) {
        isbn = book;
        units_sold = 0;
        revenue = 0.0;
        return *this;
    }

    Sales_item& Sales_item::operator=(const Sales_item &rhs) {
        isbn = rhs.isbn;
        units_sold = rhs.units_sold;
        revenue = this->revenue;
        return *this;
    }

    Sales_item& Sales_item::operator+=(const Sales_item &rhs) {
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
        return *this;
    }

    Sales_item operator+(const Sales_item &lhs, const Sales_item &rhs) {
        if (!lhs.same_isbn(rhs)) {
            throw isbn_mismatch("isbn mismatch", lhs.book(), rhs.book());
        }
        // copy lhs into a local object that we'll retrun
        Sales_item ret(lhs);
        // add in the contents of rhs
        ret += rhs;
        // return ret by value
        return ret;
    }

    inline bool operator==(const Sales_item &lhs, const Sales_item &rhs) {
        // must be made a friend of Sales_item
        return lhs.units_sold == rhs.units_sold &&
                lhs.revenue == rhs.revenue &&
                lhs.same_isbn(rhs);
    }

    inline bool operator!=(const Sales_item &lhs, const Sales_item &rhs) {
        return !(lhs == rhs);
    }

    ostream& operator<<(ostream &out, const Sales_item &item) {
        out << item.isbn << "\t" << item.units_sold << "\t"
            << item.revenue << "\t" << item.avg_price();
        return out;
    }

    istream& operator>>(istream &in, Sales_item &item) {
        double price;
        in >> item.isbn >> item.units_sold >> price;

        if (in) {
            item.revenue = item.units_sold * price;
        } else {
            item = Sales_item();
        }

        return in;
    }
    
}





