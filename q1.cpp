#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull()  { return top == MAX - 1; }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = x;
        cout << x << " pushed.\n";
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack Empty!\n";
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack Empty!\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack st;
    int choice, val;

    while (true) {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 7) break;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            st.push(val);
            break;

        case 2:
            cout << "Popped: " << st.pop() << endl;
            break;

        case 3:
            cout << (st.isEmpty() ? "Stack is Empty\n" : "Stack is NOT Empty\n");
            break;

        case 4:
            cout << (st.isFull() ? "Stack is Full\n" : "Stack is NOT Full\n");
            break;

        case 5:
            st.display();
            break;

        case 6:
            cout << "Top element: " << st.peek() << endl;
            break;
        }
    }
}
