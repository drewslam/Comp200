#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <string>
#include <vector>
#include "ItemToPurchase.h"

class ShoppingCart {
   public:
   ShoppingCart();
   ShoppingCart(string name, string date);
   string GetCustomerName() const;
   string GetDate() const;
   void AddItem(ItemToPurchase item);
      // Adds an item to cartItems vector. Has parameter ItemToPurchase. Does not return anything.
   void RemoveItem(string name);
      // Removes item from cartItems vector. Has a string (an item's name) parameter. Does not return anything.
      // If item name cannot be found, output a message: Item not found in cart. Nothing removed.
   void ModifyItem(ItemToPurchase item);
      // Modifies an item's description, price, and/or quantity. Has parameter ItemToPurchase. Does not return anything.
      // If item can be found (by name) in cart, check if parameter has default values for description, price, and quantity. If not, modify item in cart.
      // If item cannot be found (by name) in cart, output a message: Item not found in cart. Nothing modified.
   int GetNumItemsInCart() const;// (2 pts)
      // Returns quantity of all items in cart. Has no parameters.
   int GetCostOfCart() const;// (2 pts)
      // Determines and returns the total cost of items in cart. Has no parameters.
   void PrintTotal() const;
      // Outputs total of objects in cart.
      // If cart is empty, output a message: SHOPPING CART IS EMPTY
   void PrintDescriptions() const;
      // Outputs each item's description.
      // If cart is empty, output a message: SHOPPING CART IS EMPTY
   private:
      string customerName; // - Initialized in default constructor to "none"
      string currentDate; // - Initialized in default constructor to "January 1, 2016"
      vector<ItemToPurchase> cartItems;
};

#endif
