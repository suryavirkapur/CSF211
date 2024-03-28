#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        std::cout << "Pushed " << value << "." << std::endl;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        std::cout << "Popped " << temp->data << std::endl;
        delete temp;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }
        return top->data;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.peek() << std::endl;

    stack.pop();
    stack.pop();

    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    stack.pop();
    stack.pop();

    return 0;
}