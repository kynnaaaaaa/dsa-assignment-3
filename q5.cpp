#include <iostream>
#include <stack>
using namespace std;

int evaluatePostfix(string post) {
    stack<int> st;

    for (char c : post) {
        if (isdigit(c))
            st.push(c - '0');
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            switch (c) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }
    return st.top();
}

int main() {
    string post;
    cout << "Enter postfix expression: ";
    cin >> post;

    cout << "Result = " << evaluatePostfix(post);
}
