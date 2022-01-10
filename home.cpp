#include "home.h"

int Home::Area() const{
  return this->Width * this->Height;
}

Home::Home(int a, int b){
  this->Width = a;
  this->Height = b;
}
