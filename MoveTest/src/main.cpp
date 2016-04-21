
#include <iostream>
#include <string>
#include <pthread.h>
#include "socket.hpp"
#include "picojson.h"


const int PORT = 12345;

static float posX = 0;
static float posY = 0;

void* recv_th_(void* pParam);
void* send_th_(void* pParam);

static Socket server_;
static Socket client_;

static std::string data_;

int main() {
  std::cout << "start program" << std::endl;

  server_.create();
  server_.bind(PORT);
  server_.listen();

  pthread_t th_recv_;
  //pthread_t th_send_;

  pthread_create(&th_recv_, NULL, recv_th_, NULL);
  //pthread_create(&th_send_, NULL, send_th_, NULL);

  pthread_join(th_recv_, NULL);
  //pthread_join(th_send_, NULL);

  std::cout << "end program" << std::endl; 
}

void* recv_th_(void* pParam) {
  while(1) {
    server_.accept(client_);
    client_ >> data_;
    std::cout << "recv : " << data_ << std::endl;
  }
}

void* send_th_(void* pParam) {
  while(1) {
    client_ << data_;
    std::cout << "send : " << data_ << std::endl;
  }
}
