#include <iostream>
#include <fstream>
#include <string>

int main()
{
  std::ifstream file("Content.dat");
  if (!file)
  {
    std::cout << "Error: Cannot open the file" << std::endl;
    return 1;
  }

  std::string line;
  while (std::getline(file, line))
  {
    std::cout << line << std::endl;
  }

  file.close();
}