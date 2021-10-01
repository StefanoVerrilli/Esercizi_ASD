#include <string>
#include "Resolver.cpp"
using namespace std;

int main(){
  string Problem("Problema.txt");
  string Solution("Soluzione.txt");
  resolver resolve(Problem,Solution);
  resolve.IsCorrect();
  return 0;
}