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
      "Manas Sethi", "Akash Dani", "Tanvi D’Alia", "Aamani Sarkar", "Krishna Golla",
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

void merge(std::vector<Student> &records, int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  std::vector<Student> leftRecords(records.begin() + left, records.begin() + mid + 1);
  std::vector<Student> rightRecords(records.begin() + mid + 1, records.begin() + right + 1);

  int i = 0, j = 0, k = left;

  while (i < n1 && j < n2)
  {
    if (leftRecords[i].name <= rightRecords[j].name)
    {
      records[k] = leftRecords[i];
      i++;
    }
    else
    {
      records[k] = rightRecords[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    records[k] = leftRecords[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    records[k] = rightRecords[j];
    j++;
    k++;
  }
}

void mergeSort(std::vector<Student> &records, int left, int right)
{
  if (left >= right)
  {
    return;
  }

  int mid = left + (right - left) / 2;

  mergeSort(records, left, mid);
  mergeSort(records, mid + 1, right);

  merge(records, left, mid, right);

  std::cout << "Iteration: ";
  for (const auto &student : records)
  {
    std::cout << student.name << " ";
  }
  std::cout << std::endl;
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

  std::cout << "\nSorting Records..." << std::endl;

  auto start = std::chrono::high_resolution_clock::now();
  mergeSort(records, 0, records.size() - 1);
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