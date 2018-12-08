#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "tabuleiro.c"
#include "atualizar.c"
#include "verificar.c"

#include "../structs/partida.c"
#include "../historico/gerar.c"

int novo_jogo(
  char *casas[3][3],
  char jogador_x[],
  char jogador_o[],
  char marcador[]
  ) {

  system("clear");

  struct partida jogo;

  char jogador_atual[15], casa[2];

  strcpy(jogador_atual, strcmp(marcador, "X") ? jogador_o : jogador_x);

  int qt_jogadas = 0;

  bool tem_vencedor = false;

  while (!tem_vencedor && qt_jogadas <= 9) {
    system("clear");
    tabuleiro(casas);

    bool casa_valida;

    if (qt_jogadas < 9) {
      do {
        printf("%s (%s) => ", marcador, jogador_atual);
        scanf("%s", casa);

        casa_valida = (strcmp(casa, "X") && strcmp(casa, "O"))
          && atualizar(casas, marcador, casa);

        if (!casa_valida) {
          printf("\n*Por favor, insira uma posição válida:\n");
        } else {
          qt_jogadas += 1;
        }
      } while (!casa_valida);
    }

    if (qt_jogadas >= 5) tem_vencedor = verificar(casas);

    if (tem_vencedor || qt_jogadas == 9) {
      system("clear");
      tabuleiro(casas);

      char voltar[1];

      if (tem_vencedor) {
        if (strcmp(marcador, "X") == 0) {
          strcpy(jogo.vencedor, jogador_x);
          strcpy(jogo.derrotado, jogador_o);
        } else {
          strcpy(jogo.vencedor, jogador_o);
          strcpy(jogo.derrotado, jogador_x);
        }

        printf("Vencedor: %s.\n", jogo.vencedor);
        gerar_log(jogo.vencedor, jogo.derrotado, tem_vencedor);
      } else {
        printf("Empate.\n");
        gerar_log(jogador_x, jogador_o, tem_vencedor);
      }

      printf("Fim de jogo!\n");

      printf("\nVoltar ao menu? (s/n): ");
      scanf("%s", voltar);

      if (!strcmp(voltar, "s") || !strcmp(voltar, "S")) return 1;
      else printf("Fim.\n"); exit(0);
    } else {
      if (!strcmp(marcador, "X")) {
        strcpy(marcador, "O");
        strcpy(jogador_atual, jogador_o);
      } else {
        strcpy(marcador, "X");
        strcpy(jogador_atual, jogador_x);
      }
    }
  }
}