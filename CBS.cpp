#include <iostream> 
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

class Item {
public:
    int id;
    string name;
    double price;
    int quantity;

    Item(int id, string name, double price, int quantity) {
        this->id = id;
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }
};

class BillingSystem {
private:
    vector<Item> itemList;

public:
    // Load items from file
    void loadItemsFromFile() {
        ifstream file("inventory.txt");
        if (!file) {
            cout << "No inventory file found. Starting with an empty list.\n";
            return;
        }

        string header;
        getline(file, header);  // Read the header line and ignore it

        int id, quantity;
        string name;
        double price;
        while (file >> id >> name >> price >> quantity) {
            itemList.push_back(Item(id, name, price, quantity));
        }
        file.close();
    }

    // Save items to file with header
    void saveItemsToFile() {
        ofstream file("inventory.txt");
        file << "itemid name price quantity\n";  // Header line

        for (const auto &item : itemList) {
            file << item.id << " " << item.name << " " << item.price << " " << item.quantity << endl;
        }
        file.close();
    }

    // Simulate QR code input by user
    void simulateQRCodeInput() {
        string qrData;
        cout << "Enter QR Code data (format: id,name,price,quantity): ";
        cin >> ws;
        getline(cin, qrData);

        size_t pos = 0;
        vector<string> parsedData;
        while ((pos = qrData.find(',')) != string::npos) {
            parsedData.push_back(qrData.substr(0, pos));
            qrData.erase(0, pos + 1);
        }
        parsedData.push_back(qrData);

        if (parsedData.size() == 4) {
            int id = stoi(parsedData[0]);
            string name = parsedData[1];
            double price = stod(parsedData[2]);
            int quantity = stoi(parsedData[3]);

            itemList.push_back(Item(id, name, price, quantity));
            cout << "Item added via simulated QR Code input successfully!\n";
        } else {
            cout << "Invalid input format! Please try again.\n";
        }
    }

    // Add item manually
    void addItem() {
        int id, quantity;
        string name;
        double price;

        cout << "Enter item ID: ";
        cin >> id;
        cout << "Enter item name: ";
        cin >> name;
        cout << "Enter item price: ";
        cin >> price;
        cout << "Enter item quantity: ";
        cin >> quantity;

        itemList.push_back(Item(id, name, price, quantity));
        cout << "Item added successfully!\n";
    }

    // Display all items
    void displayItems() {
        if (itemList.empty()) {
            cout << "No items available!\n";
            return;
        }

        cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Price" << setw(10) << "Quantity\n";
        for (const auto &item : itemList) {
            cout << left << setw(10) << item.id << setw(20) << item.name 
                 << setw(10) << item.price << setw(10) << item.quantity << endl;
        }
    }

    // Generate bill and save to file
    void generateBill() {
        if (itemList.empty()) {
            cout << "No items available to generate a bill!\n";
            return;
        }

        ofstream receiptFile("receipt.txt");
        double total = 0;
        receiptFile << "\nCanteen Billing Receipt\n";
        receiptFile << left << setw(10) << "ID" << setw(20) << "Name" 
                    << setw(10) << "Price" << setw(10) << "Quantity" 
                    << setw(10) << "Subtotal\n";

        for (const auto &item : itemList) {
            double subtotal = item.price * item.quantity;
            total += subtotal;
            receiptFile << left << setw(10) << item.id << setw(20) << item.name 
                        << setw(10) << item.price << setw(10) << item.quantity 
                        << setw(10) << subtotal << endl;
        }

        receiptFile << "Total Amount: " << total << endl;
        receiptFile.close();

        cout << "Bill generated and saved to receipt.txt.\n";
    }

    // Remove item by ID
    void removeItem() {
        int id;
        cout << "Enter item ID to remove: ";
        cin >> id;

        for (auto it = itemList.begin(); it != itemList.end(); ++it) {
            if (it->id == id) {
                itemList.erase(it);
                cout << "Item removed successfully!\n";
                return;
            }
        }
        cout << "Item not found!\n";
    }

    // Update item quantity
    void updateItem() {
        int id, newQuantity;
        cout << "Enter item ID to update: ";
        cin >> id;

        for (auto &item : itemList) {
            if (item.id == id) {
                cout << "Enter new quantity: ";
                cin >> newQuantity;
                item.quantity = newQuantity;
                cout << "Item updated successfully!\n";
                return;
            }
        }
        cout << "Item not found!\n";
    }
};

int main() {
    BillingSystem system;
    system.loadItemsFromFile(); // Load items from file at startup

    int choice;
    bool running = true;

    while (running) {
        cout << "\nCanteen Billing System\n";
        cout << "1. Add Item\n";
        cout << "2. Display Items\n";
        cout << "3. Generate Bill\n";
        cout << "4. Remove Item\n";
        cout << "5. Update Item\n";
        cout << "6. Simulate QR Code Input\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.addItem();
                break;
            case 2:
                system.displayItems();
                break;
            case 3:
                system.generateBill();
                break;
            case 4:
                system.removeItem();
                break;
            case 5:
                system.updateItem();
                break;
            case 6:
                system.simulateQRCodeInput();
                break;
            case 7:
                // fall-through to exit
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                continue;  // back to menu without exit prompt
        }

        if (choice == 7) {
            // exit immediately
            running = false;
        } else {
            char ex;
            cout << "\nPress E to exit or any other key to return to the menu: ";
            cin >> ex;
            if (ex == 'E' || ex == 'e') {
                running = false;
            }
        }
    }

    // Save before quitting
    system.saveItemsToFile();
    cout << "Goodbye!\n";
    return 0;
}
