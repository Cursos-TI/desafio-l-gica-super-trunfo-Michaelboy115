#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio

    // --- Variáveis da Carta 1 ---
    char estado_1;
    int num_cidade_1;
    char nome_cidade_1[50];
    float populacao_1; 
    float area_1;      
    float pib_1;       
    int turisticos_1;  
    float densidade_1;    
    float pib_percapita_1;
    float super_poder_1; 
    
    // --- Variáveis da Carta 2 ---
    char estado_2;
    int num_cidade_2;
    char nome_cidade_2[50];
    float populacao_2; 
    float area_2;      
    float pib_2;       
    int turisticos_2;  
    float densidade_2;    
    float pib_percapita_2;
    float super_poder_2; 

     // Variável para consumir o ENTER entre as leituras (mantida a técnica anterior)
    char enter_dummy;
    
    // Cadastro das Cartas:
// --- CADASTRO DA CARTA 1 ---
    printf("\n--- Inserir Dados da Carta 1 ---\n");
    printf("Sigla do Estado (ex: A): ");
    scanf(" %c", &estado_1); 
    printf("Numero da Cidade (ex: 1): ");
    scanf("%d", &num_cidade_1);
    scanf("%c", &enter_dummy); 
    printf("Nome da Cidade (UMA palavra, ex: SAOPAULO): ");
    scanf("%49s", nome_cidade_1); 
    printf("Populacao (em milhoes, ex: 12.325): ");
    scanf("%f", &populacao_1);
    scanf("%c", &enter_dummy); 
    printf("Area (em km2, ex: 1521.11): ");
    scanf("%f", &area_1);
    scanf("%c", &enter_dummy); 
    printf("PIB (em bilhoes, ex: 699.28): ");
    scanf("%f", &pib_1);
    scanf("%c", &enter_dummy); 
    printf("Numero de Pontos Turisticos (ex: 50): ");
    scanf("%d", &turisticos_1);
    scanf("%c", &enter_dummy); 

    // --- CADASTRO DA CARTA 2 ---
    printf("\n--- Inserir Dados da Carta 2 ---\n");
    printf("Sigla do Estado (ex: B): ");
    scanf(" %c", &estado_2);
    printf("Numero da Cidade (ex: 1): ");
    scanf("%d", &num_cidade_2);
    scanf("%c", &enter_dummy); 
    printf("Nome da Cidade (UMA palavra, ex: RIODEJANEIRO): ");
    scanf("%49s", nome_cidade_2);
    printf("Populacao (em milhoes, ex: 6.748): ");
    scanf("%f", &populacao_2);
    scanf("%c", &enter_dummy); 
    printf("Area (em km2, ex: 1202.25): ");
    scanf("%f", &area_2);
    scanf("%c", &enter_dummy); 
    printf("PIB (em bilhoes, ex: 300.50): ");
    scanf("%f", &pib_2);
    scanf("%c", &enter_dummy); 
    printf("Numero de Pontos Turisticos (ex: 30): ");
    scanf("%d", &turisticos_2);
    scanf("%c", &enter_dummy); 

    // CÁLCULOS (Manter para a exibição completa)
    densidade_1 = populacao_1 / area_1;
    pib_percapita_1 = pib_1 / populacao_1;
    super_poder_1 = populacao_1 + area_1 + pib_1 + pib_percapita_1 + (1.0 / (densidade_1 * 1000.0)) + turisticos_1; 

    densidade_2 = populacao_2 / area_2;
    pib_percapita_2 = pib_2 / populacao_2;
    super_poder_2 = populacao_2 + area_2 + pib_2 + pib_percapita_2 + (1.0 / (densidade_2 * 1000.0)) + turisticos_2;


    printf("\n\n===== RESULTADOS DA COMPARACAO =====\n");
    printf("Comparando População (Quanto MAIOR, melhor):\n");
    
    // Comparação de População
    if (populacao_1 > populacao_2) {
        printf(" -> VENCEDOR: Carta 1 (%s) - População %.2f milhoes\n", nome_cidade_1, populacao_1);
    } else if (populacao_2 > populacao_1) {
        printf(" -> VENCEDOR: Carta 2 (%s) - População %.2f milhoes\n", nome_cidade_2, populacao_2);
    } else {
        printf(" -> EMPATE: Populações iguais.\n");
    }

    printf("\nComparando Densidade Demográfica (Quanto MENOR, melhor - Invertida):\n");
    
    // Comparação de Densidade (Regra: Quanto MENOR a densidade, melhor)
    if (densidade_1 < densidade_2) {
        printf(" -> VENCEDOR: Carta 1 (%s) - Densidade %.2f hab/km2\n", nome_cidade_1, densidade_1 * 1000.0);
    } else if (densidade_2 < densidade_1) {
        printf(" -> VENCEDOR: Carta 2 (%s) - Densidade %.2f hab/km2\n", nome_cidade_2, densidade_2 * 1000.0);
    } else {
        printf(" -> EMPATE: Densidades iguais.\n");
    }

    printf("\nComparando PIB (Quanto MAIOR, melhor):\n");
    
    // Comparação de PIB
    if (pib_1 > pib_2) {
        printf(" -> VENCEDOR: Carta 1 (%s) - PIB %.2f bilhoes\n", nome_cidade_1, pib_1);
    } else if (pib_2 > pib_1) {
        printf(" -> VENCEDOR: Carta 2 (%s) - PIB %.2f bilhoes\n", nome_cidade_2, pib_2);
    } else {
        printf(" -> EMPATE: PIBs iguais.\n");
    }

    printf("\nComparando Super Poder (Quanto MAIOR, melhor):\n");

    // Comparação de Super Poder
    if (super_poder_1 > super_poder_2) {
        printf(" -> VENCEDOR: Carta 1 (%s) - Super Poder %.2f\n", nome_cidade_1, super_poder_1);
    } else if (super_poder_2 > super_poder_1) {
        printf(" -> VENCEDOR: Carta 2 (%s) - Super Poder %.2f\n", nome_cidade_2, super_poder_2);
    } else {
        printf(" -> EMPATE: Super Poderes iguais.\n");
    }


    // Exibição dos Resultados:
printf("\n\n===== Dados Completos das Cartas =====\n");
    
    // Exibição da Carta 1
    printf("\n--- Carta 1 (Código: %c%d) ---\n", estado_1, num_cidade_1);
    printf("Nome: %s\n", nome_cidade_1);
    printf("Populacao: %.2f milhoes\n", populacao_1);
    printf("Area: %.2f km2\n", area_1);
    printf("Densidade Demografica: %.2f hab/km2\n", densidade_1 * 1000.0);
    printf("PIB: %.2f bilhoes\n", pib_1);
    printf("PIB Per Capita: %.2f bilhoes/milhao\n", pib_percapita_1); 
    printf("P. Turisticos: %d\n", turisticos_1);
    printf("Super Poder: %.2f\n", super_poder_1);

    // Exibição da Carta 2
    printf("\n--- Carta 2 (Código: %c%d) ---\n", estado_2, num_cidade_2);
    printf("Nome: %s\n", nome_cidade_2);
    printf("Populacao: %.2f milhoes\n", populacao_2);
    printf("Area: %.2f km2\n", area_2);
    printf("Densidade Demografica: %.2f hab/km2\n", densidade_2 * 1000.0);
    printf("PIB: %.2f bilhoes\n", pib_2);
    printf("PIB Per Capita: %.2f bilhoes/milhao\n", pib_percapita_2); 
    printf("P. Turisticos: %d\n", turisticos_2);
    printf("Super Poder: %.2f\n", super_poder_2);

    return 0;
}
