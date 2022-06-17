#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

namespace {
Base* Generate(void) {
  switch (rand() % 3) {
    case 0:
      return new A();
      break;
    case 1:
      return new B();
      break;
    case 2:
      return new C();
      break;
  }
  return NULL;
}
void Identify(Base* p) {
  std::cout << "Pointer:   ";
  if (dynamic_cast<A*>(p))
    std::cout << "It is A" << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << "It is B" << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << "It is C" << std::endl;
}
void Identify(Base& p) {
  std::cout << "Reference: ";
  if (typeid(p) == typeid(A))
    std::cout << "It is A" << std::endl;
  else if (typeid(p) == typeid(B))
    std::cout << "It is B" << std::endl;
  else if (typeid(p) == typeid(C))
    std::cout << "It is C" << std::endl;
}

void leakcheck() {
  system("leaks cpp06_ex02.out | grep Process");
}
}  // namespace

int main() {
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    Base* bp = Generate();
    (void)bp;
    Identify(bp);
    Identify(*bp);
    delete bp;
    std::cout << '\n';
  }
  leakcheck();
  return 0;
}
