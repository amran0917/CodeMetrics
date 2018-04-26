#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    std::string input = "abc,def,   ghi";
    std::istringstream ss(input);
    std::string token;
    size_t pos=-1;
    while(ss>>token) {
      while ((pos=token.rfind(',')) != std::string::npos) {
        token.erase(pos, 1);
      }
      std::cout << token << '\n';
    }
}
