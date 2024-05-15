#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

int  pd[2],pd2[2], n,n2, pid;
char line[100],  *s="datos del pipe1 en un mensaje mas grande";
char line2[100], *s2="otra cadena de mensaje para el pipe2";

int main(int argc, char *argv[]) {
  pid = getpid();
  printf("Padre = %d\n", pid);

  pipe(pd);
  pipe(pd2);

  if (fork()) {
    printf("Padre %d cierra pd[0]\n", pid);
    close(pd[0]);
    close(pd2[1]);

    for (int i = 1; i < 4; i++) {
      printf("Padre %d escribe pipe : %s\n", pid, s);
      write(pd[1], s, strlen(s) + 1);

      printf("Padre %d lee del pipe : ", pid);
      n2 = read(pd2[0], line2, strlen(s2) + 1);
      if (n2 == 0) break;
      line2[n2] = 0;
      printf("%s\n", line2);
    }
  } else {
    pid = getpid();
    printf("Hijo  %d cierra pd[1]\n", pid);
    close(pd[1]);

    for (int i = 1; i < 4; i++) {
      printf("Hijo  %d lee del pipe : ", pid);
      n = read(pd[0], line, strlen(s) + 1);
      if (n == 0) break;
      line[n] = 0;
      printf("%s\n", line);

      printf("Hijo %d escribe pipe : %s\n", pid, s2);
      write(pd2[1], s2, strlen(s2) + 1);
    }
  }
}
