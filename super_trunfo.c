#include <stdio.h>
#include <locale.h>

// Estrutura que representa uma carta de paùs
typedef struct {
    char nome[40];
    int populacao;   // maior vence
    int area;        // maior vence
    int pib;         // maior vence (em milhùes de USD)
    int densidade;   // menor vence (habitantes por kmù)
} Carta;

// Funùùo para mostrar o menu de atributos (dinùmico)
void mostrarMenu(int excluir) {
    printf("\nEscolha um atributo para a comparaùùo:\n");
    if (excluir != 1) printf("1 - Populaùùo (maior vence)\n");
    if (excluir != 2) printf("2 - ùrea (maior vence)\n");
    if (excluir != 3) printf("3 - PIB (maior vence)\n");
    if (excluir != 4) printf("4 - Densidade Demogrùfica (menor vence)\n");
    printf("Sua escolha: ");
}

// Funùùo para obter o valor de um atributo
int pegarAtributo(Carta c, int opcao) {
    switch(opcao) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.densidade;
        default: return 0;
    }
}

// Funùùo para retornar o nome do atributo
const char* nomeAtributo(int opcao) {
    switch(opcao) {
        case 1: return "Populaùùo";
        case 2: return "ùrea";
        case 3: return "PIB";
        case 4: return "Densidade Demogrùfica";
        default: return "Desconhecido";
    }
}

int main() {
    setlocale(LC_ALL, "");

    // Dados atualizados (PIB em milhùes de USD)
    Carta brasil = {"Brasil", 213000000, 8516000, 2179413, 25};
    Carta japao  = {"Japùo", 125000000, 378000, 4026211, 328};

    int opcao, escolha1, escolha2;

    printf("=============================================\n");
    printf("Bem-vindo ao Super Trunfo dos Paùses!\n");
    printf("=============================================\n");

    do {
        printf("\nMenu Principal:\n");
        printf("1 - Comparar cartas (%s vs %s)\n", brasil.nome, japao.nome);
        printf("2 - Mostrar cartas\n");
        printf("3 - Sair\n");
        printf("Escolha uma opùùo: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: {
                mostrarMenu(0);
                scanf("%d", &escolha1);

                mostrarMenu(escolha1);
                scanf("%d", &escolha2);

                int valorB1 = pegarAtributo(brasil, escolha1);
                int valorJ1 = pegarAtributo(japao, escolha1);
                int valorB2 = pegarAtributo(brasil, escolha2);
                int valorJ2 = pegarAtributo(japao, escolha2);

                int pontosB = 0, pontosJ = 0;

                (escolha1 == 4) ? (valorB1 < valorJ1 ? pontosB++ : pontosJ++)
                                : (valorB1 > valorJ1 ? pontosB++ : pontosJ++);
                (escolha2 == 4) ? (valorB2 < valorJ2 ? pontosB++ : pontosJ++)
                                : (valorB2 > valorJ2 ? pontosB++ : pontosJ++);

                int somaB = valorB1 + valorB2;
                int somaJ = valorJ1 + valorJ2;

                printf("\n===== Resultado da Comparaùùo =====\n");
                printf("%s:\n - %s = %d\n - %s = %d\n - Soma = %d\n",
                       brasil.nome, nomeAtributo(escolha1), valorB1,
                       nomeAtributo(escolha2), valorB2, somaB);

                printf("\n%s:\n - %s = %d\n - %s = %d\n - Soma = %d\n",
                       japao.nome, nomeAtributo(escolha1), valorJ1,
                       nomeAtributo(escolha2), valorJ2, somaJ);

                if (somaB > somaJ) {
                    printf("\nVencedor: %s\n", brasil.nome);
                } else if (somaJ > somaB) {
                    printf("\nVencedor: %s\n", japao.nome);
                } else {
                    printf("\nEmpate!\n");
                }
                printf("===================================\n");
                break;
            }

            case 2:
                printf("\nCartas disponùveis:\n");
                printf("%s -> Populaùùo: %d | ùrea: %d | PIB: %d | Densidade: %d\n",
                       brasil.nome, brasil.populacao, brasil.area,
                       brasil.pib, brasil.densidade);
                printf("%s -> Populaùùo: %d | ùrea: %d | PIB: %d | Densidade: %d\n",
                       japao.nome, japao.populacao, japao.area,
                       japao.pib, japao.densidade);
                break;

            case 3:
                printf("Saindo do jogo... Atù a prùxima!\n");
                break;

            default:
                printf("Opùùo invùlida! Tente novamente.\n");
                break;
        }

    } while(opcao != 3);

    return 0;
}
