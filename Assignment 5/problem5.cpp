#include <iostream>
#include <stack>
using namespace std;

// Function to evaluate postfix expression
int evaluatePostfix(string exp) {
    stack<int> st;

    for (char ch : exp) {
        // If operand (0-9), push to stack
        if (isdigit(ch)) {
            st.push(ch - '0');  // Convert char to int
        }
        else {
            // Operator: pop top two elements
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            int result;

            // Perform operation
            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }

            // Push result back
            st.push(result);
        }
    }

    // Final result on top of stack
    return st.top();
}

int main() {
    string exp;
    cout << "Enter postfix expression: ";
    cin >> exp;

    cout << "Result = " << evaluatePostfix(exp);

    return 0;
}
