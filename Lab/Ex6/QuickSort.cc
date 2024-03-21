#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

struct Student
{
  std::string name;
  int id;
  int enrollmentYear;
  double cgpa;
};

std::vector<Student> generateRandomRecords(int numRecords)
{
  std::vector<Student> records;
  std::srand(std::time(nullptr));

  std::string names[] = {
      "Manas Sethi", "Akash Dani", "Tanvi D'Alia", "Aamani Sarkar", "Krishna Golla",
      "Sai Doshi", "Dinesh Radhakrishnan", "Neel Munshi", "Harish Konda", "Durga Keer"};

  int numNames = sizeof(names) / sizeof(names[0]);

  for (int i = 0; i < numRecords; i++)
  {
    Student student;
    student.name = names[std::rand() % numNames];
    student.id = std::rand() % 1000 + 1;
    student.enrollmentYear = std::rand() % 5 + 2018;
    student.cgpa = static_cast<double>(std::rand() % 500 + 100) / 100.0 + 4.0;
    records.push_back(student);
  }

  return records;
}

int partition(std::vector<Student> &records, int low, int high)
{
  std::string pivot = records[high].name;
  int i = low - 1;

  for (int j = low; j < high; j++)
  {
    if (records[j].name <= pivot)
    {
      i++;
      std::swap(records[i], records[j]);
    }
  }

  std::swap(records[i + 1], records[high]);

  return i + 1;
}

void quickSort(std::vector<Student> &records, int low, int high)
{
  if (low < high)
  {
    int pivotIndex = partition(records, low, high);

    quickSort(records, low, pivotIndex - 1);
    quickSort(records, pivotIndex + 1, high);

    std::cout << "Iteration: ";
    for (const auto &student : records)
    {
      std::cout << student.name << " ";
    }
    std::cout << std::endl;
  }
}

int main()
{
  std::vector<Student> records = generateRandomRecords(10);

  std::cout << "Original Records:" << std::endl;
  for (const auto &student : records)
  {
    std::cout << "Name: " << student.name << ", ID: " << student.id
              << ", Enrollment Year: " << student.enrollmentYear
              << ", CGPA: " << student.cgpa << std::endl;
  }

  std::cout << "\nSorting Records:" << std::endl;

  auto start = std::chrono::high_resolution_clock::now();
  quickSort(records, 0, records.size() - 1);
  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double, std::milli> duration = end - start;

  std::cout << "\nSorted Records:" << std::endl;
  for (const auto &student : records)
  {
    std::cout << "Name: " << student.name
              << ", ID: " << student.id
              << ", Enrollment Year: " << student.enrollmentYear
              << ", CGPA: " << student.cgpa
              << std::endl;
  }

  std::cout << "\nTime taken for sorting: " << duration.count() << " milliseconds" << std::endl;

  return 0;
}