#include<iostream>
#include<fstream>

int main() {
	std::ofstream file;
	
	file.open("Content.dat");
	file << "Test File" << std::endl;

	file.close();
}
