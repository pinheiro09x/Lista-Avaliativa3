#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto {
    int codigo;
    char descricao[50];
    int quantidade;
    float valor;
};

void inicializarEstoque(Produto estoque[], int *quantidadeProdutos) {
    *quantidadeProdutos = 0;
}

void adicionarProduto(Produto estoque[], int *quantidadeProdutos) {
    Produto novoProduto;

    printf("Digite o codigo do produto: ");
    scanf("%d", &novoProduto.codigo);
    printf("Digite a descricao do produto: ");
    scanf("%s", novoProduto.descricao);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &novoProduto.quantidade);
    printf("Digite o valor do produto: ");
    scanf("%f", &novoProduto.valor);

    estoque[*quantidadeProdutos] = novoProduto;
    (*quantidadeProdutos)++;

    printf("Produto adicionado com sucesso!\n");
}

void gerarRelatorio(Produto estoque[], int quantidadeProdutos) {
    printf("\nRelatorio de Estoque:\n");
    printf("Codigo | Descricao | Quantidade | Valor\n");

    for (int i = 0; i < quantidadeProdutos; i++) {
        printf("%d | %s | %d | %.2f\n", estoque[i].codigo, estoque[i].descricao, estoque[i].quantidade, estoque[i].valor);
    }
}

void consultarProduto(Produto estoque[], int quantidadeProdutos) {
    int codigoConsulta;
    printf("Digite o codigo do produto a ser consultado: ");
    scanf("%d", &codigoConsulta);

    for (int i = 0; i < quantidadeProdutos; i++) {
        if (estoque[i].codigo == codigoConsulta) {
            printf("Produto encontrado:\n");
            printf("Codigo | Descricao | Quantidade | Valor\n");
            printf("%d | %s | %d | %.2f\n", estoque[i].codigo, estoque[i].descricao, estoque[i].quantidade, estoque[i].valor);
            return;
        }
    }

    printf("Produto nao encontrado.\n");
}

void removerProduto(Produto estoque[], int *quantidadeProdutos) {
    int codigoRemocao;
    printf("Digite o codigo do produto a ser removido: ");
    scanf("%d", &codigoRemocao);

    for (int i = 0; i < *quantidadeProdutos; i++) {
        if (estoque[i].codigo == codigoRemocao) {
            for (int j = i; j < *quantidadeProdutos - 1; j++) {
                estoque[j] = estoque[j + 1];
            }
            (*quantidadeProdutos)--;
            printf("Produto removido com sucesso!\n");
            return;
        }
    }

    printf("Produto nao encontrado.\n");
}

int main() {
    Produto estoque[100];  
    int quantidadeProdutos;

    inicializarEstoque(estoque, &quantidadeProdutos);

    int opcao;
    do {
        printf("\n===== Menu =====\n");
        printf("1. Adicionar Produto\n");
        printf("2. Consultar Produto\n");
        printf("3. Gerar Relatorio\n");
        printf("4. Remover Produto\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(estoque, &quantidadeProdutos);
                break;
            case 2:
                consultarProduto(estoque, quantidadeProdutos);
                break;
            case 3:
                gerarRelatorio(estoque, quantidadeProdutos);
                break;
            case 4:
                removerProduto(estoque, &quantidadeProdutos);
                break;
            case 5:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}