#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

int randomnum(){
  int fd = open("/dev/random", O_RDONLY);
  int *buf = malloc(4);
  read(fd, buf, sizeof(int));
  int rand = abs(*buf % 15) + 5;
  close(fd);
  return rand;
}

int main(){
  printf("Forking...\n");
  int forker;
  if((forker = fork())){
    forker = fork();
  }
  if( forker == 0){
    printf("Child process...\n");
    printf("\tChild's pid: %d\n", getpid());
    int num = randomnum();
    sleep(num);
    printf("Child is finished.\n");
    exit(num);
  }else{
    int status;
    printf("Parent process...\n\tPid of completed child: %d\n", wait(&status));
    if(WIFEXITED(status)) {
      int sleep = WEXITSTATUS(status);
      printf("\tChild slept for %d seconds.\n", sleep);
    }
    printf("Parent is finished.\n");
    return 0;
  }
  return 0;
}
