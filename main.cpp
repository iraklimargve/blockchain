#include <stdio.h>
#include <iostream>
#include <ctime>
#include <string>
#include <pqxx/pqxx>

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
  BOOST_LOG_TRIVIAL(info) <<awa;
  BOOST_LOG_TRIVIAL(info) << "22222222";
  printf("%s\n","FINISH");
  printf("%s\n","Try connecting database");

  try {
      pqxx::connection C("dbname = postgres user = postgres password = password hostaddr = 127.0.0.1 port = 5432");
      printf("%s\n","checkeeeeeeeeeeers");
      if (C.is_open()) {
         printf("%s\n","opened successfully");
      } else {
         printf("%s\n","cant open");
         return 1;
      }
      pqxx::work W(C);

      // how to check if database exist??????????? chenidedaia
      // if exist dont run this command if not run to create boishy
      // W.exec("create table chenidedaiaaa(ID int primary key, name varchar(50), salary real);");
      W.exec("insert into chenidedaiaaa(name, salary) values (1, 'chndedaiaboishy', 100000);");
      W.commit();
      C.disconnect();
   } catch (const std::exception &e) {
      printf("%s\n",e.what());
      return 1;
   }

  return 0;

}
