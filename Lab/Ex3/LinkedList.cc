#include <iostream>
#include <string>

class Student
{
public:
  std::string name;
  std::string id;
  float cgpa;
  Student *next;
};

class StudentList
{
private:
  Student *head;
  int count;

public:
  StudentList()
  {
    head = nullptr;
    count = 0;
  }

  void insert(int position, std::string name, std::string id, float cgpa)
  {
    Student *newStudent = new Student();
    newStudent->id = id;
    newStudent->cgpa = cgpa;
    newStudent->name = name;

    if (position == 1)
    {
      newStudent->next = head;
      ` head = newStudent;
    }
    else
    {
      Student *prev = head;
      for (int i = 1; i < position - 1 && prev != nullptr; i++)
      {
        prev = prev->next;
      }
      if (prev != nullptr)
      {
        newStudent->next = prev->next;
        prev->next = newStudent;
      }
    }
    count++;
  }

  int find(std::string name)
  {
    Student *current = head;
    int position = 1;
    while (current != nullptr)
    {
      if (current->name == name)
      {
        return position;
      }
      current = current->next;
      position++;
    }
    return -1;
  }

  int remove(std::string name)
  {
    if (head == nullptr)
    {
      return -1;
    }
    if (head->name == name)
    {
      Student *temp = head;
      head = head->next;
      delete temp;
      count--;
      return 1;
    }
    Student *prev = head;
    Student *current = head->next;
    int position = 2;
    while (current != nullptr)
    {
      if (current->name == name)
      {
        prev->next = current->next;
        delete current;
        count--;
        return position;
      }
      prev = current;
      current = current->next;
      position++;
    }
    return -1;
  }

  Student *get(int position)
  {
    if (position < 1 || position > count)
    {
      return nullptr;
    }
    Student *current = head;
    for (int i = 1; i < position; i++)
    {
      current = current->next;
    }
    return current;
  }

  void display()
  {
    Student *current = head;
    while (current != nullptr)
    {
      std::cout << "Name: " << current->name << ", ID: " << current->id << ", CGPA: " << current->cgpa << std::endl;
      current = current->next;
    }
  }

  int size()
  {
    return count;
  }

  bool isEmpty()
  {
    return count == 0;
  }
};

int main()
{
  StudentList studentList;
  int choice;
  std::string name;
  std::string id;
  float cgpa;
  int position;

  do
  {
    std::cout << "\nList Operations:" << std::endl;
    std::cout << "1. Add a student record to the list" << std::endl;
    std::cout << "2. Find a student record by name" << std::endl;
    std::cout << "3. Delete a student record from the list" << std::endl;
    std::cout << "4. Display the list" << std::endl;
    std::cout << "5. isEmpty" << std::endl;
    std::cout << "6. Size" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
      std::cout << "Enter the position to insert: ";
      std::cin >> position;
      std::cout << "Enter the student name: ";
      std::cin.ignore();
      getline(std::cin, name);
      std::cout << "Enter the student ID: ";
      std::cin >> id;
      std::cout << "Enter the student CGPA: ";
      std::cin >> cgpa;
      studentList.insert(position, name, id, cgpa);
      std::cout << "Student record added successfully." << std::endl;
      break;
    case 2:
      std::cout << "Enter the student name to find: ";
      std::cin.ignore();
      getline(std::cin, name);
      position = studentList.find(name);
      if (position != -1)
      {
        std::cout << "Student found at position: " << position << std::endl;
      }
      else
      {
        std::cout << "Student not found." << std::endl;
      }
      break;
    case 3:
      std::cout << "Enter the student name to delete: ";
      std::cin.ignore();
      getline(std::cin, name);
      position = studentList.remove(name);
      if (position != -1)
      {
        std::cout << "Student record deleted successfully." << std::endl;
      }
      else
      {
        std::cout << "Student not found. Deletion failed." << std::endl;
      }
      break;
    case 4:
      std::cout << "Student List:" << std::endl;
      studentList.display();
      break;
    case 5:
      std::cout << "Is the list empty? " << (studentList.isEmpty() ? "Yes" : "No") << std::endl;
      break;
    case 6:
      std::cout << "Total students: " << studentList.size() << std::endl;
      break;
    case 7:
      std::cout << "Exiting the program." << std::endl;
      break;
    default:
      std::cout << "Invalid choice. Please try again." << std::endl;
    }
  } while (choice != 7);

  return 0;
}