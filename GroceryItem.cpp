#include "GroceryItem.h"

// Constructor to initialize GroceryItem with a name
GroceryItem::GroceryItem(const std::string& name) : name(name), quantity(1) {}

// Constructor to initialize GroceryItem with a name and quantity
GroceryItem::GroceryItem(const std::string& name, int quantity) : name(name), quantity(quantity) {}

// Get the name of the grocery item
std::string GroceryItem::getName() const { return name; }

// Get the quantity of the grocery item
int GroceryItem::getQuantity() const { return quantity; }

// Increment the quantity of the item
void GroceryItem::addItem() { quantity++; }

// Decrement the quantity of the item
void GroceryItem::removeItem() { if (quantity > 0) quantity--; }

// Comparison operator for sorting items
bool GroceryItem::operator<(const GroceryItem& other) const {
    return name < other.name;
}
