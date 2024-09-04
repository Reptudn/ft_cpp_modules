#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << &argv[0] << " <file> <str> <replace>" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string str = argv[2];
	std::string replace = argv[3];

	std::fstream file;
	file.open(filename, std::fstream::in);
	if (!file)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return 2;
	}

	std::fstream replacefile;
	replacefile.open((filename + ".replace").c_str(), std::fstream::out);
	if (!replacefile)
	{
		std::cerr << "Error: could not create replace file" << std::endl;
		file.close();
		return 3;
	}

	std::string line;
	int	count = 0;
	while (std::getline(file, line))
	{
		for (int i = 0; line[i]; i++)
		{
			std::string curr = line.substr(i, str.length());
			if (curr == str)
			{
				replacefile << replace;
				i += str.length() - 1;
				count++;
			}
			else
				replacefile << line[i];
		}
		replacefile << "\n";
	}
	file.close();
	if (count > 0)
		std::cout << "Successfuly replaced " << count << " occurences of the word '" + str + "' with '" + replace + "'" << std::endl;
	else
		std::cout << "No occurences found of '" + str + "'. Replaced nothing" << std::endl;
	return 0;
}