#include <stdio.h>

// Definição da estrutura para representar uma carta
struct Carta {
    char estado[30];
    char sigla_estado[3]; 
    int codigo;
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
};

int main() {
    // Cadastro de duas cartas com dados reais e pontos turísticos arbitrários
    // Dados de 2022/2023 (aproximados):
    // São Paulo: população 11.451.245, área 1521.11 km², PIB per capita ~R$ 60.000, pontos turísticos: 35
    // Rio de Janeiro: população 6.211.423, área 1182.30 km², PIB per capita ~R$ 55.000, pontos turísticos: 28
    struct Carta carta1 = {
        "São Paulo", "SP", 1, "São Paulo",
        11451245, 1521.11, 687000000000.0, 35, 0, 0
    };
    struct Carta carta2 = {
        "Rio de Janeiro", "RJ", 2, "Rio de Janeiro",
        6211423, 1182.30, 342000000000.0, 28, 0, 0
    };

    // Cálculo da densidade populacional e PIB per capita para cada carta
    carta1.densidade_populacional = carta1.populacao / carta1.area;
    carta2.densidade_populacional = carta2.populacao / carta2.area;
    carta1.pib_per_capita = carta1.pib / carta1.populacao;
    carta2.pib_per_capita = carta2.pib / carta2.populacao;

    // Escolha do atributo para comparação
    // 1 - População, 2 - Área, 3 - PIB, 4 - Densidade Populacional, 5 - PIB per capita
    int atributo = 4; // Altere este valor para comparar outro atributo

    float valor1, valor2;
    char atributo_nome[30];
    switch (atributo) {
        case 1:
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            sprintf(atributo_nome, "População");
            break;
        case 2:
            valor1 = carta1.area;
            valor2 = carta2.area;
            sprintf(atributo_nome, "Área");
            break;
        case 3:
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            sprintf(atributo_nome, "PIB");
            break;
        case 4:
            valor1 = carta1.densidade_populacional;
            valor2 = carta2.densidade_populacional;
            sprintf(atributo_nome, "Densidade Populacional");
            break;
        case 5:
            valor1 = carta1.pib_per_capita;
            valor2 = carta2.pib_per_capita;
            sprintf(atributo_nome, "PIB per capita");
            break;
        default:
            printf("Atributo inválido!\n");
            return 1;
    }

    // Comparação das cartas usando if/else conforme a regra do desafio
    printf("Comparando o atributo: %s\n", atributo_nome);
    printf("%s: %.2f\n", carta1.nome_cidade, valor1);
    printf("%s: %.2f\n", carta2.nome_cidade, valor2);

    if (atributo == 4) { // Para densidade populacional, vence o menor valor
        if (valor1 < valor2) {
            printf("\nVencedor: %s (%s)\n", carta1.nome_cidade, carta1.sigla_estado);
        } else if (valor2 < valor1) {
            printf("\nVencedor: %s (%s)\n", carta2.nome_cidade, carta2.sigla_estado);
        } else {
            printf("\nEmpate!\n");
        }
    } else { // Para os demais atributos, vence o maior valor
        if (valor1 > valor2) {
            printf("\nVencedor: %s (%s)\n", carta1.nome_cidade, carta1.sigla_estado);
        } else if (valor2 > valor1) {
            printf("\nVencedor: %s (%s)\n", carta2.nome_cidade, carta2.sigla_estado);
        } else {
            printf("\nEmpate!\n");
        }
    }

    return 0;
}

// empty commit
