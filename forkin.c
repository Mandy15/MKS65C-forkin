#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(){
  printf("Forking...\n");
  if( fork() == 0){
    printf("Child's pid: %d\n", getpid());
    sleep();
    printf("Child is finished.\n");
  }else{
    int *x;
    printf("Pid of completed child: %d\n", wait(x));
    printf("Child was asleep for %d seconds\n", );
    printf("Parent is finished.\n");
  }
  return 0;
}
