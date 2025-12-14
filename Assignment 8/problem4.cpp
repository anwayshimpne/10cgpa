#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// Product Node structure
class Product {
public:
    string productCode;
    string name;
    float price;
    int quantity;
    string dateReceived;
    string expirationDate;
    Product* left;
    Product* right;

    Product(string code, string n, float p, int q, string dr, string exp) {
        productCode = code;
        name = n;
        price = p;
        quantity = q;
        dateReceived = dr;
        expirationDate = exp;
        left = right = NULL;
    }
};

// Product Tree class
class ProductTree {
private:
    Product* root;

    // Helper function for insertion (based on name)
    Product* insert(Product* node, string code, string name, float price, int qty, string rec, string exp) {
        if (node == NULL)
            return new Product(code, name, price, qty, rec, exp);

        if (name < node->name)
            node->left = insert(node->left, code, name, price, qty, rec, exp);
        else if (name > node->name)
            node->right = insert(node->right, code, name, price, qty, rec, exp);
        else
            cout << " Duplicate Product Name not allowed!\n";

        return node;
    }

    // Inorder Traversal: Display all products (sorted by name)
    void inorder(Product* node) {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << "Product Code: " << node->productCode
             << " | Name: " << node->name
             << " | Price: " << node->price
             << " | Qty: " << node->quantity
             << " | Received: " << node->dateReceived
             << " | Expiry: " << node->expirationDate << endl;
        inorder(node->right);
    }

    // Preorder Traversal: Display expired items
    void preorderExpired(Product* node) {
        if (node == NULL)
            return;

        if (isExpired(node->expirationDate))
            cout << " Expired Product → " << node->name
                 << " (Expiry: " << node->expirationDate << ")\n";

        preorderExpired(node->left);
        preorderExpired(node->right);
    }

    // Helper function to check if product is expired
    bool isExpired(string expDate) {
        int day, month, year;
        sscanf(expDate.c_str(), "%d/%d/%d", &day, &month, &year);

        time_t t = time(0);
        tm* now = localtime(&t);
        int cDay = now->tm_mday;
        int cMonth = now->tm_mon + 1;
        int cYear = now->tm_year + 1900;

        if (year < cYear) return true;
        if (year == cYear && month < cMonth) return true;
        if (year == cYear && month == cMonth && day < cDay) return true;
        return false;
    }

public:
    ProductTree() { root = NULL; }

    // Insert Product
    void insertProduct(string code, string name, float price, int qty, string rec, string exp) {
        root = insert(root, code, name, price, qty, rec, exp);
    }

    // Display all products
    void displayAll() {
        cout << "\n Product Inventory (Sorted by Product Name):\n";
        cout << "-------------------------------------------------------------\n";
        inorder(root);
    }

    // Display expired products
    void displayExpired() {
        cout << "\n List of Expired Products (Preorder Traversal):\n";
        cout << "-------------------------------------------------------------\n";
        preorderExpired(root);
    }
};

// ================= MAIN FUNCTION =================
int main() {
    ProductTree inventory;
    int choice, qty;
    string code, name, rec, exp;
    float price;

    cout << "=================================================\n";
    cout << "  PRODUCT INVENTORY MANAGEMENT USING TREE (BST)\n";
    cout << "=================================================\n";

    do {
        cout << "\n------ MENU ------\n";
        cout << "1. Insert New Product\n";
        cout << "2. Display All Products (Inorder)\n";
        cout << "3. List Expired Products (Preorder)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Product Code: ";
            cin >> code;
            cout << "Enter Product Name: ";
            cin >> name;
            cout << "Enter Price: ";
            cin >> price;
            cout << "Enter Quantity: ";
            cin >> qty;
            cout << "Enter Date Received (dd/mm/yyyy): ";
            cin >> rec;
            cout << "Enter Expiration Date (dd/mm/yyyy): ";
            cin >> exp;
            inventory.insertProduct(code, name, price, qty, rec, exp);
            cout << "Product inserted successfully!\n";
            break;

        case 2:
            inventory.displayAll();
            break;

        case 3:
            inventory.displayExpired();
            break;

        case 4:
            cout << "Exiting program... Thank you!\n";
            break;

        default:
            cout << " Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
