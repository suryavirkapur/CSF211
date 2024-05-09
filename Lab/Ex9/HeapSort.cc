#include <iostream>
#include <vector>
#include <string>

using namespace std;

void heapify(vector<string> &arr, int n, int i)
{
  int smallest = i;  // smallest as root
  int l = 2 * i + 1; // left = 2*i + 1
  int r = 2 * i + 2; // right = 2*i + 2

  // If left child is smaller 
  if (l < n && arr[l] < arr[smallest])
    smallest = l;

  // If right child is smaller 
  if (r < n && arr[r] < arr[smallest])
    smallest = r;

  // If smallest is not root
  if (smallest != i)
  {
    swap(arr[i], arr[smallest]);
    // Recursively heapify the affected subtree
    heapify(arr, n, smallest);
  }
}

void heapSort(vector<string> &arr)
{
  int n = arr.size();
  // Build heap rearrange heap
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  // One by one extract an element from heap
  for (int i = n - 1; i >= 0; i--)
  {
    // Move current root to end
    swap(arr[0], arr[i]);

    // call max heapify on the reduced heap
    heapify(arr, i, 0);

    // Print current state of the array
    cout << "Current state of array: ";
    for (int j = 0; j < arr.size(); j++)
    {
      cout << arr[j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  vector<std::string> arr;
  arr.push_back("Manas");
  arr.push_back("Krishna");
  arr.push_back("Sai");
  arr.push_back("Dinesh");
  arr.push_back("Neel");
  arr.push_back("Harish");
  arr.push_back("Keer");

  cout << "Initial array: ";
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  heapSort(arr);

  cout << "Sorted array: ";
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}