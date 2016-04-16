
#include <iostream>
#include "socket.hpp"
#include "picojson.h"


int main() {
  std::cout << "start program" << std::endl;

  Socket server;
  Socket client;

  server.create();
  server.bind(54321);
  server.listen();

  while(1) {
    server.accept(client);

    std::string data;
  
    client >> data;

    picojson::value val;
    picojson::parse(val, data);
    picojson::object obj = val.get<picojson::object>();

    client << data;
  }

  std::cout << "end program" << std::endl; 
}
