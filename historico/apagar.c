#include <stdio.h>

void apagar_log() {
  FILE *historico;

  historico = fopen(".historico.txt", "w");

  fprintf(historico, "%s", "");
  fclose(historico);
}