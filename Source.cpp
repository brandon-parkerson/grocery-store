#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include "GroceryItem.h"

// Create method to read the inventory.txt file 
// and returns a set of GroceryItem
void readInventoryFile(const std::string& filename, std::set<GroceryItem>& items);

// Print the list with numbers that represent the frequency of all items purchased
void displayItemFrequency(const std::set<GroceryItem>& items);

// Print the same frequency information for all the items in the form of a histogram
void displayHistogram(const std::set<GroceryItem>& items);

// Backup the accumulated data to frequency.txt
void backupData(const std::set<GroceryItem>& items, const std::string& backupFilename);

int main() {
    // I use set of GroceryItem here instead of using "map" to include the class
    std::set<GroceryItem> items;
    std::string inputFilename = "Inventory.txt";
    std::string backupFilename = "frequency.dat";

    // Read the inventory file to initialize item frequencies
    readInventoryFile(inputFilename, items);

    // Backup the accumulated data to a file
    backupData(items, backupFilename);

    int choice = 0;
    while (choice != 4) {
        std::cout << "Menu:\n";
        std::cout << "1. Search for an item\n";
        std::cout << "2. Display all item frequencies\n";
        std::cout << "3. Display histogram\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string itemName;
            std::cout << "Enter the item name: ";
            std::cin >> itemName;
            auto it = std::find_if(items.begin(), items.end(), [&](const GroceryItem& item) {
                return item.getName() == itemName;
                });
            if (it != items.end()) {
                std::cout << it->getName() << ": " << it->getQuantity() << std::endl;
            }
            else {
                std::cout << itemName << " not found." << std::endl;
            }
        }
        else if (choice == 2) {
            displayItemFrequency(items);
        }
        else if (choice == 3) {
            displayHistogram(items);
        }
        else if (choice == 4) {
            std::cout << "Exiting program." << std::endl;
        }
        else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}

// Method to read the inventory.txt file and returns a set of GroceryItem
void readInventoryFile(const std::string& filename, std::set<GroceryItem>& items) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }

    std::string itemName;
    while (file >> itemName) {
        auto it = std::find_if(items.begin(), items.end(), [&](const GroceryItem& item) {
            return item.getName() == itemName;
            });
        if (it != items.end()) {
            const_cast<GroceryItem&>(*it).addItem();
        }
        else {
            items.insert(GroceryItem(itemName));
        }
    }
    file.close();
}

// Print the list with numbers that represent the frequency of all items purchased
void displayItemFrequency(const std::set<GroceryItem>& items) {
    for (const auto& item : items) {
        std::cout << item.getName() << " " << item.getQuantity() << std::endl;
    }
}

// Print the same frequency information for all the items in the form of a histogram
void displayHistogram(const std::set<GroceryItem>& items) {
    for (const auto& item : items) {
        std::cout << item.getName() << " ";
        for (int i = 0; i < item.getQuantity(); ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

// Backup the accumulated data to frequency.txt
void backupData(const std::set<GroceryItem>& items, const std::string& backupFilename) {
    std::ofstream backupFile(backupFilename);
    if (!backupFile) {
        std::cerr << "Unable to open backup file " << backupFilename << std::endl;
        return;
    }

    for (const auto& item : items) {
        backupFile << item.getName() << " " << item.getQuantity() << std::endl;
    }
    backupFile.close();
}
