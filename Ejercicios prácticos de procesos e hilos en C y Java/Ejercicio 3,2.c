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

  for (i = 1; i < n; i++) {
    if (hijopid = fork()) {
      // Esperar a que el hijo termine
      wait(NULL);
    } else {
      // Código del proceso hijo
      fprintf(stdout, "i:%d proceso - %ld Id del padre - %ld ID del hijo\n", i, (long)getppid(), (long)getpid());
      exit(0);
    }
  }

  if (hijopid == -1) {
    perror("error al ejecutar el fork");
    exit(1);
  }

  exit(0);
}
/*Con esta modificación, el padre esperará a que todos sus hijos terminen antes de terminar él mismo.
Esto evita que los procesos hijo se conviertan en huérfanos.*/