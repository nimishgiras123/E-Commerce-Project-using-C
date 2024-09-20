#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

struct Product {
    int id;
    string name;
    double price;
    int quantity;
    string category;
};

const string adminPassword = "root123";

void addProduct(vector<Product>& inventory, int id, const string& name, double price, int quantity, const string& category) {
    Product product = { id, name, price, quantity, category };
    inventory.push_back(product);
}

void displayInventory(const vector<Product>& inventory) {
    if (inventory.size() != 0) {
        cout << "Inventory:\n";
        for (const Product& product : inventory) {
            cout << "ID: " << product.id << ", Name: " << product.name << ", Price: Rs " << product.price << ", Quantity: " << product.quantity << ", Category: " << product.category << endl;
        }
    }
    else {
        cout << "Your Cart is Empty!\n";
    }
}



// FILE HANDLING
void writeInventoryToFile(const vector<Product>& inventory) {
    ofstream outFile("Inventory.txt");

    if (outFile.is_open()) {
        for (const Product& product : inventory) {
            outFile << product.id << "," << product.name << "," << product.price << "," << product.quantity << "," << product.category << endl;
        }
        outFile.close();
        cout << "Inventory written to file successfully." << endl;
    }
    else {
        cout << "Unable to open file for writing." << endl;
    }
}


void fetchInventoryFromFile(vector<Product>& inventory) {
    ifstream inFile("Inventory.txt");

    if (inFile.is_open()) {
        inventory.clear(); // Clear existing inventory

        int id, quantity;
        double price;
        string name, category;

        while (inFile >> id >> name >> price >> quantity >> category) {
            addProduct(inventory, id, name, price, quantity, category);
        }

        inFile.close();
        cout << "Inventory fetched from file successfully." << endl;
    }
    else {
        cout << "Unable to open file for reading." << endl;
    }
}

void writeCartToFile(const vector<Product>& cart) {
    ofstream outFile("cart.txt");

    if (outFile.is_open()) {
        for (const Product& product : cart) {
            outFile << product.id << "," << product.name << "," << product.price << "," << product.quantity << "," << product.category << endl;
        }
        outFile.close();
        cout << "Cart items written to file successfully." << endl;
    }
    else {
        cout << "Unable to open file for writing." << endl;
    }
}
void writeBillToFile(const vector<Product>& cart) {
    ofstream billFile("bill.txt");

    if (billFile.is_open()) {
        for (const Product& product : cart) {
            billFile << "ID: " << product.id << ", Name: " << product.name << ", Price: Rs " << product.price << ", Quantity: " << product.quantity << ", Category: " << product.category << endl;
        }
        billFile.close();
        cout << "Bill details written to file successfully." << endl;
    }
    else {
        cout << "Unable to open file for writing bill details." << endl;
    }
}


int binarySearch(const vector<Product>& inventory, int id) {
    int left = 0;
    int right = inventory.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (inventory[mid].id == id) {
            return mid;  // Product found, return its index
        }

        if (inventory[mid].id < id) {
            left = mid + 1;  // Search in the right half
        }
        else {
            right = mid - 1;  // Search in the left half
        }
    }

    return -1;  // Product not found
}

void searchProduct(const vector<Product>& inventory, int id) {
    int index = binarySearch(inventory, id);
    if (index != -1) {
        const Product& product = inventory[index];
        cout << "Product ID: " << product.id << ", Name: " << product.name << ", Price: Rs " << product.price << ", Quantity: " << product.quantity << ", Category: " << product.category << endl;
    }
    else {
        cout << "Product not found." << endl;
    }
}

void updateProductQuantity(vector<Product>& inventory, int id, int newQuantity) {
    for (Product& product : inventory) {
        if (product.id == id) {
            product.quantity = newQuantity;
            cout << "Product quantity updated successfully." << endl;
            return;
        }
    }
    cout << "Product not found." << endl;
}

void removeProduct(vector<Product>& inventory, int id) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->id == id) {
            inventory.erase(it);
            cout << "Product removed successfully." << endl;
            return;
        }
    }
    cout << "Product not found." << endl;
}

double calculateTotalBill(const vector<Product>& cart) {
    double total = 0.0;
    for (const Product& product : cart) {
        total += product.price * product.quantity;
    }
    return total;
}

