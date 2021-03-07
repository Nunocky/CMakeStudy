#include <X/libX.h>

std::string 
X::greeting(void) {

  // 意図的に memory leakを仕込んでみる
  //  char *str = new char[8]; // buffer overrunは '-fsanitize=address'で検出される

  char *str = new char[256]; // こちらだとエラーが起きない (アドレスの汚染がないので?)

  sprintf(str, "Hello World");
  std::string retVal(str);

  //delete[] str;
  //delete[] str; // double freeは検出可能

  return str;
}
