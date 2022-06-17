#include <iostream>

#include "Data.hpp"

namespace {
uintptr_t Serialize(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}
Data* Deserialize(uintptr_t raw) {
  return reinterpret_cast<Data*>(raw);
}
}  // namespace

int main() {
  Data          d;
  unsigned long serialized = Serialize(&d);
  Data*         deserialized = Deserialize(serialized);
  std::cout << &d << '\n';
  std::cout << std::hex << serialized << '\n';
  std::cout << deserialized << std::endl;
  return 0;
}
