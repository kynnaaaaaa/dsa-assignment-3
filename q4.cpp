#include <iostream>
#include <stack>
using namespace std;

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> st;
    string post = "";

    for (char c : infix) {
        if (isalnum(c))
            post += c;
        else if (c == '(')
            st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                post += st.top();
                st.pop();
            }
            st.pop();
        } 
        else {
            while (!st.empty() && precedence(c) <= precedence(st.top())) {
                post += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        post += st.top();
        st.pop();
    }
    return post;
}

int main() {
    string infix;
    cout << "Enter infix: ";
    cin >> infix;

    cout << "Postfix: " << infixToPostfix(infix);
}
