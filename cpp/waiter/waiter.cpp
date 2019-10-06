#include <stdio.h>
#include <thread>
#include <chrono>

int main() {
  int total, inter;
  int res = 0;
  scanf("%d %d", &total, &inter);
  while(res < total) {
    printf("Hello %d\n", res);
	fflush(stdout);
    std::this_thread::sleep_for(std::chrono::milliseconds(inter * 1000));  
    res += inter; 
  }
  printf("Hello %d\n", res);
  return 0;
}
