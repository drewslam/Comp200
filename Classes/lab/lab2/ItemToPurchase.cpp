#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() {
   this->itemName = "none";
   this->itemDescription = "none";
   this->itemPrice = 0;
   this->itemQuantity = 0;
}

ItemToPurchase::ItemToPurchase(string name, string description, int price, int qty) {
   this->itemName = name;
   this->itemDescription = description;
   this->itemPrice = price;
   this->itemQuantity = qty;
}

void ItemToPurchase::SetName(string name) {
   this->itemName = name;
}

string ItemToPurchase::GetName() const {
   return this->itemName;
}

void ItemToPurchase::SetDescription(string description) {
   this->itemDescription = description;
}

string ItemToPurchase::GetDescription() const {
   return this->itemDescription;
}

void ItemToPurchase::SetPrice(int price) {
   this->itemPrice = price;
}

int ItemToPurchase::GetPrice() const {
   return this->itemPrice;
}

void ItemToPurchase::SetQuantity(int qty) {
   this->itemQuantity = qty;
}

int ItemToPurchase::GetQuantity() const {
   return this->itemQuantity;
}

void ItemToPurchase::PrintItemCost() const {
   cout << GetName() << " " << GetQuantity();
   cout << " @ $" << GetPrice() << " = $";
   cout << GetPrice() * GetQuantity() << endl;
}

void ItemToPurchase::PrintItemDescription() const {
   cout << GetName() << " " << GetDescription() << endl;
}
