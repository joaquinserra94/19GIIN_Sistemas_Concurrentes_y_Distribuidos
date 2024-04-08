#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void main(int argc, char *argv[]) {
  int i, n;
  pid_t hijopid;

  if (argc != 2) {
    fprintf(stderr, "USO: %s num_procesos\n", argv[0]);
    exit(1);
  }

  n = atoi(argv[1]);
  hijopid = 0;

  for (i = 1; i < n; i++)
    if (hijopid = fork())  // Add semicolon here
      break;

  if (hijopid == -1) {
    perror("error al ejecutar el fork");
    exit(1);
  }

  fprintf(stdout, "i:%d proceso - %ld Id del padre - %ld ID del hijo\n", i, (long)getppid(), (long)getpid());
  exit(0);
}
/*El programa crea un número específico de procesos hijo, según el valor del argumento proporcionado al ejecutarlo. En este caso hemos proporcionado el numero 5, por lo que ha creado 5 procesos hijo.
Cada proceso hijo imprime su ID, el ID de su padre y un contador que indica su posición entre los procesos creados. Por ejemplo tenemos, i:1 proceso - 257 Id del padre - 493 ID del hijo.
Como el padre no espera a los hijos, estos se convierten en procesos "huérfanos" después de que el padre termina.*/