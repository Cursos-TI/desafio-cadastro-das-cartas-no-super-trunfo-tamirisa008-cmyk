#include <stdio.h>
#include <string.h>

// Definição da estrutura Carta
typedef struct {
    char estado;               // Uma letra A-H
    char codigo[4];            // Código da carta (ex: A01)
    char nomecidade[50];       // Nome da cidade
    int populacao;             // População total
    float area;                // Área em km²
    float pib;                 // PIB em bilhões
    int pontosTuristicos;      // Número de pontos turísticos
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para limpar buffer do teclado após scanf
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Função para calcular densidade populacional
float calcularDensidade(int populacao, float area) {
    return (float)populacao / area;
}

// Função para calcular PIB per Capita
float calcularPIBPerCapita(float pib, int populacao) {
    return (pib * 1000000000.0f) / (float)populacao;
}

// Função para calcular o Super Poder
float calcularSuperPoder(Carta c) {
    double soma;
    soma = (double)c.populacao + c.area + c.pib + c.pontosTuristicos + c.pibPerCapita + (1.0f / c.densidadePopulacional);
    return (float)soma;
}

int main() {
    Carta carta1, carta2;

    // Entrada da carta 1
    printf("=== Cadastro da carta 1 ===\n");
    printf("Estado (letra A-H): ");
    scanf(" %c", &carta1.estado);
    limparBuffer();

    printf("Código da carta (ex: A01): ");
    scanf("%3s", carta1.codigo);
    limparBuffer();

    printf("Nome da cidade: ");
    fgets(carta1.nomecidade, sizeof(carta1.nomecidade), stdin);
    carta1.nomecidade[strcspn(carta1.nomecidade, "\n")] = '\0';

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

    // Entrada da carta 2
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

    // Calcular densidade populacional
    carta1.densidadePopulacional = calcularDensidade(carta1.populacao, carta1.area);
    carta2.densidadePopulacional = calcularDensidade(carta2.populacao, carta2.area);

    // Calcular PIB per Capita
    carta1.pibPerCapita = calcularPIBPerCapita(carta1.pib, carta1.populacao);
    carta2.pibPerCapita = calcularPIBPerCapita(carta2.pib, carta2.populacao);

    // Calcular Super Poder
    float superPoder1 = calcularSuperPoder(carta1);
    float superPoder2 = calcularSuperPoder(carta2);

    // Comparações (1 = carta1 vence, 0 = carta2 vence)
    int vPopulacao = (carta1.populacao > carta2.populacao) ? 1 : 0;
    int vArea = (carta1.area > carta2.area) ? 1 : 0;
    int vPIB = (carta1.pib > carta2.pib) ? 1 : 0;
    int vPontos = (carta1.pontosTuristicos > carta2.pontosTuristicos) ? 1 : 0;
    int vDensidade = (carta1.densidadePopulacional < carta2.densidadePopulacional) ? 1 : 0; // menor vence
    int vPIBperCapita = (carta1.pibPerCapita > carta2.pibPerCapita) ? 1 : 0;
    int vSuperPoder = (superPoder1 > superPoder2) ? 1 : 0;

    // Exibir resultados
    printf("\n\nComparação de Cartas:\n");
    printf("População: Carta 1 venceu (%d)\n", vPopulacao);
    printf("Área: Carta 1 venceu (%d)\n", vArea);
    printf("PIB: Carta 1 venceu (%d)\n", vPIB);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", vPontos);
    printf("Densidade Populacional: Carta 2 venceu (%d)\n", 1 - vDensidade);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", vPIBperCapita);
    printf("Super Poder: Carta 1 venceu (%d)\n", vSuperPoder);

    return 0;
}
