#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
  if (argc != 2) {
    return 1;
  }

  // int integer;
  // try {
  //   integer = std::stoi(argv[1]);
  // } catch (std::out_of_range& e) {
  //   std::cout << e.what() << std::endl;
  //   return 0;
  // }

  // std::cout << "char  : ";
  // if (std::isprint(integer))
  //   std::cout << "'" << static_cast<char>(integer) << "'" << std::endl;
  // else
  //   std::cout << "impossible" << std::endl;
  // std::cout << "int   : " << integer << std::endl;
  std::cout << "float : " << std::fixed << std::setprecision(4) << std::stof(argv[1]) << 'f'
            << std::endl;
  std::cout << "double: " << std::setprecision(4) << std::stod(argv[1]) << std::endl;
}
