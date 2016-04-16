
#include <iostream>
#include "udp.hpp"
#include "picojson.h"


int main() {
  std::cout << "start program" << std::endl;

  while(1) {
    Udp udp;
    udp.initAddr(54321, "");
    std::string data = udp.recieve();
    std::cout << data << std::endl;
  }

  std::cout << "end program" << std::endl; 
}
