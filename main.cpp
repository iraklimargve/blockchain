#include <stdio.h>
#include <iostream>
#include <ctime>
#include <string>

#include "home.h"
#include "config.h"

int main(){
  Config::GetInstance().InitLogger();

  // Home* ab = new Home(2,3);
  std::time_t epochTime = std::time(0);
  char* curTime = ctime(&epochTime);
  std::string timestr(curTime);
  std::string mm("AAAAA BBBBBB");
  std::string awa(mm + timestr);
  // BOOST_LOG_TRIVIAL(info) <<"AAAAA" + " " + timestr;
  BOOST_LOG_TRIVIAL(info) <<awa;
  // BOOST_LOG_TRIVIAL(info) << timestr + " " + "AAAAAAAA";
  BOOST_LOG_TRIVIAL(info) << "22222222";

  // std::cin.get();
  printf("%s\n","FINISH");

  return 0;

}
