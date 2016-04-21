
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

    server.accept(client);

    std::string data("hogehogepiyokoge");

    client << data;

  std::cout << "end program" << std::endl; 
}
