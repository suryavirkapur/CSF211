#include <iostream>
#include <string>
#include <vector>
#include <fstream>

template <typename T>
class Stack
{
public:
  // Add an element to the top of the stack
  void push(const T &value)
  {
    data.push_back(value);
  }

  // Remove and return the top element from the stack
  T pop()
  {
    if (isEmpty())
    {
      throw std::runtime_error("Cannot pop from an empty stack");
    }
    T value = data.back();
    data.pop_back();
    return value;
  }

  // Return a reference to the top element of the stack
  const T &top() const
  {
    if (isEmpty())
    {
      throw std::runtime_error("Cannot get the top of an empty stack");
    }
    return data.back();
  }

  // Check if the stack is empty
  bool isEmpty() const
  {
    return data.empty();
  }

private:
  std::vector<T> data;
};

int main()
{
  // File Handles
  std::ifstream inFile("student.in");

  // Initialize a Stack
  Stack<std::string> stack;

  // Push on Stack

  std::string line;
  while (std::getline(inFile, line))
  {
    stack.push(line);
  }

  // Print Top Element
  std::cout << "Top element: " << stack.top() << std::endl;
  // Pop an Element
  stack.pop();
  // isEmpty()
  std::cout << "Is the stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl; // Output: Is the stack empty? No

  // Out File Handle
  std::ofstream outFile("student.out");

  // Print all to File
  while (!stack.isEmpty())
  {
    std::cout << stack.top() << std::endl;
    outFile << stack.top() << std::endl;
    stack.pop();
  }
}