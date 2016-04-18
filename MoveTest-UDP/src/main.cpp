
#include <iostream>
#include <map>
#include <pthread.h>
#include "udp.hpp"
#include "picojson.h"


float posX;
float posY;

void* recv_th(void* pParam);
void* send_th(void* pParam);

int main() {
  std::cout << "start program" << std::endl;

  pthread_t th_recv;
  //pthread_t th_send;

  pthread_create(&th_recv, NULL, recv_th, NULL);
  //pthread_create(&th_send, NULL, send_th, NULL);

  pthread_join(th_recv, NULL);
  //pthread_join(th_send, NULL);

  std::cout << "end program" << std::endl; 
}

void* recv_th(void* pParam) {
  while(1) {
    Udp udp;
    udp.initAddr(54321, "");
    std::string data = udp.recieve();

    std::cout << data << std::endl;
    
    picojson::value val;
    picojson::parse(val, data);
    picojson::object obj = val.get<picojson::object>();
    posX = obj["posx"].get<double>();
    posY = obj["posy"].get<double>();

    //if (val.serialize()) continue;
    Udp udd;
    udd.initAddr(12345, "192.168.3.2");
    udd.send(val.serialize());
  }
}

void* send_th(void* pParam) {
  while(1) {
    picojson::object obj;
    obj.insert(std::make_pair("posx", picojson::value(posX)));
    obj.insert(std::make_pair("posy", picojson::value(posY)));
    picojson::value val(obj);

    Udp udp;
    udp.initAddr((u_short)54321, "192.168.101.92");
    udp.send(val.serialize());
  }
}
