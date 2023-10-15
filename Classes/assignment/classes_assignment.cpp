/// Andrew Souza
/// Comp 200 -- Spring 23
/// Classes Assignment
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

// Default constructor that produces an empty vector
CashRegister::CashRegister() {
    this->items.clear();
}

// Empties the items vector
void CashRegister::clear() {
    this->items.clear();
}

// Adds an item to the items vector
void CashRegister::add_item(double item) {
    this->items.push_back(item);
}

// Adds up the contents of the items vector and returns the total
double CashRegister::get_total() const {
    double total = 0;
    for (unsigned int i = 0; i < this->items.size(); i++) {
        total += items.at(i);
    }
    return total;
}

// Returns the numbers of items in the vector
int CashRegister::get_count() const {
    return this->items.size();
}

// Displays an itemized total of the entire vector with the total
void CashRegister::display_all() const {
    cout << setfill('*') << setw(12) << "Total";
    cout << setfill('*') << setw(7) << "" << endl;
    for (unsigned int i = 0; i < this->items.size(); i++) {
        cout << "*" << setw(2) << setfill(' ') << ' ' << i + 1 << ": ";
        cout << this->items.at(i) << "\t *" << endl;
    }
    cout << "*  Total: " << this->get_total() << "\t *" << endl;
    cout << setfill('*') << setw(19) << "" << endl;
    cout << endl;
}

int main() {
    cout << fixed << setprecision(2);
    CashRegister cart;
    char selection;
    double item;

    cout << "Add item to cart" << endl;
    cin >> item;
    cart.add_item(item);
    cout << "Add more items? press q to quit" << endl;
    cout << "a -- add item" << endl;
    cout << "d -- display total" << endl;
    cout << "e -- clear cart" << endl;
    cin >> selection;
    while (selection != 'q') {
        if (selection == 'a') {
            cin >> item;
            cart.add_item(item);
        } else if (selection == 'd') {
            cart.display_all();
        } else if (selection == 'e') {
            cart.clear();
        } else {
            cout << "Make a selection" << endl;
        }
        cout << "Add more items? press q to quit" << endl;
        cout << "a -- add item" << endl;
        cout << "d -- display total" << endl;
        cout << "e -- clear cart" << endl;
        cin >> selection;
        cout << endl;
    }

    cart.display_all();

    return 0;
}
