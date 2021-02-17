#include <iostream>
#include <string>

using std::string;
using std::istream;
using std::ostream;
using std::endl;

class Sales_item
{
public:
	double avg_price() const;
	bool same_isbn(const Sales_item &rhs) const { return isbn == rhs.isbn; }
	Sales_item() : units_sold(0), revenue(0.0) {}

	void read_inputs(istream& in) 
	{
		double price;
		in >> isbn >> units_sold >> price;
		if (in) {
			revenue = units_sold * price;
		} else {
			units_sold = 0;
			revenue = 0.0;
		}
	}

	void write_output(ostream& out)
       	{
		out << isbn << " " << units_sold << " " << revenue << " " << avg_price() << endl;
	};

private:
	string isbn;
	unsigned units_sold;
	double revenue;
};
