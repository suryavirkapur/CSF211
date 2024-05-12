# CSF211

**1 Searching Algorithms**

* **Linear Search**: Iterate through an array and check each element until the target element is found.
```cpp
int linearSearch(int arr[], int target, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // not found
}
```
* **Binary Search**: Find an element in a sorted array by repeatedly dividing the search interval in half.
```cpp
int binarySearch(int arr[], int target, int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // not found
}
```
**2 Singly Linked List**

* **Node structure**:
```cpp
struct Node {
    int data;
    Node* next;
};
```
* **Insertion**:
```cpp
void insert(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
```
* **Traversal**:
```cpp
void traverse(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
```
**3 Stack Operations (using array implementation)**

* **Stack structure**:
```cpp
class Stack {
    int arr[100];
    int top;
public:
    Stack() : top(-1) {}
    void push(int data);
    int pop();
    int topElement();
    bool isEmpty();
};
```
* **Push**:
```cpp
void Stack::push(int data) {
    if (top == 99) {
        cout << "Stack overflow!" << endl;
        return;
    }
    arr[++top] = data;
}
```
* **Pop**:
```cpp
int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack underflow!" << endl;
        return -1;
    }
    return arr[top--];
}
```
* **Top Element**:
```cpp
int Stack::topElement() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return arr[top];
}
```
* **Is Empty**:
```cpp
bool Stack::isEmpty() {
    return top == -1;
}
```
**5 Queue Operations (using array implementation)**

* **Queue structure**:
```cpp
class Queue {
    int arr[100];
    int front, rear;
public:
    Queue() : front(0), rear(0) {}
    void enqueue(int data);
    int dequeue();
    int frontElement();
    bool isEmpty();
};
```
* **Enqueue**:
```cpp
void Queue::enqueue(int data) {
    if ((rear + 1) % 100 == front) {
        cout << "Queue is full!" << endl;
        return;
    }
    arr[rear++] = data;
    rear %= 100;
}
```
* **Dequeue**:
```cpp
int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    int data = arr[front++];
    front %= 100;
    return data;
}
```
* **Front Element**:
```cpp
int Queue::frontElement() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return arr[front];
}
```
* **Is Empty**:
```cpp
bool Queue::isEmpty() {
    return front == rear;
}
```
**6 Sorting Algorithms**

* **Quick Sort**:
```cpp
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
```
* **Merge Sort**:
```cpp
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void merge(int arr[], int low, int mid, int high) {
    int left[mid - low + 1];
    int right[high - mid];
    for (int i = low; i <= mid; i++) {
        left[i - low] = arr[i];
    }
    for (int i = mid + 1; i <= high; i++) {
        right[i - mid - 1] = arr[i];
    }
    int i = 0, j = 0, k = low;
    while (i < mid - low + 1 && j < high - mid) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < mid - low + 1) {
        arr[k++] = left[i++];
    }
    while (j < high - mid) {
        arr[k++] = right[j++];
    }
}
```
* **Heap Sort**:
```cpp
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
```
**7 Stack Implementation using Linked List**

* **Node structure**:
```cpp
struct Node {
    int data;
    Node* next;
};
```
* **Stack structure**:
```cpp
class Stack {
    Node* top;
public:
    Stack() : top(nullptr) {}
    void push(int data);
    int pop();
    int topElement();
    bool isEmpty();
};
```
* **Push**:
```cpp
void Stack::push(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}
```
* **Pop**:
```cpp
int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack underflow!" << endl;
        return -1;
    }
    int data = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return data;
}
```
* **Top Element**:
```cpp
int Stack::topElement() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return top->data;
}
```
* **Is Empty**:
```cpp
bool Stack::isEmpty() {
    return top == nullptr;
}
```
**8 Queue Implementation using Linked List**

* **Node structure**:
```cpp
struct Node {
    int data;
    Node* next;
};
```
* **Queue structure**:
```cpp
class Queue {
    Node* front, *rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}
    void enqueue(int data);
    int dequeue();
    int frontElement();
    bool isEmpty();
};
```
* **Enqueue**:
```cpp
void Queue::enqueue(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}
```
* **Dequeue**:
```cpp
int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    int data = front->data;
    Node* temp = front;
    front = front->next;
    delete temp;
    if (front == nullptr) {
        rear = nullptr;
    }
    return data;
}
```
* **Front Element**:
```cpp
int Queue::frontElement() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return front->data;
}
```
* **Is Empty**:
```cpp
bool Queue::isEmpty() {
    return front == nullptr;
}
```
**9 Hashing**

* **Hash Function**:
```cpp
int hashFunction(int key, int tableSize) {
    return key % tableSize;
}
```
* **Hash Table**:
```cpp
class HashTable {
    int* table;
    int tableSize;
public:
    HashTable(int size) : tableSize(size) {
        table = new int[tableSize];
        for (int i = 0; i < tableSize; i++) {
            table[i] = -1; // initialize with -1
        }
    }
    void insert(int key);
    int search(int key);
};
```
* **Insert**:
```cpp
void HashTable::insert(int key) {
    int index = hashFunction(key, tableSize);
    if (table[index] == -1) {
        table[index] = key;
    } else {
        // handle collision
    }
}
```
* **Search**:
```cpp
int HashTable::search(int key) {
    int index = hashFunction(key, tableSize);
    if (table[index] == key) {
        return index;
    } else {
        // handle collision
    }
    return -1; // not found
}
```
