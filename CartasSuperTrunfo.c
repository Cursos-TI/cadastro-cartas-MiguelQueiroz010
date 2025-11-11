#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

int main() {
  // Área para definição das variáveis para armazenar as propriedades das cidades

  char state_code, state_code_2;        //Código do Estado
  char card_code[10], card_code_2[10];    //Código da Carta Completo
  char city_name[40], city_name_2[40];  //Nome da Cidade

  int population, population_2;         //População
  int turistic_points, turistic_points_2;  //Número de Pontos Turísticos

  float area, area_2;                   //Área em km²
  float pib, pib_2;                     //Produto Interno Bruto [PIB]

  // Área para entrada de dados
  printf("Sistema de Cadastro de Cartas\nVersão Novato por Miguel A. Queiroz\n-------------------\n\n");

  //CARTA 1
  printf("Digite os dados para a carta 1:\n\n");
  
  printf("\nCódigo do Estado: ");
  scanf(" %c", &state_code);
  printf("\nCódigo da Carta: ");
  scanf(" %s", &card_code);
  printf("\nNome da Cidade: ");
  scanf(" %[^\n]", &city_name); //Tive de usar esse %[^\n] no lugar do fgets que está me jogando erro,
  //o [] são os caracteres lidos e o ^\n indica que ele vai ler enquanto (condição) ^ = negativo, não encontrar uma quebra \n.
  
  printf("\nNúmero de Habitantes: ");
  scanf("%d", &population);
  printf("\nÁrea da Cidade(km²): ");
  scanf("%f", &area);
  printf("\nPIB: ");
  scanf("%f",&pib);
  printf("\nNúmero de Pontos Turísticos: ");
  scanf("%d", &turistic_points);

  //CARTA 2
  printf("\nDigite os dados para a carta 2:\n\n");
  
  printf("\nCódigo do Estado: ");
  scanf(" %c", &state_code_2);
  printf("\nCódigo da Carta: ");
  scanf(" %s", &card_code_2);
  printf("\nNome da Cidade: ");
  scanf(" %[^\n]", &city_name_2); //%[^\n] é necessário 
  printf("\nNúmero de Habitantes: ");
  scanf("%d", &population_2);
  printf("\nÁrea da Cidade(km²): ");
  scanf("%f", &area_2);
  printf("\nPIB: ");
  scanf("%f",&pib_2);
  printf("\nNúmero de Pontos Turísticos: ");
  scanf("%d", &turistic_points_2);
  
  // Área para exibição dos dados da cidade
  printf("\nDADOS APURADOS\n----------------\n\n");

  //Imprime Carta 1
  printf("Carta 1:\nEstado: %c\nCódigo: %c%s\nNome da Cidade: %s\nPopulação: %d\nÁrea: %.2f km²\nPIB: %.2f  bilhões de reais\nNúmero de Pontos Turísticos: %d",
  state_code, state_code, card_code, city_name, population, area, pib, turistic_points);

  //Imprime Carta 2
  printf("\n\nCarta 2:\nEstado: %c\nCódigo: %c%s\nNome da Cidade: %s\nPopulação: %d\nÁrea: %.2f km²\nPIB: %.2f bilhões de reais\nNúmero de Pontos Turísticos: %d",
  state_code_2, state_code_2, card_code_2, city_name_2, population_2, area_2, pib, turistic_points_2);

  printf("\n\nFim do programa\n\n");

return 0;
} 
