
#include <iostream>
#include <pthread.h>


void* thread(void* pParam);

int main() {
  pthread_t th1;

  pthread_create(&th1, NULL, thread, NULL);

  pthread_join(th1, NULL);

  return 0;
}

void* thread(void* pParam) {
  std::cout << "a" << std::endl;
  return NULL;
}
