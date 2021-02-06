#include <stdlib.h>
#include <stdio.h>
#include <signal.h> /*for signal() and raise()*/

#include <iostream>
#include <csignal>
#include <unistd.h>

void hello(int signum){
    printf("Hello World!\n");
    exit(0);
}

int main(){

//  signal(SIGKILL, hello);
  signal(SIGINT, hello);
    sleep(1);

    while (1);
}
