#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>

int main()
{

  // Read the File
  std::ifstream testSizeFile;
  int testSize;
  testSizeFile.open("testCaseSize.txt");

  int num;
  std::cin >> num;
  std::vector<int> nums;

  while (testSizeFile >> testSize)
  {
    nums.push_back(testSize);
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
  int size = numbers.size();
  std::cout << size << std::endl;
  file.close(); // Close the file

  // Compute
  // for (int i = 0; i < numbers.size() + 1; i++)
  // {
  //   std::cout << numbers[i] << " ";
  // }
  int ele;
  std::cin >> ele;

  clock_t tStart = clock();
  int rL = linear_search(numbers, ele);
  double tEnd = (double)(clock() - tStart) / CLOCKS_PER_SEC;

  tStart = clock();
  int rB = binary_search(numbers, ele);
  tEnd = (double)(clock() - tStart) / CLOCKS_PER_SEC;

  std::cout << "L/B Input Pos Time (s)" << std::endl;
  std::cout << "L   " << ele << " " << rL << " " << tEnd << std::endl;
  std::cout << "B   " << ele << " " << rB << " " << tEnd << std::endl;

  // Time Setup
  std::ofstream linearFile("linearSearchResult.txt");
  linearFile << "Input Pos Time (s)" << std::endl;
  for (int i; i < nums.size(); i++)
  {
    clock_t tStart = clock();
    int j = linear_search(numbers, nums[i]);
    double tEnd = (double)(clock() - tStart) / CLOCKS_PER_SEC;
    linearFile << nums[i] << " " << j << " " << tEnd << std::endl;
  }

  std::ofstream binaryFile("binarySearchResult.txt");
  binaryFile << "Input Pos Time (s)" << std::endl;
  for (int i; i < nums.size(); i++)
  {
    clock_t tStart = clock();
    int j = binary_search(numbers, nums[i]);
    double tEnd = (double)(clock() - tStart) / CLOCKS_PER_SEC;
    binaryFile << nums[i] << " " << j << " " << tEnd << std::endl;
  }
}
