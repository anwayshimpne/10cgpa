#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to check if character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Convert infix to postfix and display steps
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    cout << "\n--- Step-by-Step Conversion ---\n";
    cout << "Symbol\tStack\t\tPostfix\n";
    cout << "----------------------------------------\n";

    for (char c : infix) {
        // Operand → directly add to postfix
        if (isalnum(c)) {
            postfix += c;
        }

        // Opening parenthesis → push to stack
        else if (c == '(') {
            s.push(c);
        }

        // Closing parenthesis → pop until '('
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Remove '('
        }

        // Operator
        else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }

        // Print current step
        cout << c << "\t";
        // Display stack contents
        stack<char> temp = s;
        string stContent = "";
        while (!temp.empty()) {
            stContent = temp.top() + stContent;
            temp.pop();
        }
        cout << stContent << "\t\t" << postfix << endl;
    }

    // Pop remaining operators
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    cout << "----------------------------------------\n";
    return postfix;
}

int main() {
    string infix;
    cout << "===========================================\n";
    cout << " INFIX TO POSTFIX CONVERSION USING STACK\n";
    cout << "===========================================\n";

    cout << "Enter infix expression (e.g. a-b*c-d/e+f): ";
    cin >> infix;

    string postfix = infixToPostfix(infix);

    cout << "\n Final Postfix Expression: " << postfix << endl;
    return 0;
}
