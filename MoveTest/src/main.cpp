
#include <iostream>
#include "socket.hpp"


int main() {
  std::cout << "start program" << std::endl;

  Socket server;
  Socket client;

  server.create();
  server.bind(12345);
  server.listen();
  server.accept(client);

  std::string str = "move 0, jump 1";
  
  client << str;

  std::cout << "end program" << std::endl; 
}
