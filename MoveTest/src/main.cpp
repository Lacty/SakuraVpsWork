
#include <iostream>
#include "socket.hpp"
#include "picojson.h"


int main() {
  std::cout << "start program" << std::endl;

  Socket server;
  Socket client;

  server.create();
  server.bind(12345);
  server.listen();

  while(1) {
    //server.listen();
    server.accept(client);

    std::string data;
  
    client >> data;

    picojson::value val;
    picojson::parse(val, data);
    picojson::object obj = val.get<picojson::object>();

    std::cout << obj["posx"].get<double>() << std::endl;
    std::cout << obj["posy"].get<double>() << std::endl;
  }

  std::cout << "end program" << std::endl; 
}
