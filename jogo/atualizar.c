#include <stdio.h>

int atualizar(char *casas[3][3], char marcador[], char casa[]) {
  int casa_valida;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      casa_valida = strcmp(casas[i][j], casa) == 0;

      if (casa_valida) {
        if (strcmp(marcador, "X") == 0) {
          casas[i][j] = "X";
        } else {
          casas[i][j] = "O";
        }

        return casa_valida;
      }
    }
  }
}