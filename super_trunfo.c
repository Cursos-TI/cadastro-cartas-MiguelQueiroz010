#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

//Como a ideia é ter um código organizado e bem estruturado já comecei usando tudo que sei para simplificar,
//já vou começar com struct e com alguns módulos para cada tarefa.

typedef struct{
  // Área para definição das variáveis para armazenar as propriedades das cidades
  char state_code;      //Código do Estado
  char card_code[10];   //Código da Carta Completo
  char city_name[40];   //Nome da Cidade

  int population;       //População
  int turistic_points;  //Número de Pontos Turísticos

  float area;           //Área em km²
  float pib;            //Produto Interno Bruto [PIB]

  //Adicionar Densidade Populacional e PIB per Capita
  float population_density;
  float pib_per_capita;

  //Super Poder
  float super_power;

  int index;            //Índice da Carta

  } SuperCard;

SuperCard GetValues(int card_index)
{
  SuperCard Entry;
  Entry.index = card_index;

  printf("\n\nDigite os dados para a carta %d:\n\n", card_index);
  
  printf("\nCódigo do Estado: ");
  scanf(" %c", &Entry.state_code);
  printf("\nCódigo da Carta: ");
  scanf(" %s", &Entry.card_code);
  printf("\nNome da Cidade: ");
  scanf(" %[^\n]", &Entry.city_name); //O [] são os caracteres lidos e o ^\n indica que ele vai
  //ler enquanto (condição) ^ = negativo, não encontrar uma quebra \n.
  
  printf("\nNúmero de Habitantes: ");
  scanf("%d", &Entry.population);
  printf("\nÁrea da Cidade(km²): ");
  scanf("%f", &Entry.area);
  printf("\nPIB: ");
  scanf("%f",&Entry.pib);
  printf("\nNúmero de Pontos Turísticos: ");
  scanf("%d", &Entry.turistic_points);

  Entry.population_density = Entry.population / Entry.area;
  Entry.pib_per_capita = Entry.pib / Entry.population;

  //Calcular Super-Poder
  float inverted_pop_density = 1 / Entry.population_density;

  Entry.super_power = (float) ( (Entry.population + Entry.turistic_points) +
  (Entry.area + Entry.pib + Entry.pib_per_capita + inverted_pop_density));

  return Entry;
}

void ShowValues(SuperCard card)
{
  //Imprime [para cada] Carta
  printf(
    "\n\nCarta %d:"
    "\nEstado: %c"
    "\nCódigo: %c%s"
    "\nNome da Cidade: %s"
    "\nPopulação: %d"
    "\nÁrea: %.2f km²"
    "\nPIB: %.2f bilhões de reais"
    "\nNúmero de Pontos Turísticos: %d"
    "\nDensidade Populacional: %2.f hab/km²"
    "\nPIB per Capita: %2.f reais",
    card.index,
    card.state_code,
    card.state_code, card.card_code,
    card.city_name,
    card.population,
    card.area,
    card.pib,
    card.turistic_points,
    card.population_density,
    card.pib_per_capita);
}

void CompareCards(SuperCard carta_a, SuperCard carta_b)
{

  int carta_a_popu = carta_a.population > carta_b.population;
  int carta_a_area = carta_a.area > carta_b.area;
  int carta_a_pib = carta_a.pib > carta_b.pib;
  int carta_a_ponto = carta_a.turistic_points > carta_b.turistic_points;
  int carta_a_densi = carta_a.population_density < carta_b.population_density;
  int carta_a_pibpc = carta_a.pib_per_capita > carta_b.pib_per_capita;
  int carta_a_super = carta_a.super_power > carta_b.super_power;

  printf(
    "\n\nComparação de Cartas:"
    "\nPopulação: Carta %d venceu (%d)"
    "\nÁrea: Carta %d venceu (%d)"
    "\nPIB: Carta %d venceu (%d)"
    "\nPontos Turísticos: Carta %d venceu (%d)"
    "\nDensidade Populacional: Carta %d venceu (%d)"
    "\nPIB per Capita: Carta %d venceu (%d)"
    "\nSuper Poder: Carta %d venceu (%d)",
    carta_a_popu == 1 ? carta_a.index : carta_b.index,
    carta_a_popu,
    carta_a_area == 1 ? carta_a.index : carta_b.index,
    carta_a_area,
    carta_a_pib == 1 ? carta_a.index : carta_b.index,
    carta_a_pib,
    carta_a_ponto == 1 ? carta_a.index : carta_b.index,
    carta_a_ponto,
    carta_a_densi == 1 ? carta_a.index : carta_b.index,
    carta_a_densi,
    carta_a_pibpc == 1 ? carta_a.index : carta_b.index,
    carta_a_pibpc,
    carta_a_super == 1 ? carta_a.index : carta_b.index,
    carta_a_super);


}

int main() {
  //Limpa o console
  system("cls");
  system("clear");

  // Mensagem de Sistema
  printf("Sistema de Cadastro de Cartas\nCoded by Miguel A. Queiroz\n-------------------");
  
  //Pegar os dados das Cartas
  SuperCard cartas[2];
  cartas[0] = GetValues(1); //Carta 1

  //Limpa o console
  system("cls");
  system("clear");

  cartas[1] = GetValues(2); //Carta 2

  //Limpa o console
  system("cls");
  system("clear");

  //Mostrar dados das Cartas
  // Mensagem de Sistema
  printf("Sistema de Cadastro de Cartas\nCoded by Miguel A. Queiroz\n-------------------\n");
  printf("\nDADOS APURADOS\n----------------");

  ShowValues(cartas[0]);  //Carta 1
  ShowValues(cartas[1]);  //Carta 2

  CompareCards(cartas[0], cartas[1]);

  printf("\n\nFim do programa\n\n");

return 0;
} 
