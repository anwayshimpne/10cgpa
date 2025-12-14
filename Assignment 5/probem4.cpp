#include <iostream>
#include <stack>
using namespace std;

// Function to check if brackets are balanced
bool isBalanced(string s) {
    stack<char> st;
    for (char ch : s) {
        // Push opening brackets
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        else {
            // If stack empty → no matching opening bracket
            if (st.empty())
                return false;
            char top = st.top();
            st.pop();

            // Check matching pair
            if ( (ch == ')' && top != '(') ||
                 (ch == '}' && top != '{') ||
                 (ch == ']' && top != '[') ) {
                return false;
            }
        }
    }
    // If stack is empty → balanced
    return st.empty();
}
int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;
    if (isBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}
