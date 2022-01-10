#include <stdio.h>
#include "home.h"

int main(){

  Home* ab = new Home(2,3);
  printf("%d\n", ab->Area());
  printf("%d\n", ab->Area());

  // printf("%lld\n%lld\n", (long long int)&a, (long long int)b);
  return 0;


}
