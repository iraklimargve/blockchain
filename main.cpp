#include <stdio.h>
#include <iostream>

#include "home.h"
#include "config.h"

int main(){
  Config::GetInstance().InitLogger();

  Home* ab = new Home(2,3);
  printf("%d\n", ab->Area());
  BOOST_LOG_TRIVIAL(info) << "this is an informational severity message12312321";
  std::cin.get();
  // printf("%lld\n%lld\n", (long long int)&a, (long long int)b);
  return 0;

}
