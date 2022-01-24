#include <stdio.h>
#include <iostream>
#include <ctime>
#include <string>
#include <thread>
#include <chrono>
#include <pqxx/pqxx>

#include "home.h"
#include "config.h"

struct cndedaia{
  int id;
  std::string name;
  double salary;
};

void printcndedaia(cndedaia obj){
  // printf("id: %d, name: %s, salary: %f\n", obj.id, obj.name, obj.salary);
  std::cout << "id: " << obj.id << ", name: " << obj.name << ", salary: " << obj.salary << std::endl;
};


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
      cndedaia obj;
      obj.name = "asdf";
      obj.id = 5;
      obj.salary = 12.23;
      printcndedaia(obj);
      pqxx::connection C("dbname = postgres user = postgres password = password hostaddr = 127.0.0.1 port = 5432");
      printf("%s\n","checkeeeeeeeeeeers");
      if (C.is_open()) {
         printf("%s\n","opened successfully");
      } else {
         printf("%s\n","cant open");
         return 1;
      }
      pqxx::work W(C);
      for (size_t i = 6; i < 10; i++) {
        std::string q;
        q = "insert into chenidedaiaaa(id, name, salary) values ";
        q = q + "(" + std::to_string(i) + ", 'name" + std::to_string(i) + "', " + std::to_string(i * 10.0) + " )";
        std::cout << q << std::endl;
        W.exec(q);
        W.commit();
        std::this_thread::sleep_for(std::chrono::seconds(1));
      }

      pqxx::result res = W.exec("select id, name, salary from chenidedaiaaa");
      W.commit();
      for (pqxx::row r : res) {
        obj.id = r[0].as<int>();
        obj.name = r[1].as<std::string>();
        obj.salary = r[2].as<double>();
        printcndedaia(obj);
      }
      C.disconnect();
   } catch (const std::exception &e) {
      printf("%s\n",e.what());
      return 1;
   }

  return 0;

}
