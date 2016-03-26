
#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>


int main() {
  std::cout << "TcpServer start" << std::endl;

  int sock0;
  sockaddr_in addr;
  sockaddr_in client;
  socklen_t len;
  int sock;

  std::string str = "HelloXD";

  // make sock
  std::cout << "make sock\n"; 
  sock0 = socket(AF_INET, SOCK_STREAM, 0);
  
  // setting
  addr.sin_family = AF_INET;
  addr.sin_port = htons(23456);
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_len = sizeof(addr);

  std::cout << "bind\n";
  bind(sock0, (sockaddr*)&addr, sizeof(addr));

  // listen
  std::cout << "listen\n";
  listen(sock0, 5);

  // accept
  std::cout << "accept\n";
  len = sizeof(client);
  sock = accept(sock0, (sockaddr*)&client, &len);

  // send
  std::cout << "send\n";
  write(sock, str.c_str(), str.size());

  std::cout << "close sock\n";
  close(sock);
  close(sock0);

  std::cout << "TcpServer end" << std::endl;
}
