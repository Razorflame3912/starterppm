#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/time.h>
#define INPUTSIZE 20

int main(){
  int i,j;
  float r,g,b;
  char input[INPUTSIZE];
  umask(0);
  int f = open("img.ppm",O_CREAT | O_WRONLY | O_APPEND,0666);

  memset(input,0,INPUTSIZE);
  strcat(input, "P3\n500 500\n255\n");
  write(f,input,INPUTSIZE);

  for(i=0;i<500;i++){
    r = (i/500)*256;
    for(j=0;j<500;j++){
      memset(input,0,INPUTSIZE);
      g = (j/500)*256;
      b = (j/500)*256;
      sprintf(input, "%d %d %d \n",r,g,b);
      write(f,input,INPUTSIZE);
    }
  }
  close(f);

  
  return 0;

}
