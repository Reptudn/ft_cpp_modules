#include <cctype>
#include <iostream>
#include <ostream>
#include <string>

std::string strtrim(char *str, char c)
{
	unsigned long start_point = 0;

	char	*start	= str;
	while (std::isspace(*start))
	{
		start_point++;
		start++;
	}

	unsigned long end = 0;
	for (int i = 0; str[i]; i++)
	{
		end++;
		str++;
	}

	while (std::isspace(*str))
	{
		str--;
		end--;
	}

	std::string new_str = std::to_string(str);
	return (new_str.substr(start_point, end))
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
			std::cout << (char)toupper(argv[i][j]);
		std::cout << " ";
	}
	std::cout << std::endl;
	return 0;
}