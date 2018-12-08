#include <stdio.h>
#include <stdbool.h>

int exibir_log() {
  FILE *historico;

  historico = fopen(".historico.txt", "r");

  if (historico == NULL) {
    historico = fopen(".historico.txt", "w");
    fprintf(historico, "%s", "");
  }

  char linha[100];
  bool vazio = true;

  while(fgets(linha, 100, historico) != NULL) {
    vazio = false;
    printf("%s", linha);
  }

  if (vazio) printf("Histórico vazio.\n");

  fclose(historico);

  return vazio;
}