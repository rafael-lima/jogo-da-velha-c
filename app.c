#include <stdio.h>
#include <stdlib.h>

#include "menu.c"

#include "jogo/iniciar.c"
#include "historico/iniciar.c"

int main(void) {
  int voltar = 0;

  do {
    char *casas[3][3] = {
      "1", "2", "3",
      "4", "5", "6",
      "7", "8", "9"
    };

    system("clear");

    int opcao = menu();

    if (opcao == 1) {
      char jogador_x[15], jogador_o[15], marcador[2];

      printf("\nJogador X: ");
      scanf("%s", jogador_x);

      printf("Jogador O: ");
      scanf("%s", jogador_o);

      bool marcador_valido;

      do {
        printf("\nSelecione o jogador que iniciará a partida (X/O): ");
        scanf("%s", marcador);

        marcador_valido = strcmp(marcador, "X") && strcmp(marcador, "O")
          || strcmp(marcador, "x") && strcmp(marcador, "o");

        if (!marcador_valido) {
          printf("\n*Por favor, selecione um marcador válido.\n");
        }
      } while (!marcador_valido);

      if (!strcmp(marcador, "x")) strcpy(marcador, "X");
      if (!strcmp(marcador, "o")) strcpy(marcador, "O");

      voltar = novo_jogo(
        casas,
        jogador_x,
        jogador_o,
        marcador
      );
    } else if (opcao == 2) {
      voltar = historico();
    } else exit(0);
  } while (voltar);

  return 0;
}