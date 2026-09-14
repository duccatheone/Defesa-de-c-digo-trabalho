#include <stdio.h>

#define TAM 5

int main() {
    int codigos[TAM];
    int quantidades[TAM];
    float precos[TAM];

    int total_produtos = 0;
    int cadastrado = 0;
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

        // Opcao 1: cadastro dos produtos
        if (opcao == 1) {

            printf("\n--- Cadastramento de Produtos ---\n");

            // Verifica se o limite de produtos ja foi atingido
            if (total_produtos == TAM) {
                printf("\nErro: O estoque ja possui %d produtos cadastrados.\n", TAM);
            } else {

                int quantidade_cadastro;

                printf("Quantos produtos deseja cadastrar? ");
                scanf("%d", &quantidade_cadastro);

                // Verifica se a quantidade informada e valida
                if (quantidade_cadastro < 1) {
                    printf("\nErro: Cadastre pelo menos 1 produto.\n");

                } else if (quantidade_cadastro > TAM - total_produtos) {
                    printf("\nErro: Voce pode cadastrar no maximo %d produto(s) agora.\n",
                           TAM - total_produtos);

                } else {

                    // Cadastro dos produtos
                    for (i = 0; i < quantidade_cadastro; i++) {

                        int codigo_repetido;

                        printf("\nProduto %d:\n", total_produtos + 1);

                        // Verifica se o codigo ja esta cadastrado
                        do {
                            codigo_repetido = 0;

                            printf("Digite o codigo (ID numerico): ");
                            scanf("%d", &codigos[total_produtos]);

                            // Busca o codigo nos produtos ja cadastrados
                            for (int j = 0; j < total_produtos; j++) {
                                if (codigos[j] == codigos[total_produtos]) {
                                    codigo_repetido = 1;
                                    break;
                                }
                            }

                            if (codigo_repetido) {
                                printf("Erro: Esse codigo ja esta cadastrado. "
                                       "Digite outro.\n");
                            }

                        } while (codigo_repetido);

                        printf("Digite a quantidade em estoque: ");
                        scanf("%d", &quantidades[total_produtos]);

                        printf("Digite o preco unitario: ");
                        scanf("%f", &precos[total_produtos]);

                        total_produtos++;
                    }

                    cadastrado = 1;

                    printf("\nCadastro concluido com sucesso!\n");
                }
            }

        // Opcao 2: busca de produto
        } else if (opcao == 2) {

            // Verifica se existem produtos cadastrados
            if (!cadastrado) {
                printf("\nErro: Nenhum produto cadastrado ainda!\n");

            } else {
                int codigo_busca;
                int encontrado = 0;

                printf("\n--- Busca de Produto ---\n");
                printf("Digite o codigo do produto procurado: ");
                scanf("%d", &codigo_busca);

                // Busca linear no vetor de codigos
                for (i = 0; i < total_produtos; i++) {

                    if (codigos[i] == codigo_busca) {
                        printf("\n[PRODUTO ENCONTRADO]\n");
                        printf("Codigo: %d\n", codigos[i]);
                        printf("Quantidade: %d unidades\n", quantidades[i]);
                        printf("Preco Unitario: R$ %.2f\n", precos[i]);

                        // Calcula o valor total do produto em estoque
                        printf("Valor Total em Estoque: R$ %.2f\n",
                               quantidades[i] * precos[i]);

                        encontrado = 1;
                        break;
                    }
                }

                // Caso nenhum produto seja encontrado
                if (!encontrado) {
                    printf("\nProduto com codigo %d nao foi encontrado.\n",
                           codigo_busca);
                }
            }

        // Opcao 3: relatorio e estatisticas
        } else if (opcao == 3) {

            // Verifica se existem produtos cadastrados
            if (!cadastrado) {
                printf("\nErro: Nenhum produto cadastrado ainda!\n");

            } else {
                float valor_total_estoque = 0;
                int indice_mais_caro = 0;

                // Processa somente os produtos cadastrados
                for (i = 0; i < total_produtos; i++) {

                    // Soma o valor de todos os produtos
                    valor_total_estoque +=
                        quantidades[i] * precos[i];

                    // Procura o maior preco unitario
                    if (precos[i] > precos[indice_mais_caro]) {
                        indice_mais_caro = i;
                    }
                }

                printf("\n--- RELATORIO GERAL E ESTATISTICAS ---\n");
                printf("Total de produtos cadastrados: %d\n", total_produtos);

                printf("Valor total acumulado no estoque: R$ %.2f\n",
                       valor_total_estoque);

                printf("Produto de maior valor unitario: "
                       "Codigo %d (R$ %.2f)\n",
                       codigos[indice_mais_caro],
                       precos[indice_mais_caro]);
            }

        // Opcao invalida
        } else if (opcao != 4) {
            printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 4);

    printf("\nPrograma encerrado.\n");

    return 0;
