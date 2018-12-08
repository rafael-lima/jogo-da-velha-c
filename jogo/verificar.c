int vertical(char *casas[3][3]) {
  return casas[0][0] == casas[1][0] && casas[1][0] == casas[2][0]
    || casas[0][1] == casas[1][1] && casas[1][1] == casas[2][1]
    || casas[0][2] == casas[1][2] && casas[1][2] == casas[2][2]
  ;
}

int horizontal(char *casas[3][3]) {
  return casas[0][0] == casas[0][1] && casas[0][1] == casas[0][2]
    || casas[1][0] == casas[1][1] && casas[1][1] == casas[1][2]
    || casas[2][0] == casas[2][1] && casas[2][1] == casas[2][2]
  ;
}

int diagonal(char *casas[3][3]) {
  return (casas[1][1] == casas[0][0] && casas[1][1] == casas[2][2])
    || (casas[1][1] == casas[0][2] && casas[1][1] == casas[2][0])
  ;
}

int verificar(char *casas[3][3]) {
  return vertical(casas)
    || horizontal(casas)
    || diagonal(casas)
  ;
}