void sortProductsByName(vector<Product>& inventory) {
    sort(inventory.begin(), inventory.end(), [](const Product& a, const Product& b) {
        return a.name < b.name;
    });
}

bool isProductAvailable(const vector<Product>& inventory, int id, int quantity) {
    for (const Product& product : inventory) {
        if (product.id == id && product.quantity >= quantity) {
            return true;
        }
    }
    return false;
}

void addProductAdmin(vector<Product>& inventory) {
    int id, quantity;
    double price;
    string name, category;

    cout << "Enter Product ID: ";
    cin >> id;
    cout << "Enter Product Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Product Price: $";
    cin >> price;
    cout << "Enter Product Quantity: ";
    cin >> quantity;
    cout << "Enter Product Category: ";
    cin.ignore();
    getline(cin, category);

    addProduct(inventory, id, name, price, quantity, category);
    cout << "Product added to the inventory successfully." << endl;
}

void updateProductAdmin(vector<Product>& inventory, int id) {
    for (Product& product : inventory) {
        if (product.id == id) {
            double price;
            string name;

            cout << "Enter New Product Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter New Product Price: Rs ";
            cin >> price;

            product.name = name;
            product.price = price;

            cout << "Product updated successfully." << endl;
            return;
        }
    }
    cout << "Product not found." << endl;
}

void deleteProductAdmin(vector<Product>& inventory, int id) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->id == id) {
            inventory.erase(it);
            cout << "Product deleted successfully." << endl;
            return;
        }
    }
    cout << "Product not found." << endl;
}

void displayInventoryByCategory(const vector<Product>& inventory, const string& category) {
    cout << "Inventory for Category: " << category << "\n";
    for (const Product& product : inventory) {
        if (product.category == category) {
            cout << "ID: " << product.id << ", Name: " << product.name << ", Price: Rs " << product.price << ", Quantity: " << product.quantity << ", Category: " << product.category << endl;
        }
    }
}

void sortAndDisplayCategory(vector<Product>& inventory, char sortOption, const string& category) {
    vector<Product> categoryItems;

    // Filter items of the selected category
    for (const Product& product : inventory) {
        if (product.category == category) {
            categoryItems.push_back(product);
        }
    }

    if (sortOption == 'P' || sortOption == 'p') {
        sort(categoryItems.begin(), categoryItems.end(), [](const Product& a, const Product& b) {
            return a.price < b.price;
        });
    }
    else if (sortOption == 'C' || sortOption == 'c') {
        sort(categoryItems.begin(), categoryItems.end(), [](const Product& a, const Product& b) {
            return a.category < b.category;
        });
    }

    displayInventory(categoryItems);
}

void sortInventoryByCategory(vector<Product>& inventory) {
    // Define a custom comparison function for sorting by category
    auto customCategoryComparator = [](const Product& a, const Product& b) -> bool {
        // Define the desired order of categories
        const vector<string> categoryOrder = {"Electronics", "Food Items", "Apparels"};

        // Find the indices of the categories for a and b in the order vector
        auto aCategoryIndex = find(categoryOrder.begin(), categoryOrder.end(), a.category);
        auto bCategoryIndex = find(categoryOrder.begin(), categoryOrder.end(), b.category);

        // Compare the category indices to determine the order
        if (aCategoryIndex != categoryOrder.end() && bCategoryIndex != categoryOrder.end()) {
            return distance(categoryOrder.begin(), aCategoryIndex) < distance(categoryOrder.begin(), bCategoryIndex);
        } else {
            // Handle categories not in the specified order (e.g., if new categories are added)
            // Sort them alphabetically
            return a.category < b.category;
        }
    };

    // Sort inventory using the custom comparison function
    sort(inventory.begin(), inventory.end(), customCategoryComparator);

    // Print the sorted inventory
    displayInventory(inventory);
}

void quickSortByPrice(vector<Product>& inventory, int left, int right) {
    if (left < right) {
        int pivot = left;
        int i = left;
        int j = right;

        while (i < j) {
            while (inventory[i].price <= inventory[pivot].price && i < right) {
                i++;
            }

            while (inventory[j].price > inventory[pivot].price) {
                j--;
            }

            if (i < j) {
                swap(inventory[i], inventory[j]);
            }
        }

        swap(inventory[pivot], inventory[j]);

        quickSortByPrice(inventory, left, j - 1);
        quickSortByPrice(inventory, j + 1, right);
    }
}

