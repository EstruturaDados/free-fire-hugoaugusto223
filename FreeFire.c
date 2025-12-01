#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 10

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

void inserirItem(Item mochila[], int *tamanho);
void removerItem(Item mochila[], int *tamanho);
void listarItens(Item mochila[], int tamanho);
void buscarItem(Item mochila[], int tamanho);

int main() {
    Item mochila[MAX_ITENS];
    int tamanho = 0;
    int opcao;

    do {
        printf("\n====== MOCHILA DO SOBREVIVENTE (NÍVEL NOVATO) ======\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Buscar item\n");
        printf("4 - Listar itens\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                inserirItem(mochila, &tamanho);
                break;
            case 2:
                removerItem(mochila, &tamanho);
                break;
            case 3:
                buscarItem(mochila, tamanho);
                break;
            case 4:
                listarItens(mochila, tamanho);
                break;
            case 0:
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}

void inserirItem(Item mochila[], int *tamanho) {
    if (*tamanho >= MAX_ITENS) {
        printf("\nERRO: A mochila está cheia!\n");
        return;
    }

    printf("\n--- Inserir novo item ---\n");
    printf("Nome do item: ");
    scanf("%s", mochila[*tamanho].nome);

    printf("Tipo do item: ");
    scanf("%s", mochila[*tamanho].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochila[*tamanho].quantidade);

    (*tamanho)++;
    printf("Item adicionado com sucesso!\n");
}

void removerItem(Item mochila[], int *tamanho) {
    if (*tamanho == 0) {
        printf("\nA mochila está vazia.\n");
        return;
    }

    char nomeRemover[30];
    printf("\nNome do item a remover: ");
    scanf("%s", nomeRemover);

    for (int i = 0; i < *tamanho; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            for (int j = i; j < (*tamanho) - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            (*tamanho)--;
            printf("Item removido com sucesso!\n");
            return;
        }
    }

    printf("Item não encontrado.\n");
}

void buscarItem(Item mochila[], int tamanho) {
    if (tamanho == 0) {
        printf("\nA mochila está vazia.\n");
        return;
    }

    char nomeBusca[30];
    printf("\nNome do item para buscar: ");
    scanf("%s", nomeBusca);

    for (int i = 0; i < tamanho; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\nItem encontrado!\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            return;
        }
    }

    printf("Item não encontrado.\n");
}

void listarItens(Item mochila[], int tamanho) {
    printf("\n--- Itens na mochila ---\n");

    if (tamanho == 0) {
        printf("A mochila está vazia.\n");
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        printf("\nItem %d:\n", i + 1);
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d\n", mochila[i].quantidade);
    }
}
