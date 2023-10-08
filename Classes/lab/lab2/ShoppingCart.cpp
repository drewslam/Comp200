#include <iostream>
#include <string>
#include <vector>
#include "ShoppingCart.h"
using namespace std;

ShoppingCart::ShoppingCart() {
   this->customerName = "none";
   this->currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string name, string date) {
   this->customerName = name;
   this->currentDate = date;
}

string ShoppingCart::GetCustomerName() const {
   return this->customerName;
}

string ShoppingCart::GetDate() const {
   return this->currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item) {
   this->cartItems.push_back(item);
}
   // Adds an item to cartItems vector. Has parameter ItemToPurchase. Does not return anything.
void ShoppingCart::RemoveItem(string name) {
   int counter = 0;
   for (unsigned int i = 0; i < this->cartItems.size(); i++) {
      if (this->cartItems.at(i).GetName() == name) {
         this->cartItems.erase(this->cartItems.begin() + i);
         counter++;
         break;
      }
   }
   if (counter == 0) {
      cout << "Item not found in cart. Nothing removed." << endl;
   }
   cout << endl;
}
   // Removes item from cartItems vector. Has a string (an item's name) parameter. Does not return anything.
   // If item name cannot be found, output a message: Item not found in cart. Nothing removed.
void ShoppingCart::ModifyItem(ItemToPurchase item) {
   bool match = false;
   for (unsigned int i = 0; i < this->cartItems.size(); i++) {
      if (this->cartItems.at(i).GetName() == item.GetName()) {
         match = true;
         if (this->cartItems.at(i).GetDescription() == "none") {
            this->cartItems.at(i).SetDescription(item.GetDescription());
         }
         // if (this->cartItems.at(i).GetPrice() == 0) {
         //   this->cartItems.at(i).SetPrice(item.GetPrice());
         // }
         if (this->cartItems.at(i).GetQuantity() != 0) {
            this->cartItems.at(i).SetQuantity(item.GetQuantity());
         }
         break;
      }
   }
   if (match == false) {
      cout << "Item not found in cart. Nothing modified." << endl;
   }
   cout << endl;
}
   // Modifies an item's description, price, and/or quantity. Has parameter ItemToPurchase. Does not return anything.
   // If item can be found (by name) in cart, check if parameter has default values for description, price, and quantity. If not, modify item in cart.
   // If item cannot be found (by name) in cart, output a message: Item not found in cart. Nothing modified.
int ShoppingCart::GetNumItemsInCart() const {
   int totalItems = 0;
   for (unsigned int i = 0; i < this->cartItems.size(); i++) {
      totalItems += this->cartItems.at(i).GetQuantity();
   }
   return totalItems;
}
   // Returns quantity of all items in cart. Has no parameters.
int ShoppingCart::GetCostOfCart() const {
   int totalCost = 0;
   for (unsigned int i = 0; i < this->cartItems.size(); i++) {
      totalCost += (this->cartItems.at(i).GetPrice() * this->cartItems.at(i).GetQuantity());
   }
   return totalCost;
}
   // Determines and returns the total cost of items in cart. Has no parameters.
void ShoppingCart::PrintTotal() const {
   // "OUTPUT SHOPPING CART John Doe's Shopping Cart - February 1, 2016 Number of Items: 0 SHOPPING CART IS EMPTY Total: $0"
   cout << this->GetCustomerName() << "'s Shopping Cart - " << this->GetDate() << endl;
   cout << "Number of Items: " << this->GetNumItemsInCart() << endl;
   cout << endl;
   if (cartItems.size() == 0) {
      cout << "SHOPPING CART IS EMPTY" << endl;
   } else {
      for (unsigned int i = 0; i < this->cartItems.size(); i++) {
         cout << this->cartItems.at(i).GetName() << " " << this->cartItems.at(i).GetQuantity() << " @ $";
         cout << this->cartItems.at(i).GetPrice() << " = $";
         cout << this->cartItems.at(i).GetQuantity() * this->cartItems.at(i).GetPrice() << endl;
      }
   }
   cout << endl;
   cout << "Total: $" << this->GetCostOfCart() << endl;
   cout << endl;
}
   // Outputs total of objects in cart.
   // If cart is empty, output a message: SHOPPING CART IS EMPTY
void ShoppingCart::PrintDescriptions() const {
   cout << this->GetCustomerName() << "'s Shopping Cart - " << this->GetDate() << endl;
   cout << endl;
   if (cartItems.size() == 0) {
      cout << "SHOPPING CART IS EMPTY" << endl;
   } else {
      cout << "Item Descriptions" << endl;
      for (unsigned int i = 0; i < this->cartItems.size(); i++) {
         cout << this->cartItems.at(i).GetName() << ": ";
         cout << this->cartItems.at(i).GetDescription() << endl;
      }
   }
   cout << endl;
}
   // Outputs each item's description.
   // If cart is empty, output a message: SHOPPING CART IS EMPTY
