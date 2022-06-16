#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		return 1;
	}

	// int integer = std::stoi(argv[1]);

	// std::cout << "char  : ";
	// if (std::isprint(integer))
	// 	std::cout << static_cast<char>(integer) << std::endl;
	// else
	// 	std::cout << "impossible" << std::endl;
	// std::cout << "int   : " << integer << std::endl;
	std::cout << "float : " << std::stof(argv[1]) << 'f' << std::endl;
	std::cout << "double: " << std::stod(argv[1]) << std::endl;
}
