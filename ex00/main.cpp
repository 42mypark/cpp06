#include <climits>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "Parser.hpp"

namespace ft {
int stoi(const std::string& str) {
  std::stringstream ss(str);
  Parser            p(ss, kInt);
  return p.getInteger();
}

float stof(const std::string& str) {
  std::stringstream ss(str);
  Parser            p(ss, kFloat);
  return static_cast<float>(p.getInteger()) + static_cast<float>(p.getDouble());
}

double stod(const std::string& str) {
  std::stringstream ss(str);
  Parser            p(ss, kDouble);
  return static_cast<double>(p.getInteger()) + static_cast<double>(p.getDouble());
}

}  // namespace ft

int main(int argc, char const* argv[]) {
  if (argc != 2) {
    std::cout << "Please Check Arguments" << std::endl;
    return 1;
  }

  int    i;
  float  f;
  double d;
  try {
    i = ft::stoi(argv[1]);
    f = ft::stof(argv[1]);
    d = ft::stod(argv[1]);
    if (std::isprint(i))
      std::cout << "char: '" << static_cast<char>(i) << "'\n";
    else
      std::cout << "char: "
                << "Non displayable" << '\n';
    std::cout << "int: " << i << '\n';
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << 'f' << '\n';
    std::cout << "double: " << d << '\n';
  } catch (const std::exception& e) {
    std::cout << "char: impossible" << '\n';
    std::cout << "int: impossible" << '\n';
    std::cout << "float: nanf" << '\n';
    std::cout << "double: nan" << '\n';
  }
  return 0;
}
