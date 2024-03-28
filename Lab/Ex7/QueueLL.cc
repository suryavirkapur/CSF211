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

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        std::cout << "Enqueued " << value << "." << std::endl;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        std::cout << "Dequeued " << temp->data << " from the queue." << std::endl;
        delete temp;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1;
        }
        return front->data;
    }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Front element: " << queue.peek() << std::endl;

    queue.dequeue();
    queue.dequeue();

    std::cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << std::endl;

    queue.dequeue();
    queue.dequeue();

    return 0;
}