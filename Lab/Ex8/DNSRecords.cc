#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

struct DNSRecord
{
  string hostname;
  string ip_address;
};

class HashTable
{
private:
  static const int HASH_SIZE = 17; // Size of the hash table
  vector<list<DNSRecord>> table;   // Hash table

  int hashFunction(const string &hostname)
  {
    // For each char
    // hash = (hash * a + c) % HASH_SIZE.
    int a = 33; 
    long long hash = 0;
    for (int i = 0; i < hostname.length(); i++)
    {
      hash = (hash * a + hostname[i]) % HASH_SIZE;
    }
    return hash % HASH_SIZE;
  }

public:
  HashTable()
  {
    table.resize(HASH_SIZE);
  }

  void insert(const string &hostname, const string &ip_address)
  {
    int index = hashFunction(hostname);
    DNSRecord record = {hostname, ip_address};
    table[index].push_back(record);
    cout << "DNS record inserted successfully into the Hash table" << endl;
  }

  void find(const string &hostname)
  {
    int index = hashFunction(hostname);
    list<DNSRecord>::iterator it;
    for (it = table[index].begin(); it != table[index].end(); ++it)
    {
      if (it->hostname == hostname)
      {
        cout << "The hostname " << hostname << " is present in the hash table" << endl;
        cout << "The IP address is " << it->ip_address << endl;
        return;
      }
    }
    cout << "No such element found" << endl;
  }

  void display()
  {
    cout << "The entire contents of the hash table:" << endl;
    for (int i = 0; i < HASH_SIZE; i++)
    {
      list<DNSRecord>::iterator it;
      for (it = table[i].begin(); it != table[i].end(); ++it)
      {
        cout << it->hostname << " " << it->ip_address << endl;
      }
    }
  }
};

int main()
{
  HashTable dnsHashTable;
  int choice;
  string hostname, ip_address;

  while (true)
  {
    cout << "\n1) Insert hostname with IP" << endl;
    cout << "2) Search hostname" << endl;
    cout << "3) Display" << endl;
    cout << "4) Exit" << endl;
    cout << "Enter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Please enter the hostname: ";
      cin >> hostname;
      cout << "Please Enter IP: ";
      cin >> ip_address;
      dnsHashTable.insert(hostname, ip_address);
      break;
    case 2:
      cout << "Please enter the hostname to be searched: ";
      cin >> hostname;
      dnsHashTable.find(hostname);
      break;
    case 3:
      dnsHashTable.display();
      break;
    case 4:
      return 0;
    default:
      cout << "Invalid choice." << endl;
    }
  }

  return 0;
}