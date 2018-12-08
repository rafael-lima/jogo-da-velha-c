#include <stdio.h>

void tabuleiro(char *casas[3][3]) {
  const char margem[] = "     ";

  printf("-%s# JOGO DA VELHA%s-\n\n\n", margem, margem);

  for (int i = 0; i < 3; i++) {
    if (i == 0) {
      printf("%s     |     |     \n", margem);
    }

    printf("%s", margem);

    for (int j = 0; j < 3; j++) {
      if (j != 2) {
        printf("  %s  |", casas[i][j]);
      } else {
        printf("  %s", casas[i][j]);
      }
    }

    if (i != 2) {
      printf("\n%s     |     |     ", margem);
      printf("\n%s-----------------\n", margem);
      printf("%s     |     |     \n", margem);
    } else {
      printf("\n%s     |     |     ", margem);
      printf("\n\n\n");
    }
  }
}