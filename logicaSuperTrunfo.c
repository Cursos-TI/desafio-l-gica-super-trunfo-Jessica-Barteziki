#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Nível Novato - Cadastro e Comparação de Cartas
//Jessica Dill Barteziki

// Definição da estrutura para representar uma carta do Super Trunfo
typedef struct {
    char estado[3];
    char codigo[5];
    char nomeCidade[100];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para calcular a densidade populacional
float calcularDensidadePopulacional(int populacao, float area) {
    if (area > 0) {
        return (float)populacao / area;
    } else {
        return 0;
    }
}

// Função para calcular o PIB per capita
float calcularPibPerCapita(float pib, int populacao) {
    if (populacao > 0) {
        return pib / populacao;
    } else {
        return 0;
    }
}

int main() {
    // Declaração das duas cartas
    Carta carta1, carta2;

    // Cadastro da Carta 1:
    printf("Cadastro da Carta 1:\n");
    printf("Estado (ex: SP): ");
    scanf("%s", carta1.estado);
    printf("Código da Carta (ex: A01): ");
    scanf("%s", carta1.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta1.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    printf("\n");

    // Cadastro da Carta 2:
    printf("Cadastro da Carta 2:\n");
    printf("Estado (ex: RJ): ");
    scanf("%s", carta2.estado);
    printf("Código da Carta (ex: B02): ");
    scanf("%s", carta2.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta2.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);
    printf("\n");

    // Cálculo da Densidade Populacional e PIB per capita para cada carta
    carta1.densidadePopulacional = calcularDensidadePopulacional(carta1.populacao, carta1.area);
    carta2.densidadePopulacional = calcularDensidadePopulacional(carta2.populacao, carta2.area);

    carta1.pibPerCapita = calcularPibPerCapita(carta1.pib * 1e9, carta1.populacao);
    carta2.pibPerCapita = calcularPibPerCapita(carta2.pib * 1e9, carta2.populacao);

    // Escolha do atributo para comparação 
    char atributoComparacao[] = "População"; // Opções: "Área", "PIB", "Densidade Populacional", "PIB per capita"

    printf("Comparação de cartas (Atributo: %s):\n\n", atributoComparacao);
    printf("Carta 1 - %s (%s): ", carta1.nomeCidade, carta1.estado);
    printf("Carta 2 - %s (%s): ", carta2.nomeCidade, carta2.estado);

    // Lógica de comparação baseada no atributo escolhido
    if (strcmp(atributoComparacao, "População") == 0) {
        printf("%d\n%d\n", carta1.populacao, carta2.populacao);
        if (carta1.populacao > carta2.populacao) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.populacao > carta1.populacao) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: As cartas empataram em População!\n");
        }
    } else if (strcmp(atributoComparacao, "Área") == 0) {
        printf("%.2f km²\n%.2f km²\n", carta1.area, carta2.area);
        if (carta1.area > carta2.area) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.area > carta1.area) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: As cartas empataram em Área!\n");
        }
    } else if (strcmp(atributoComparacao, "PIB") == 0) {
        printf("%.2f bilhões de reais\n%.2f bilhões de reais\n", carta1.pib, carta2.pib);
        if (carta1.pib > carta2.pib) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.pib > carta1.pib) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: As cartas empataram em PIB!\n");
        }
    } else if (strcmp(atributoComparacao, "Densidade Populacional") == 0) {
        printf("%.2f hab/km²\n%.2f hab/km²\n", carta1.densidadePopulacional, carta2.densidadePopulacional);
        if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.densidadePopulacional < carta1.densidadePopulacional) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: As cartas empataram em Densidade Populacional!\n");
        }
    } else if (strcmp(atributoComparacao, "PIB per capita") == 0) {
        printf("%.2f reais\n%.2f reais\n", carta1.pibPerCapita, carta2.pibPerCapita);
        if (carta1.pibPerCapita > carta2.pibPerCapita) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: As cartas empataram em PIB per capita!\n");
        }
    } else {
        printf("Atributo de comparação inválido!\n");
    }

    return 0;
}