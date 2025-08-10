#include <stdio.h>
#include <string.h>

// Definição da estrutura Carta
typedef struct {
    char estado;                    // Uma letra A-H
    char codigo[4];                 // Código da carta (ex: A01)
    char nomecidade[50];            // Nome da cidade
    unsigned long int populacao;    // População total (unsigned long int para nível mestre)
    float area;                    // Área em km²
    float pib;                     // PIB em bilhões
    int pontosTuristicos;          // Número de pontos turísticos
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para limpar buffer do teclado após scanf
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Função para calcular densidade populacional
float calcularDensidade(unsigned long int populacao, float area) {
    return (float)populacao / area;
}

// Função para calcular PIB per Capita
float calcularPIBPerCapita(float pib, unsigned long int populacao) {
    return (pib * 1000000000.0f) / (float)populacao;
}

// Função para calcular o Super Poder (retornando double para maior precisão)
double calcularSuperPoder(Carta c) {
    double soma;
    soma = (double)c.populacao + c.area + c.pib + c.pontosTuristicos + 
           c.densidadePopulacional + c.pibPerCapita + (1.0 / c.densidadePopulacional);
    return soma;
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
    scanf("%lu", &carta1.populacao);
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
    scanf("%lu", &carta2.populacao);
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
    double superPoder1 = calcularSuperPoder(carta1);
    double superPoder2 = calcularSuperPoder(carta2);

    // Exibir dados com Super Poder incluído
    printf("\n=== Dados da Carta 1 ===\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Código: %s\n", carta1.codigo);
    printf("Cidade: %s\n", carta1.nomecidade);
    printf("População: %lu habitantes\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);
    printf("PIB: R$ %.2f bilhões\n", carta1.pib);
    printf("Pontos Turísticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", carta1.pibPerCapita);
    printf("Super Poder: %.2lf\n", superPoder1);

    printf("\n=== Dados da Carta 2 ===\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Código: %s\n", carta2.codigo);
    printf("Cidade: %s\n", carta2.nomecidade);
    printf("População: %lu habitantes\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);
    printf("PIB: R$ %.2f bilhões\n", carta2.pib);
    printf("Pontos Turísticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", carta2.pibPerCapita);
    printf("Super Poder: %.2lf\n", superPoder2);

    // Comparações (1 = carta 1 vence, 0 = carta 2 vence)
    int vPopulacao = (carta1.populacao > carta2.populacao) ? 1 : 0;
    int vArea = (carta1.area > carta2.area) ? 1 : 0;
    int vPIB = (carta1.pib > carta2.pib) ? 1 : 0;
    int vPontos = (carta1.pontosTuristicos > carta2.pontosTuristicos) ? 1 : 0;
    int vDensidade = (carta1.densidadePopulacional < carta2.densidadePopulacional) ? 1 : 0; // menor vence
    int vPIBperCapita = (carta1.pibPerCapita > carta2.pibPerCapita) ? 1 : 0;
    int vSuperPoder = (superPoder1 > superPoder2) ? 1 : 0;

    // Exibir resultados das comparações com mensagens amigáveis
    printf("\nComparação de Cartas:\n");

    printf("População: ");
    if (vPopulacao == 1) {
        printf("Carta 1 venceu.\n");
    } else {
        printf("Carta 2 venceu.\n");
    }

    printf("Área: ");
    if (vArea == 1) {
        printf("Carta 1 venceu.\n");
    } else {
        printf("Carta 2 venceu.\n");
    }

    printf("PIB: ");
    if (vPIB == 1) {
        printf("Carta 1 venceu.\n");
    } else {
        printf("Carta 2 venceu.\n");
    }

    printf("Pontos Turísticos: ");
    if (vPontos == 1) {
        printf("Carta 1 venceu.\n");
    } else {
        printf("Carta 2 venceu.\n");
    }

    printf("Densidade Populacional: ");
    if (vDensidade == 1) {
        printf("Carta 1 venceu.\n");
    } else {
        printf("Carta 2 venceu.\n");
    }

    printf("PIB per Capita: ");
    if (vPIBperCapita == 1) {
        printf("Carta 1 venceu.\n");
    } else {
        printf("Carta 2 venceu.\n");
    }

    printf("Super Poder: ");
    if (vSuperPoder == 1) {
        printf("Carta 1 venceu.\n");
    } else {
        printf("Carta 2 venceu.\n");
    }

    return 0;
}
