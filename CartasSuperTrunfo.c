#include <stdio.h>

typedef struct {
    char estado;
    char codigo[4];
    char nomecidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

int main() {
    Carta carta1, carta2;

 printf("=== Cadastro da carta 1 ===\n");

 printf("Estado(letra A-H):");
 scanf(" %c", &carta1.estado);

 printf("Codigo da carta (ex:A01): ");
 scanf("%s", &carta1.codigo);

 printf("Nome da cidade: ");
 scanf(" %[^\n]", carta1.nomecidade);

 printf("Populacao: ");
 scanf("%d", &carta1.populacao);

 printf("Area (em km²): ");
 scanf("%f", &carta1.area);

 printf("Pib: ");
 scanf("%f", &carta1.pib);

 printf("Numero de Pontos Turisticos:");
 scanf("%d", &carta1.pontosTuristicos);

 
 printf("\n=== Cadastro da carta 2 ===\n");

 printf("Estado(letra A-H):");
 scanf(" %c", &carta2.estado);

 printf("Codigo da carta (ex:A01): ");
 scanf("%s", &carta2.codigo);

 printf("Nome da cidade: ");
 scanf(" %[^\n]", carta2.nomecidade);

 printf("Populacao: ");
 scanf("%d", &carta2.populacao);

 printf("Area (em km²): ");
 scanf("%f", &carta2.area);

 printf("Pib: ");
 scanf("%f", &carta2.pib);

 printf("Numero de Pontos Turisticos:");
 scanf("%d", &carta2.pontosTuristicos);

 return 0;
}
