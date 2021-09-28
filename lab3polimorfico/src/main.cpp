#include "Compresor1.hpp"
#include "Compresor2.hpp"

using namespace std;
#include <sstream>

int main() {
  Compresor1 compresor;

  stringstream ss1;

  compresor.comprimir(ss1);
  cout << ss1.str();

  return 0;
}