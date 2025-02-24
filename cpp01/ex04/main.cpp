#include <iostream>
#include <fstream>
#include <string>

void	replaceInFile(std::string str1, std::string str2, std::ofstream &outputFile, std::ifstream &inputFile)
{
	if(inputFile.is_open() && outputFile.is_open())
	{
		std::string temp;
		std::size_t found;
		while(getline(inputFile, temp))
		{
			found = temp.find(str1);
			while(found != std::string::npos)
			{
				temp.erase(found, str1.length());
				temp.insert(found, str2);
				found = temp.find(str1, found + str2.length());
			}
			outputFile << temp << std::endl;
		}
		inputFile.close();
		outputFile.close();
	}
}

int main(int argc, char **argv)
{
	if(argc != 4){
		std::cerr << "ERR: Wrong input.\n" << "Usage: " << argv[0] << " <filename> <string1> <string2>\n";
		return 1;
	}

	std::string filename = argv[1];
	std::string str1 = argv[2];
	std::string str2 = argv[3];

	std::ifstream inputFile(filename.c_str());
	if(!inputFile){
		std::cerr << "ERR:" << filename << " does not exist." << std::endl;
		return 1;
	}
	std::ofstream outputFile((filename + ".replace").c_str());
	if(!outputFile){
		std::cerr << "ERR: could not create new file." << std::endl;
		return 1;
	}
	replaceInFile(str1, str2, outputFile, inputFile);
	return 0;
}