#include <stdio.h>


// VARIÁVEIS DA CARTA 1
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

// VARIÁVEIS DA CARTA 2
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

// Variável para consumir o ENTER
char enter_dummy;
// Variável de controle do menu
int opcao_menu = -1;
// Variável para a comparação
int atributo_comparacao = 0;


// ===========================================
// FUNÇÃO AUXILIAR: CADASTRO DE DADOS
// (Agrupa a entrada de dados para ser chamada uma vez)
// ===========================================
void cadastrar_cartas() {
    printf("===== CADASTRO DE DADOS DAS CARTAS =====\n");

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
    
    // CÁLCULOS
    densidade_1 = populacao_1 / area_1;
    pib_percapita_1 = pib_1 / populacao_1;
    super_poder_1 = populacao_1 + area_1 + pib_1 + pib_percapita_1 + (1.0 / (densidade_1 * 1000.0)) + turisticos_1; 

    densidade_2 = populacao_2 / area_2;
    pib_percapita_2 = pib_2 / populacao_2;
    super_poder_2 = populacao_2 + area_2 + pib_2 + pib_percapita_2 + (1.0 / (densidade_2 * 1000.0)) + turisticos_2;
    
    printf("\nCadastro e cálculos concluídos com sucesso.\n");
}

// ===========================================
// FUNÇÃO AUXILIAR: LÓGICA DE COMPARAÇÃO ANINHADA
// ===========================================
void comparar_cartas(int atributo) {
    float val1, val2;
    char *nome_atributo;
    int maior_melhor = 1; // 1 = maior valor vence, 0 = menor valor vence

    printf("\n--- RESULTADO DA BATALHA ---\n");

    // 1. SWITCH: Define os valores a serem comparados e a regra (maior/menor vence)
    switch (atributo) {
        case 1: // População
            val1 = populacao_1;
            val2 = populacao_2;
            nome_atributo = "População";
            maior_melhor = 1; 
            break;
        case 2: // Área
            val1 = area_1;
            val2 = area_2;
            nome_atributo = "Área";
            maior_melhor = 1; 
            break;
        case 3: // PIB
            val1 = pib_1;
            val2 = pib_2;
            nome_atributo = "PIB";
            maior_melhor = 1; 
            break;
        case 4: // Densidade Demográfica (Regra: MENOR VENCE)
            val1 = densidade_1 * 1000.0;
            val2 = densidade_2 * 1000.0;
            nome_atributo = "Densidade Demográfica";
            maior_melhor = 0; // MENOR valor vence
            break;
        case 5: // Super Poder
            val1 = super_poder_1;
            val2 = super_poder_2;
            nome_atributo = "Super Poder";
            maior_melhor = 1; 
            break;
        default:
            printf("Erro na seleção do atributo.\n");
            return;
    }

    // 2. COMPARAÇÃO ANINHADA: Lógica principal de decisão
    if (val1 == val2) {
        printf("EMPATE no atributo %s.\n", nome_atributo);
        
        // Exemplo de Comparação Aninhada: Se empatar, compara o próximo atributo (Turisticos)
        printf("Tentando desempate (Pontos Turísticos):\n");
        if (turisticos_1 > turisticos_2) {
            printf(" -> DESEMPATE VENCEDOR: Carta 1 (%s)\n", nome_cidade_1);
        } else if (turisticos_2 > turisticos_1) {
            printf(" -> DESEMPATE VENCEDOR: Carta 2 (%s)\n", nome_cidade_2);
        } else {
            printf(" -> EMPATE FINAL.\n");
        }
        
    } else {
        // Se houver vencedor direto
        
        int carta1_vence;
        
        // Determina quem venceu com base na regra (maior ou menor é melhor)
        if (maior_melhor == 1) {
            carta1_vence = val1 > val2; // Maior é melhor
        } else { // maior_melhor == 0
            carta1_vence = val1 < val2; // Menor é melhor (para Densidade)
        }
        
        // Exibe o vencedor
        if (carta1_vence) {
            printf("VENCEDOR na rodada (%s): Carta 1 (%s) com %.2f\n", 
                   nome_atributo, nome_cidade_1, val1);
        } else {
            printf("VENCEDOR na rodada (%s): Carta 2 (%s) com %.2f\n", 
                   nome_atributo, nome_cidade_2, val2);
        }
    }
}


// ===========================================
// FUNÇÃO PRINCIPAL
// ===========================================
int main() {
    

    // 1. Cadastro dos Dados (Chamada única)
    cadastrar_cartas();

    // 2. Menu Interativo (Loop principal do jogo)
    while (opcao_menu != 0) {
        printf("\n================ MENU DE BATALHA ================\n");
        printf("Escolha o atributo para comparação:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Densidade Demográfica\n");
        printf("5 - Super Poder\n");
        printf("0 - Sair\n");
        printf("Opção: ");

        if (scanf("%d", &opcao_menu) != 1) {
            printf("\nOpção inválida! Digite um número.\n");
            // Limpeza do buffer (Necessário por causa do scanf)
            while (getchar() != '\n'); 
            continue;
        }

        // SWITCH: Processa a escolha do usuário
        switch (opcao_menu) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                comparar_cartas(opcao_menu);
                break;
            case 0:
                printf("\nEncerrando o jogo. Obrigado por jogar!\n");
                break;
            default:
                printf("\nOpção inválida! Escolha um número de 0 a 5.\n");
                break;
        }
    }

    return 0;
}