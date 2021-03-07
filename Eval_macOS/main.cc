#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

#include <X/libX.h>
#include <Y/libY.h>

int main(int argc, char* argv[])
{
  printf("%s\n", X::greeting().c_str());
  printf("%s\n", Y::greeting().c_str());
  return 0;
}
