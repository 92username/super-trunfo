// super_trunfo_aventureiro.c
// Desafio Super Trunfo - Nível Aventureiro
// Implementação de menu interativo e comparação entre duas cartas

#include <stdio.h>
#include <string.h>

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
};

int main() {
    // Cadastro das cartas (dados de 2022/2023)
    struct Carta carta1 = {
        "São Paulo", "SP", 1, "São Paulo",
        11451245, 1521.11, 687000000000.0, 35, 0
    };
    struct Carta carta2 = {
        "Rio de Janeiro", "RJ", 2, "Rio de Janeiro",
        6211423, 1182.30, 342000000000.0, 28, 0
    };

    // Cálculo da densidade populacional
    carta1.densidade_populacional = carta1.populacao / carta1.area;
    carta2.densidade_populacional = carta2.populacao / carta2.area;

    int opcao;
    int sair = 0;
    while (!sair) {
        printf("\n=== Super Trunfo - Nível Aventureiro ===\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turísticos\n");
        printf("5 - Densidade Demográfica\n");
        printf("0 - Sair\n");
        printf("Escolha o atributo para comparar: ");
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida!\n");
            while (getchar() != '\n'); // Limpa buffer
            continue;
        }

        float valor1 = 0, valor2 = 0;
        char atributo_nome[40] = "";
        int empate = 0, vencedor = 0;

        switch (opcao) {
            case 1:
                valor1 = carta1.populacao;
                valor2 = carta2.populacao;
                strcpy(atributo_nome, "População");
                break;
            case 2:
                valor1 = carta1.area;
                valor2 = carta2.area;
                strcpy(atributo_nome, "Área");
                break;
            case 3:
                valor1 = carta1.pib;
                valor2 = carta2.pib;
                strcpy(atributo_nome, "PIB");
                break;
            case 4:
                valor1 = carta1.pontos_turisticos;
                valor2 = carta2.pontos_turisticos;
                strcpy(atributo_nome, "Pontos Turísticos");
                break;
            case 5:
                valor1 = carta1.densidade_populacional;
                valor2 = carta2.densidade_populacional;
                strcpy(atributo_nome, "Densidade Demográfica");
                break;
            case 0:
                sair = 1;
                printf("Saindo...\n");
                continue;
            default:
                printf("Opção inválida!\n");
                continue;
        }

        printf("\nComparando o atributo: %s\n", atributo_nome);
        printf("%s: %.2f\n", carta1.nome_cidade, valor1);
        printf("%s: %.2f\n", carta2.nome_cidade, valor2);

        // Lógica de comparação
        if (opcao == 5) { // Densidade: menor vence
            if (valor1 < valor2) vencedor = 1;
            else if (valor2 < valor1) vencedor = 2;
            else empate = 1;
        } else { // Demais: maior vence
            if (valor1 > valor2) vencedor = 1;
            else if (valor2 > valor1) vencedor = 2;
            else empate = 1;
        }

        if (empate) {
            printf("\nEmpate!\n");
        } else if (vencedor == 1) {
            printf("\nVencedor: %s (%s)\n", carta1.nome_cidade, carta1.sigla_estado);
        } else if (vencedor == 2) {
            printf("\nVencedor: %s (%s)\n", carta2.nome_cidade, carta2.sigla_estado);
        }
    }
    return 0;
}
