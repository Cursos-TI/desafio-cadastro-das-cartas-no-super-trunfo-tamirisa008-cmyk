#include <stdio.h>
#include <string.h>

// Estrutura da carta
typedef struct {
    char estado;
    char codigo[4];
    char nomecidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    Carta carta1, carta2;

    printf("=== Cadastro da carta 1 ===\n");

    printf("Estado (letra A-H): ");
    scanf(" %c", &carta1.estado);
    limparBuffer();

    printf("Código da carta (ex: A01): ");
    scanf("%3s", carta1.codigo);
    limparBuffer();

    printf("Nome da cidade: ");
    fgets(carta1.nomecidade, sizeof(carta1.nomecidade), stdin);
    carta1.nomecidade[strcspn(carta1.nomecidade, "\n")] = '\0'; // remove \n

    printf("População: ");
    scanf("%d", &carta1.populacao);
    limparBuffer();

    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    limparBuffer();

    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);
    limparBuffer();

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    limparBuffer();


    printf("\n=== Cadastro da carta 2 ===\n");

    printf("Estado (letra A-H): ");
    scanf(" %c", &carta2.estado);
    limparBuffer();

    printf("Código da carta (ex: A01): ");
    scanf("%3s", carta2.codigo);
    limparBuffer();

    printf("Nome da cidade: ");
    fgets(carta2.nomecidade, sizeof(carta2.nomecidade), stdin);
    carta2.nomecidade[strcspn(carta2.nomecidade, "\n")] = '\0';

    printf("População: ");
    scanf("%d", &carta2.populacao);
    limparBuffer();

    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    limparBuffer();

    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);
    limparBuffer();

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);
    limparBuffer();


    // Exibição
    printf("\n\n=== Cartas Cadastradas ===\n");

    printf("\n--- Carta 1 ---\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Código: %s\n", carta1.codigo);
    printf("Cidade: %s\n", carta1.nomecidade);
    printf("População: %d habitantes\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);
    printf("PIB: R$ %.2f bilhões\n", carta1.pib);
    printf("Pontos Turísticos: %d\n", carta1.pontosTuristicos);

    printf("\n--- Carta 2 ---\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Código: %s\n", carta2.codigo);
    printf("Cidade: %s\n", carta2.nomecidade);
    printf("População: %d habitantes\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);
    printf("PIB: R$ %.2f bilhões\n", carta2.pib);
    printf("Pontos Turísticos: %d\n", carta2.pontosTuristicos);

    return 0;
}