
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
  //while(1) {
    Udp udp;
    udp.initAddr(54321, "192.168.10.179");
    udp.send("hoge");
    //std::string data = udp.recieve();

    //std::cout << data << std::endl;
    
    //picojson::value val;
    //picojson::parse(val, data);
    //picojson::object obj = val.get<picojson::object>();
    //posX = obj["posx"].get<double>();
    //posY = obj["posy"].get<double>();
    
    //int sock;
    //sockaddr_in addr;

  //sock = socket(AF_INET, SOCK_DGRAM, 0);

  //addr.sin_family = AF_INET;
  //addr.sin_port = htons(54321);
  //addr.sin_addr.s_addr = inet_addr("192.168.10.179");

  //int res = sendto(sock, val.serialize().c_str(), val.serialize().size(), 0, (sockaddr*)&addr, sizeof(addr));
  //std::cout << val.serialize().c_str() << " : " << val.serialize().size() << " : " << res << std::endl;
  //close(sock);
  //}
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
