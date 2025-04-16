#include <stdio.h>
#include <string.h>

#define QTD_ATRIBUTOS 5
#define QTD_CARTAS 2
#define MAX_NOME 50

// Estrutura para representar uma carta de cidade
struct Carta {
    char estado[MAX_NOME];
    char sigla_estado[3];
    int codigo;
    char nome_cidade[MAX_NOME];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
};

void exibir_menu_atributos(int atributo_oculto) {
    printf("\nEscolha um atributo:\n");
    if (atributo_oculto != 1) printf("1. População\n");
    if (atributo_oculto != 2) printf("2. Área\n");
    if (atributo_oculto != 3) printf("3. PIB\n");
    if (atributo_oculto != 4) printf("4. Densidade Populacional\n");
    if (atributo_oculto != 5) printf("5. PIB per capita\n");
    printf("Opção: ");
}

const char* nome_atributo(int opcao) {
    switch(opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Densidade Populacional";
        case 5: return "PIB per capita";
        default: return "Desconhecido";
    }
}

float valor_atributo(struct Carta c, int opcao) {
    switch(opcao) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.densidade_populacional;
        case 5: return c.pib_per_capita;
        default: return 0;
    }
}

int ler_opcao(int atributo_oculto) {
    int opcao;
    int valido = 0;
    do {
        scanf("%d", &opcao);
        if (opcao < 1 || opcao > 5 || opcao == atributo_oculto) {
            printf("Opção inválida. Tente novamente: ");
        } else {
            valido = 1;
        }
    } while (!valido);
    return opcao;
}

int main() {
    // Cadastro das cartas (dados de 2022/2023)
    struct Carta cartas[QTD_CARTAS] = {
        {"São Paulo", "SP", 1, "São Paulo", 11451245, 1521.11, 687000000000.0, 35, 0, 0},
        {"Rio de Janeiro", "RJ", 2, "Rio de Janeiro", 6211423, 1182.30, 342000000000.0, 28, 0, 0}
    };

    // Cálculo da densidade populacional e PIB per capita
    for (int i = 0; i < QTD_CARTAS; i++) {
        cartas[i].densidade_populacional = cartas[i].populacao / cartas[i].area;
        cartas[i].pib_per_capita = cartas[i].pib / cartas[i].populacao;
    }

    int atributo1 = 0, atributo2 = 0;
    printf("=== SUPER TRUNFO MESTRE ===\n");
    printf("Comparação entre São Paulo e Rio de Janeiro!\n");

    // Escolha do primeiro atributo
    exibir_menu_atributos(0);
    atributo1 = ler_opcao(0);

    // Escolha do segundo atributo (menu dinâmico)
    printf("\nAgora escolha o segundo atributo (diferente do primeiro):\n");
    exibir_menu_atributos(atributo1);
    atributo2 = ler_opcao(atributo1);

    // Exibe cartas e valores
    printf("\nComparando:\n");
    printf("%-15s | %-20s | %-20s\n", "Cidade", nome_atributo(atributo1), nome_atributo(atributo2));
    for (int i = 0; i < QTD_CARTAS; i++) {
        printf("%-15s | %-20.2f | %-20.2f\n", cartas[i].nome_cidade, valor_atributo(cartas[i], atributo1), valor_atributo(cartas[i], atributo2));
    }

    // Comparação dos atributos
    float v1_a1 = valor_atributo(cartas[0], atributo1);
    float v2_a1 = valor_atributo(cartas[1], atributo1);
    float v1_a2 = valor_atributo(cartas[0], atributo2);
    float v2_a2 = valor_atributo(cartas[1], atributo2);

    int vencedor_a1, vencedor_a2;
    // Regra especial para Densidade Populacional (menor vence)
    vencedor_a1 = (atributo1 == 4) ? (v1_a1 < v2_a1 ? 0 : (v1_a1 > v2_a1 ? 1 : -1)) : (v1_a1 > v2_a1 ? 0 : (v1_a1 < v2_a1 ? 1 : -1));
    vencedor_a2 = (atributo2 == 4) ? (v1_a2 < v2_a2 ? 0 : (v1_a2 > v2_a2 ? 1 : -1)) : (v1_a2 > v2_a2 ? 0 : (v1_a2 < v2_a2 ? 1 : -1));

    printf("\nResultado por atributo:\n");
    printf("%s: %s\n", nome_atributo(atributo1), vencedor_a1 == -1 ? "Empate" : cartas[vencedor_a1].nome_cidade);
    printf("%s: %s\n", nome_atributo(atributo2), vencedor_a2 == -1 ? "Empate" : cartas[vencedor_a2].nome_cidade);

    // Soma dos atributos
    float soma1 = v1_a1 + v1_a2;
    float soma2 = v2_a1 + v2_a2;
    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", cartas[0].nome_cidade, soma1);
    printf("%s: %.2f\n", cartas[1].nome_cidade, soma2);

    // Resultado final
    printf("\nResultado final: ");
    if (soma1 > soma2) {
        printf("%s venceu!\n", cartas[0].nome_cidade);
    } else if (soma2 > soma1) {
        printf("%s venceu!\n", cartas[1].nome_cidade);
    } else {
        printf("Empate!\n");
    }

    printf("\nObrigado por jogar!\n");
    return 0;
}
