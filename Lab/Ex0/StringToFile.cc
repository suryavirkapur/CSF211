#include <iostream>
#include <fstream>

int main()
{
	std::ofstream file;
	std::string line;

	std::getline(std::cin, line);

	file.open("./Output/Content.dat");
	file << line << std::endl;

	file.close();
}
π