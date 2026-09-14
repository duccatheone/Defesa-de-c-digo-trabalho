#include <stdio.h>

#define TAM 5

int main() {
    int codigos[TAM];
    int quantidades[TAM];
    float precios[TAM];
    int total_cadastrado = 0;
    int opcao, i;

    // Menu principal
    do {
        printf("\n=== SISTEMA DE GERENCIAMENTO DE ESTOQUE ===\n");
        printf("1. Cadastrar Produtos\n");
        printf("2. Buscar Produto por Codigo\n");
        printf("3. Exibir Relatorio e Estatisticas\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("\n--- Cadastramento de Produtos ---\n");
            // Estrutura de repeticao for para preenchimento dos vetores
            for (i = 0; i < TAM; i++) {
                printf("\nProduto %d:\n", i + 1);
                printf("Digite o codigo (ID numerico): ");
                scanf("%d", &codigos[i]);
                 printf("Digite a quantidade em estoque: ");
                scanf("%d", &quantidades[i]);
                printf("Digite o preco unitario: ");
                scanf("%f", &precios[i]);
            }
            total_cadastrado = 1;
            printf("\nCadastro concluido com sucesso!\n");

        } else if (opcao == 2) {
            // Estrutura de decisao testando se ha dados cadastrados
            if (!total_cadastrado) {
                printf("\nErro: Nenhum produto cadastrado ainda!\n");
            } else {
                int codigo_busca;
                int encontrado = 0;

                printf("\n--- Busca de Produto ---\n");
                printf("Digite o codigo do produto procurado: ");
                scanf("%d", &codigo_busca);

                // Busca linear no vetor
                for (i = 0; i < TAM; i++) {
                    if (codigos[i] == codigo_busca) {
                        printf("\n[PRODUTO ENCONTRADO]\n");
                        printf("Codigo: %d\n", codigos[i]);
                        printf("Quantidade: %d unidades\n", quantidades[i]);
                        printf("Preco Unitario: R$ %.2f\n", precios[i]);
                        printf("Valor Total em Estoque: R$ %.2f\n", quantidades[i] * precios[i]);
                        encontrado = 1;
                        break;
                    }
                }

                if (!encontrado) {
                    printf("\nProduto com codigo %d nao foi encontrado.\n", codigo_busca);
                }
            }

        } else if (opcao == 3) {
            if (!total_cadastrado) {
                printf("\nErro: Nenhum produto cadastrado ainda!\n");
            } else {
                float valor_total_estoque = 0;
                int indice_mais_caro = 0;

                // Processamento de dados: soma total e busca do maior valor
                for (i = 0; i < TAM; i++) {
                    valor_total_estoque += (quantidades[i] * precios[i]);

                    if (precios[i] > precios[indice_mais_caro]) {
                        indice_mais_caro = i;
                    }
                }

                printf("\n--- RELATORIO GERAL E ESTATISTICAS ---\n");
                printf("Total de itens cadastrados: %d\n", TAM);
                printf("Valor total acumulado no estoque: R$ %.2f\n", valor_total_estoque);
                printf("Produto de maior valor unitario: Codigo %d (R$ %.2f)\n", 
                       codigos[indice_mais_caro], precios[indice_mais_caro]);
            }

        } else if (opcao != 4) {
            printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 4);

    printf("\nPrograma encerrado.\n");
    return 0;
}
