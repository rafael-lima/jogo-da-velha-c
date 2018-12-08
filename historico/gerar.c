#include <stdio.h>
#include <time.h>

void gerar_log(char vencedor[], char derrotado[], int tem_vencedor) {
  FILE *historico;

  historico = fopen(".historico.txt", "a");

  time_t tempo;
  struct tm *s_tempo;

  tempo = time(NULL);
  s_tempo = localtime(&tempo);

  fprintf(
    historico,
    "* Partida %s - %d:%d:%d\n",
    __DATE__,
    s_tempo->tm_hour, s_tempo->tm_min, s_tempo->tm_sec
  );

  if (tem_vencedor) {
    fprintf(historico, " - Vencedor: %s;\n", vencedor);
    fprintf(historico, " - Derrotado: %s.\n\n", derrotado);
  } else {
    fprintf(historico, " - Jogo empatado.\n");
    fprintf(historico, " - Jogadores: %s, %s.\n\n", vencedor, derrotado);
  }

  fclose(historico);
}