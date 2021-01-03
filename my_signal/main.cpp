#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <signal.h> /*for signal() and raise()*/

void hello(int signum){
    printf("Hello World!\n");
    exit(0);
}

int main(){

//  signal(SIGKILL, hello);
  signal(SIGINT, hello);

    while (1);
}
