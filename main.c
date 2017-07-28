#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

int pipefd[2];

if(pipe(pipefd)<0){
perror("pipe");
exit(1);
}

pid_t pid;
pid = fork();
if (pid == 0) {
	pid=execve("prog1",argv,NULL);
    return 0;
  }else if (pid < 0) {
    // Error forking
    perror("error");
  }else {
    wait(&pid);
  }

pid_t pid2;
pid2 = fork();
if (pid2 == 0) {
	pid2=execve("prog2",argv,NULL);
    return 0;
  }else if (pid < 0) {
    // Error forking
    perror("error");
  } else {
    wait(&pid2);
  }

pid_t pid3;
pid3 = fork();
if (pid3 == 0) {
	pid3=execve("prog3",argv,NULL);
    return 0;
  }else if (pid < 0) {
    // Error forking
    perror("error");
  } else {
    wait(&pid3);
  }

    return 0;
}
