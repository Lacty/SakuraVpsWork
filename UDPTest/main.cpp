
#include <sys/fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include <iostream>


int main() {
  int sock;
  sockaddr_in addr;

  sock = socket(AF_INET, SOCK_DGRAM, 0);

  addr.sin_family = AF_INET;
  addr.sin_port = htons(12345);
  addr.sin_addr.s_addr = inet_addr("192.168.10.179");

  sendto(sock, "HELLO", 5, 0, (sockaddr*)&addr, sizeof(addr));

  close(sock);

  return 0;
}
