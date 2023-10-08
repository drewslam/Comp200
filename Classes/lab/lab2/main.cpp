#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"

void PrintMenu() {
   cout << "MENU" << endl;
   cout << "a - Add item to cart" << endl;
   cout << "d - Remove item from cart" << endl;
   cout << "c - Change item quantity" << endl;
   cout << "i - Output items' descriptions" << endl;
   cout << "o - Output shopping cart" << endl;
   cout << "q - Quit" << endl;
   cout << endl;
}

void ExecuteMenu(char option, ShoppingCart& theCart) {
   string name;
   string description;
   int price;
   int qty;
   char newOption = option;
   while (newOption != 'q') {
         cin.ignore();
         ItemToPurchase newItem;
      if (newOption == 'a') {
         cout << "ADD ITEM TO CART" << endl;
         cout << "Enter the item name:" << endl;
         getline(cin,name);
         newItem.SetName(name);
         cout << "Enter the item description:" << endl;
         getline(cin,description);
         newItem.SetDescription(description);
         cout << "Enter the item price:" << endl;
         cin >> price;
         newItem.SetPrice(price);
         cout << "Enter the item quantity:" << endl;
         cin >> qty;
         newItem.SetQuantity(qty);
         theCart.AddItem(newItem);
         cout << endl;
         PrintMenu();
      } else if (newOption == 'd') {
         cout << "REMOVE ITEM FROM CART" << endl;
         cout << "Enter name of item to remove:" << endl;
         getline(cin,name);
         theCart.RemoveItem(name);
         PrintMenu();
      } else if (newOption == 'c') {
         cout << "CHANGE ITEM QUANTITY" << endl;
         cout << "Enter the item name:" << endl;
         getline(cin,name);
         cout << "Enter the new quantity:" << endl;
         cin >> qty;
         newItem.SetName(name);
         newItem.SetQuantity(qty);
         theCart.ModifyItem(newItem);
         PrintMenu();
      } else if (newOption == 'i') {
         cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
         theCart.PrintDescriptions();
         PrintMenu();
      } else if (newOption == 'o') {
         cout << "OUTPUT SHOPPING CART" << endl;
         theCart.PrintTotal();
         PrintMenu();
      }
      cout << "Choose an option:" << endl;
      cin >> newOption;
   }
}

int main() {
   string name;
   string date;
   char option;

   cout << "Enter customer's name:" << endl;
   getline(cin, name);
   cout << "Enter today's date:" << endl;
   getline(cin, date);
   cout << endl;
   cout << "Customer name: " << name << endl;
   cout << "Today's date: " << date << endl;
   cout << endl;

   ShoppingCart shoppingCart(name,date);

   PrintMenu();

   cout << "Choose an option:" << endl;
   cin >> option;
   ExecuteMenu(option, shoppingCart);

   return 0;
}
