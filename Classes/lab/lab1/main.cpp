#include <iostream>
#include <string>
using namespace std;

#include "ItemToPurchase.h"

int main() {
   
   ItemToPurchase item1;
   ItemToPurchase item2;
   string tempName;
   int tempPrice;
   int tempQty;
   
   cout << "Item 1" << endl;
   cout << "Enter the item name:" << endl;
   getline(cin, tempName);
   item1.SetName(tempName);
   cout << "Enter the item price:" << endl;
   cin >> tempPrice;
   item1.SetPrice(tempPrice);
   cout << "Enter the item quantity:" << endl;
   cin >> tempQty;
   item1.SetQuantity(tempQty);
   cout << endl;
   cin.ignore();
   
   cout << "Item 2" << endl;
   cout << "Enter the item name:" << endl;
   getline(cin, tempName);
   item2.SetName(tempName);
   cout << "Enter the item price:" << endl;
   cin >> tempPrice;
   item2.SetPrice(tempPrice);
   cout << "Enter the item quantity:" << endl;
   cin >> tempQty;
   item2.SetQuantity(tempQty);
   cout << endl;
   
   cout << "TOTAL COST" << endl;
   cout << item1.GetName() << " " << item1.GetQuantity();
   cout << " @ $" << item1.GetPrice() << " = $";
   cout << item1.GetPrice() * item1.GetQuantity() << endl;
   cout << item2.GetName() << " " << item2.GetQuantity();
   cout << " @ $" << item2.GetPrice() << " = $";
   cout << item2.GetPrice() * item2.GetQuantity() << endl;
   cout << endl;

   cout << "Total: $";
   cout << item1.GetPrice() * item1.GetQuantity() + item2.GetPrice() * item2.GetQuantity();
   cout << endl;
   
   return 0;
}
