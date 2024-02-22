#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#define MAX_SIZE 5
// Define a struct to represent a node in the stack
struct Stack
{
  std::string data[MAX_SIZE];
  int top;
};

void initialize(Stack *stack)
{
  stack->top = -1;
}

bool isFull(Stack *stack)
{
  return stack->top == MAX_SIZE - 1;
}

bool isEmpty(Stack *stack)
{
  return stack->top == -1;
}

void push(Stack *stack, std::string data)
{
  if (isFull(stack))
  {
    std::runtime_error("Overflow");
  }
  else
  {
    stack->top++;
    stack->data[stack->top] = data;
    std::cout << "Pushed: " << data << std::endl;
  }
}

std::string pop(Stack *stack)
{
  if (isEmpty(stack))
  {
    std::runtime_error("Underflow");
    return "Underflow";
  }
  else
  {
    std::string data = stack->data[stack->top];
    stack->top--;
    std::cout << "Popped: " << data << std::endl;
    return data;
  }
}

std::string top(Stack *stack)
{
  if (isEmpty(stack))
  {
    std::runtime_error("Overflow");
    return "Overflow";
  }
  else
  {
    return stack->data[stack->top];
  }
}

// int main()
// {
//   Stack stack;
//   initialize(&stack);

//   push(&stack, "Something");
//   std::cout << top(&stack) << std::endl;
//   return 0;
// }

int main()
{
  // File Handles
  std::ifstream inFile("student.in");

  // Initialize a Stack
  Stack stack;
  initialize(&stack);

  // Push on Stack
  std::string line;
  while (std::getline(inFile, line))
  {
    push(&stack, line);
  }

  // Print Top Element
  std::cout << "Top element: " << top(&stack) << std::endl;
  // Pop an Element
  pop(&stack);
  // isEmpty()
  std::cout << "Is the stack empty? " << (isEmpty(&stack) ? "Yes" : "No") << std::endl; // Output: Is the stack empty? No

  // Out File Handle
  std::ofstream outFile("student.out");

  // Print all to File
  while (!isEmpty(&stack))
  {
    outFile << top(&stack) << std::endl;
    pop(&stack);
  }
}