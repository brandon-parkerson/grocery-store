#pragma once
#include <string>

class GroceryItem {
public:
    // Constructor to initialize GroceryItem with a name
    GroceryItem(const std::string& name);

    // Constructor to initialize GroceryItem with a name and quantity
    GroceryItem(const std::string& name, int quantity);

    // Get the name of the grocery item
    std::string getName() const;

    // Get the quantity of the grocery item
    int getQuantity() const;

    // Increment the quantity of the item
    void addItem();

    // Decrement the quantity of the item
    void removeItem();

    // Comparison operator for sorting items
    bool operator<(const GroceryItem& other) const;

private:
    std::string name; // Name of the grocery item
    int quantity;     // Quantity of the grocery item
};
