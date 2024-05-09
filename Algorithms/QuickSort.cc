// (c) Suryavir Kapur 2024
// BITS Pilani
#include <iostream>

void swap(int &i, int &j)
{
  int temp = i;
  i = j;
  j = temp;
}

int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++)
  {
    if (arr[j] <= pivot)
    {
      i++;
      swap(arr[i], arr[j]);
    }
    int n = 9;
    for (int i = 0; i < n; i++)
      std::cout << arr[i] << " ";
    std::cout << "\n";
  }

  swap(arr[i + 1], arr[high]);
  return i + 1;
}

void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
  }
}
int main()
{
  int arr[] = {8, 4, 5, 7, 4, 9, 3, 34, 10};
  int n = sizeof(arr) / sizeof(int);

  for (int i = 0; i < n; i++)
    std::cout << arr[i] << " ";
  std::cout << "\n";

  quickSort(arr, 0, n - 1);

  for (int i = 0; i < n; i++)
    std::cout << arr[i] << " ";
  std::cout << "\n";
}