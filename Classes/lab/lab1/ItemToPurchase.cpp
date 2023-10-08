#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() {
   this->itemName = "none";
   this->itemPrice = 0;
   this->itemQuantity = 0;
}

void ItemToPurchase::SetName(string name) {
   this->itemName = name;
}

string ItemToPurchase::GetName() const { 
   return this->itemName; 
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
