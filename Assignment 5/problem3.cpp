#include <iostream>
using namespace std;

#define MAX 50 // Total size of array

class MultipleStack {
    int arr[MAX]; // Shared array
    int *top;     // Array of top indexes
    int n;        // Number of stacks
    int size;     // Size of each stack

public:
    // Constructor
    MultipleStack(int numStacks, int totalSize) {
        n = numStacks;
        size = totalSize / n;
        top = new int[n];
        for (int i = 0; i < n; i++)
            top[i] = (i * size) - 1;
    }

    // PUSH operation
    void push(int stackNum, int value) {
        if (stackNum < 1 || stackNum > n) {
            cout << "❌ Invalid stack number!\n";
            return;
        }

        int index = stackNum - 1;
        if (top[index] == ((index + 1) * size) - 1) {
            cout << "⚠️ Stack Overflow in Stack " << stackNum << "!\n";
            return;
        }

        arr[++top[index]] = value;
        cout << "✅ Pushed " << value << " into Stack " << stackNum << ".\n";
    }

    // POP operation
    void pop(int stackNum) {
        if (stackNum < 1 || stackNum > n) {
            cout << "❌ Invalid stack number!\n";
            return;
        }

        int index = stackNum - 1;
        if (top[index] == (index * size) - 1) {
            cout << "⚠️ Stack Underflow in Stack " << stackNum << "!\n";
            return;
        }

        cout << "🗑️  Popped " << arr[top[index]--] << " from Stack " << stackNum << ".\n";
    }

    // DISPLAY operation
    void display(int stackNum) {
        if (stackNum < 1 || stackNum > n) {
            cout << "❌ Invalid stack number!\n";
            return;
        }

        int index = stackNum - 1;
        if (top[index] == (index * size) - 1) {
            cout << "⚠️ Stack " << stackNum << " is empty.\n";
            return;
        }

        cout << "📊 Elements in Stack " << stackNum << ": ";
        for (int i = (index * size); i <= top[index]; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// ================= MAIN FUNCTION =================
int main() {
    int numStacks, choice, value, stackNum;

    cout << "============================================\n";
    cout << "   MULTIPLE STACK IMPLEMENTATION USING ARRAY\n";
    cout << "============================================\n";

    cout << "Enter number of stacks to create (e.g. 3): ";
    cin >> numStacks;

    MultipleStack ms(numStacks, MAX);

    do {
        cout << "\n------ MENU ------\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display Stack\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter stack number: ";
            cin >> stackNum;
            cout << "Enter value to push: ";
            cin >> value;
            ms.push(stackNum, value);
            break;
        case 2:
            cout << "Enter stack number: ";
            cin >> stackNum;
            ms.pop(stackNum);
            break;
        case 3:
            cout << "Enter stack number: ";
            cin >> stackNum;
            ms.display(stackNum);
            break;
        case 4:
            cout << "Exiting program... Thank you!\n";
            break;
        default:
            cout << "⚠️ Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
