#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

#include <X/libX.h>

int main(int argc, char* argv[])
{
  std::string message = X::greeting();

  printf("%s\n", message.c_str());
  return 0;
}
