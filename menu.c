#include <stdio.h>

int menu(void) {
  int opcao = 0;

  printf("- # JOGO DA VELHA (MENU) -\n\n");

  printf("1 - Novo Jogo;\n2 - Histórico;\n3 - Sair.\n");

  do {
    printf("\n=> ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1: case 2: return opcao;

      case 3: printf("Fim.\n"); break;

      default: printf("\n*Por favor, digite uma opção válida.");
    }
  } while (opcao < 1 || opcao > 3);
}