void sortInventoryByPrice(vector<Product>& inventory) {
     int left = 0;
    int right = inventory.size() - 1;
    quickSortByPrice(inventory, left, right);
}


int main() {
    vector<Product> inventory;

    // Sample data
    addProduct(inventory, 1, "Realme Narzo 20 Pro", 17000, 50, "Electronics");
    addProduct(inventory, 2, "Realme Narzo C2", 15000, 30, "Electronics");
    addProduct(inventory, 3, "Oneplus 11 R", 40000, 40, "Electronics");
    addProduct(inventory, 4, "Iphone 15 Pro", 115000, 40, "Electronics");
    addProduct(inventory, 5, "Oneplus Nord ", 21000, 40, "Electronics");
    addProduct(inventory, 6, "Lenovo Ideapad", 78000, 40, "Electronics");
    addProduct(inventory, 7, "Dell Inspirion 14", 84000, 40, "Electronics");
    addProduct(inventory, 8, "Hp Pavilion", 75000, 40, "Electronics");
    addProduct(inventory, 9, "Chrome Book", 92000, 40, "Electronics");
    addProduct(inventory, 10, "Apple Macbook Pro M2", 250000, 40, "Electronics");
    addProduct(inventory, 11, "Max T-shirt", 1500, 34, "Apparels");
    addProduct(inventory, 12, "Peter England Shirt", 2500, 23, "Apparels");
    addProduct(inventory, 13, "Rakuten T-shirt", 1300, 40, "Apparels");
    addProduct(inventory, 14, "Levis Jeans", 3450, 77, "Apparels");
    addProduct(inventory, 15, "Wranglar Jeans", 4350, 33, "Apparels");
    addProduct(inventory, 16, "Monte-Carlo T shirt", 1250, 40, "Apparels");
    addProduct(inventory, 17, "H&M shirt", 770, 22, "Apparels");
    addProduct(inventory, 18, "Puma lower", 1230, 22, "Apparels");
    addProduct(inventory, 19, "Nike Sports lower", 2500, 34, "Apparels");
    addProduct(inventory, 20, "Denim Jacket", 2500,29, "Apparels");
    addProduct(inventory, 21, "Parle G Gold", 10,120,"Food Items");
    addProduct(inventory, 22, "Diamond Chulbule", 25, 88,"Food Items");
    addProduct(inventory, 23, "Haldiram Bhujia", 120, 40,"Food Items");
    addProduct(inventory, 24, "Diamond Aloo bhujia", 140, 40,"Food Items");
    addProduct(inventory, 25, "Bourbon", 45, 40,"Food Items");
    addProduct(inventory, 26, "Hide and Seek", 35, 40,"Food Items");
    addProduct(inventory, 27, "Soya chips", 55, 40,"Food Items");
    addProduct(inventory, 28, "Soya sticks", 55, 40,"Food Items");
    addProduct(inventory, 29, "Kurkure", 25, 40,"Food Items");
    addProduct(inventory, 30, "Jim Jam", 30, 60,"Food Items");

    // writeInventoryToFile(inventory);
    fetchInventoryFromFile(inventory);

    vector<Product> cart;
    bool isAdmin = false;
    cout << "* WELCOME TO SHOPIFY **" << endl;
    cout << "* You name it we have it!! **" << endl;
    while (true) {
        if (!isAdmin) {
            cout << endl;
            cout << "OPERATIONS\n";
            cout << "1. Display Inventory\n";
            cout << "2. Search for a Product by ID\n";
            cout << "3. Add Product to Cart\n";
            cout << "4. Display Cart\n";
            cout << "5. Checkout\n";
            cout << "6. Sort Products by Name\n";
            cout << "7. Check Product Availability\n";
            cout << "8. Enter Admin Mode\n";
            cout << "9. Display Inventory By Category\n";
            cout << "10. Exit\n";
        }
        else {
            cout << "Admin Options:\n";
            cout << "1. Display Inventory\n";
            cout << "2. Search for a Product by ID\n";
            cout << "3. Update Product\n";
            cout << "4. Delete Product\n";
            cout << "5. Add Product (Admin)\n";
            cout << "6. Exit Admin Mode\n";
        }

        int choice;
        cout << "Enter Your choice: ";
        cin >> choice;

        if (!isAdmin) {
            if (choice == 1) {
                displayInventory(inventory);
            }
            else if (choice == 2) {
                cout << "Enter Product ID: ";
                int id;
                cin >> id;
                searchProduct(inventory, id);
            }
            else if (choice == 3) {
                cout << "Enter Product ID to Add to Cart: ";
                int id;
                cin >> id;
                cout << "Enter Quantity: ";
                int quantity;
                cin >> quantity;
                if (isProductAvailable(inventory, id, quantity)) {
                    for (Product& product : inventory) {
                        if (product.id == id) {
                            product.quantity -= quantity;
                            addProduct(cart, product.id, product.name, product.price, quantity, product.category);
                            cout << "Product added to cart successfully." << endl;
                            break;
                        }
                    }
                }
                else {
                    cout << "Product not available in the desired quantity." << endl;
                }
            }
            else if (choice == 4) {
                displayInventory(cart);
            }
            else if (choice == 5) {
                displayInventory(cart);
                double totalBill = calculateTotalBill(cart);
                cout << "Total Bill: Rs " << totalBill << endl;
                writeBillToFile(cart);
            }
            else if (choice == 6) {
                sortProductsByName(inventory);
                cout << "Products sorted by name." << endl;
            }
            else if (choice == 7) {
                cout << "Enter Product ID: ";
                int id;
                cin >> id;
                cout << "Enter Quantity: ";
                int quantity;
                cin >> quantity;
                if (isProductAvailable(inventory, id, quantity)) {
                    cout << "Product is available in the desired quantity." << endl;
                }
                else {
                    cout << "Product not available in the desired quantity." << endl;
                }
            }
            else if (choice == 8) {
                string password;
                cout << "Enter the admin password: ";
                cin >> password;
                if (password == adminPassword) {
                    isAdmin = true;
                    cout << "Access granted. Now in admin mode." << endl;
                }
                else {
                    cout << "Wrong password. Access denied." << endl;
                }
            }
            else if (choice == 9) {
                    string category;
                    cout << "Enter Category ('All', 'Electronics', 'Apparels', 'Food Items'): ";
                    cin.ignore();
                    getline(cin, category);

                    if (category == "All") {
                        char sortChoice;
                        cout << "Do you want to sort items (y/n)? ";
                        cin >> sortChoice;
                        if (sortChoice == 'y' || sortChoice == 'Y') {
                            char sortOption;
                            cout << "Sort by (P)rice or (C)ategory? ";
                            cin >> sortOption;
                            if (sortOption == 'C'){
                                sortInventoryByCategory(inventory);
                            }
                            else if (sortOption == 'P'){
                                sortInventoryByPrice(inventory);
                                displayInventory(inventory);
                            }
                        } else {
                            displayInventory(inventory);  // Display the entire inventory without sorting
                        }
                    } else {
                        char sortChoice;
                        cout << "Do you want to sort items (y/n)? ";
                        cin >> sortChoice;
                        if (sortChoice == 'y' || sortChoice == 'Y') {
                            char sortOption;
                            cout << "Sort by (P)rice or (C)ategory? ";
                            cin >> sortOption;

                            sortAndDisplayCategory(inventory, sortOption, category);
                        } else {
                            // Display the unsorted category items
                            displayInventoryByCategory(inventory, category);
                        }
                    }
                }


            else if (choice == 10) {
                writeInventoryToFile(inventory);
                writeCartToFile(cart);
                cout << "Thank You for Shopping with us! Hope to see you soon!!";
                break;
            }
            else {
                cout << "Invalid choice. Try again." << endl;
            }
        }
        else {
            if (choice == 1) {
                displayInventory(inventory);
            }
            else if (choice == 2) {
                cout << "Enter Product ID: ";
                int id;
                cin >> id;
                searchProduct(inventory, id);
            }
            else if (choice == 3) {
                cout << "Enter Product ID to Update: ";
                int id;
                cin >> id;
                updateProductAdmin(inventory, id);
            }
            else if (choice == 4) {
                cout << "Enter Product ID to Delete: ";
                int id;
                cin >> id;
                deleteProductAdmin(inventory, id);
            }
            else if (choice == 5) {
                addProductAdmin(inventory);
            }
            else if (choice == 6) {
                isAdmin = false;
                cout << "Exiting admin mode." << endl;
            }
            else {
                cout << "Invalid admin choice. Try again." << endl;
            }
        }

    }
    return 0;
}
