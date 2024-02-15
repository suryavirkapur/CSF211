#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>

int linear_search(std::vector<int> v, int a)
{
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] == a)
      return i;
  }
  return -1;
}

int binary_search(std::vector<int> v, int a)
{
  std::sort(v.begin(), v.end());
  int maximum = (v.size()) - 1;
  int minimum = 0;
  int mean;

  while (maximum > minimum)
  {
    mean = (maximum + minimum) / 2;
    if (v[mean] == a)
    {
      return mean;
    }
    else if (v[mean] > a)
    {
      maximum = (mean - 1);
    }
    else
    {
      minimum = (mean + 1);
    }
  }
  return -1;
}

int main()
{

  // Read the File
  std::ifstream testSizeFile;
  int testSize;
  testSizeFile.open("testCaseSize.txt");

  int num;
  std::cin >> num;

  if (testSizeFile.is_open())
  {
    for (int i = 1; i <= num; i++)
    {
      testSizeFile >> testSize;
    }
  }
  std::cout << "Test Size: " << testSize << std::endl;
  // Parse the File
  int arr;

  // Assuming the file is named "numbers.txt"
  std::ifstream file("searchTestCase.txt");

  std::vector<int> numbers; // Vector to store the numbers
  int number;

  // Read numbers from the file until end-of-file
  while (file >> number)
  {
    numbers.push_back(number);
  }

  file.close(); // Close the file

  // Compute
  // for (int i = 0; i < numbers.size() + 1; i++)
  // {
  //   std::cout << numbers[i] << " ";
  // }
  int ele;
  std::cin >> ele;

  // Time Setup
  clock_t tStart = clock();

  int j = linear_search(numbers, ele);
  std::cout << std::endl
            << "LS Pos: " << j << std::endl;
  double t1 = (double)(clock() - tStart) / CLOCKS_PER_SEC;

  int k = binary_search(numbers, ele);
  std::cout << std::endl
            << "BS Pos: " << k << std::endl;
  double t2 = (double)(clock() - tStart) / CLOCKS_PER_SEC;

  std::ofstream linearFile("linearSearchResult.txt");
  linearFile << "Input Pos Time (s)" << std::endl;
  linearFile << ele << " " << j << " " << t1 << std::endl;

  std::ofstream binaryFile("binarySearchResult.txt");
  binaryFile << "Input Pos Time (s)" << std::endl;
  binaryFile << ele << " " << j << " " << t1 << std::endl;
}
