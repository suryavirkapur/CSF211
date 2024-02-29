#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#define SIZE 5

struct Student
{
  std::string ID;
  std::string name;
  std::string DOB;
  std::string CGPA;
};

class Queue
{
private:
  Student s[SIZE];
  int front, rear;

public:
  Queue()
  {
    front = -1;
    rear = -1;
  }
  // Check if the queue is full
  bool isFull()
  {
    if (front == 0 && rear == SIZE - 1)
    {
      return true;
    }
    if (front == rear + 1)
    {
      return true;
    }
    return false;
  }
  // Check if the queue is empty
  bool isEmpty()
  {
    if (front == -1)
      return true;
    else
      return false;
  }
  // Adding an element
  void enQueue(Student element)
  {
    if (isFull())
    {
      std::cout << "Queue is full";
    }
    else
    {
      if (front == -1)
        front = 0;
      rear = (rear + 1) % SIZE;
      s[rear] = element;
      std::cout
          << "Inserted " << element.name << std::endl;
      std::cout << "Front" << front << " Rear" << rear << std::endl;
    }
  }
  // Removing an element
  Student deQueue()
  {
    Student element;
    if (isEmpty())
    {
      std::cout << "Queue is empty" << std::endl;
      return element;
    }
    else
    {
      element = s[front];
      if (front == rear)
      {
        front = -1;
        rear = -1;
      }
      // Q has only one element,
      // so we reset the queue after deleting it.
      else
      {
        front = (front + 1) % SIZE;
      }
      return (element);
    }
  }

  void display()
  {
    // Function to display status of Circular Queue
    int i;
    if (isEmpty())
    {
      std::cout << std::endl
                << "Empty Queue" << std::endl;
    }
    else
    {
      std::cout << "Front -> " << front << std::endl;
      std::cout
          << "Items -> ";
      for (i = front; i != rear; i = (i + 1) % SIZE)
      {
        std::cout << s[i].name << " ";
      }
      std::cout
          << s[i].name << std::endl;
      std::cout
          << "Rear -> " << rear << std::endl;
    }
  }
};

int main()
{
  Queue q;

  // Fails because front = -1
  q.deQueue();

  // File Handle
  std::ifstream inFile("student.in");
  std::string line;
  while (std::getline(inFile, line))
  {
    std::stringstream str_stream(line);

    Student S;

    str_stream >> S.ID;
    str_stream >> S.name;
    str_stream >> S.DOB;
    str_stream >> S.CGPA;

    q.enQueue(S);
  }

  q.display();

  std::ofstream outFile("student.out");

  // Print all to File
  while (!q.isEmpty())
  {
    Student s = q.deQueue();
    outFile
        << s.ID << " " << s.name << " " << s.DOB << " " << s.CGPA << std::endl;
    std::cout
        << s.ID << " " << s.name << " " << s.DOB << " " << s.CGPA << std::endl;
  }
  return 0;
}