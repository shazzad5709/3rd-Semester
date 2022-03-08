#include<iostream>
using namespace std;
int main() {
  string str = "";
  char ch;
  while ((ch = std::cin.get()) != 27) {
    str += ch;
  }

 cout << str;

return 0;
}