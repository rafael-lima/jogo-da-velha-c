#include <stdio.h>
#include <stdbool.h>

#include "exibir.c"
#include "apagar.c"

int historico() {
  system("clear");

  printf("- # JOGO DA VELHA (HISTÓRICO) -\n\n");

  bool historico_vazio = exibir_log();

  if (!historico_vazio) printf("1 - Apagar histórico;");

  printf("\n2 - Voltar;\n3 - Sair.\n");

  int opcao = 0;

  do {
    printf("\n=> ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1: apagar_log(); break;

      case 2: return 1;

      case 3: printf("Fim.\n"); exit(0); break;

      default: printf("\n*Por favor, digite uma opção válida.");
    }
  } while (opcao < 1 || opcao > 2);
}