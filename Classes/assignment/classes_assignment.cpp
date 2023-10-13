///
///
///
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// Please complete problem 9.22.6 in the prorgramming projects section of your text.
/* Reimplement the CashRegister class so that it keeps track of
 *  the price of each added item in a vector<double>. 
 * Remove the item_count and total_price data members. 
 * Reimplement the clear, add_item, get_total,
 *  and get_count member functions. 
 * Add a member function display_all that displays the
 *  prices of all items in the current sale. */

class CashRegister {
    public:
        CashRegister();
        void clear();
        void add_item(double item);
        double get_total() const;
        int get_count() const;
        void display_all() const;
    private:
        vector<double> items;
};

CashRegister::CashRegister() {
    this->items.clear();
}

void CashRegister::clear() {
    this->items.clear();
}

void CashRegister::add_item(double item) {
    this->items.push_back(item);
}

double CashRegister::get_total() const {
    double total = 0;
    for (unsigned int i = 0; i < this->items.size(); i++) {
        total += items.at(i);
    }
    return total;
}

int CashRegister::get_count() const {
    return this->items.size();
}

void CashRegister::display_all() const {
    cout << setfill('*') << setw(12) << "Total";
    cout << setfill('*') << setw(7) << "" << endl;
    for (unsigned int i = 0; i < this->items.size(); i++) {
        cout << "*" << setw(2) << setfill(' ') << ' ' << i + 1 << ": ";
        cout << this->items.at(i) << "\t *" << endl;
    }
    cout << "*  Total: " << this->get_total() << "\t *" << endl;
    cout << setfill('*') << setw(19) << "" << endl;
}

int main() {
    CashRegister drawer;

    
    drawer.add_item(1.15);
    drawer.add_item(12.57);
    drawer.add_item(9.87);

    cout << drawer.get_total() << endl;
    drawer.display_all();

    drawer.clear();
    drawer.add_item(6.66);

    cout << drawer.get_total() << endl;

    drawer.display_all();

    return 0;
}
