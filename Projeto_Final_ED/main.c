#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "proj.h"

int main(){
    setlocale(LC_ALL, "Portuguese");
    int opcao, cod, x, ordem, n = 0;
    char nome[50];
    CAD cl;
    FILE *f;
    Lista *li;
    li=cria_lista();
    //O arquivo é aberto em modo leitura binaria se houver conteudo nele este conteudo é inserido na lista se não o arquivo é apenas fechado
    f = fopen("Clientes.bin", "rb");
     if(f !=NULL){
        while(!feof(f)){
            n = fread(&cl,sizeof(CAD),1,f);
            if(n == 1){
                insere_contato(li,cl);
            }
        }
     }
     fclose(f);
    do{
        // O menu consiste em 9 opçoes sendo as 7 primeiras para exibir ou alterar a lista e as 2 ultimas para encerrar o progama salvando ou não as alterações feitas
        printf("[1] - Inserir novo cliente\n[2] - Gerar relatório total\n[3] - Gerar relatório individual\n[4] - Gerar relatório por nome\n\[5] - Tamanho da lista\n[6] - Editar dados do contato\n[7] - Remoção de contato\n[8] - Salvar alterações e sair\n[9] - Sair sem salvar alteracões\nDigite a opção: ");
        scanf ("%d", &opcao);
        system("cls");
        switch (opcao){
            case 1:
                system("cls");
                printf("\t================================\n\t=== INSERÇÃO DE NOVO CONTATO ===\n\t================================\n");
                cl = cadastro(li);
                insere_contato(li, cl);
                if(x){
                    printf("\nContato inserido com sucesso.\n\n");
                }else{
                    printf("\nErro! Contato nao inserido.\n\n");
                }
                system("pause");
                system("cls");
            break;
            case 2:
                system("cls");
                printf("\t============================\n\t=== GERAÇÃO DE RELATÓRIO ===\n\t============================\n");
                printf("[1] - Exibir em ordem crescente\n[2] - Exibir em ordem decrescente\n[3] - Voltar\nDigite a opção: ");
                scanf("%d", &ordem);
                switch(ordem){
                    case 1:
                    x = exibe_relatorio_cres(li);
                    if(x){
                        printf("\n\n");
                    }else{
                        printf("\nA lista está vazia\n");
                    }
                    system("pause");
                    system("cls");
                    break;
                    case 2:
                    x =exibe_relatorio_decres(li);
                    if(x){
                        printf("\n\n");
                    }else{
                        printf("\nA lista está vazia\n");
                    }
                    system("pause");
                    system("cls");
                    break;
                default: ;
                system("cls");
                }

            break;
            case 3:
                system("cls");
                printf("\t=======================================\n\t=== GERAÇÃO DE RELATÓRIO INDIVIDUAL ===\n\t=======================================\n");
                printf("Digite o código a ser buscado: ");
                scanf("%d", &cod);
                x = busca_codigo(li, cod);
                if(x){
                    printf("\n\n");
                }else{
                    printf("\nErro ao consultar, código inválido.\n\n");
                }
                system("pause");
                system("cls");
            break;
            case 4:
                system("cls");
                printf("\t=====================================\n\t=== GERAÇÃO DE RELATÓRIO POR NOME ===\n\t=====================================\n");
                printf("Digite o nome a ser buscado: ");
                fflush(stdin);
                gets(nome);
                x = busca_nome(li,nome);
                if(x){
                    printf("\n\n");
                }else{
                    printf("\nErro ao consultar, nome inválido.\n\n");
                }
                system("pause");
                system("cls");
            break;
            case 5: system("cls");
                printf("\t========================\n\t=== TAMANHO DA LISTA ===\n\t========================\n");
                x = tamanho_lista(li);
                printf("Tamanho da lista é: %d\n", x);
                system("pause");
                system("cls");
            break;
            case 6: system("cls");
                printf("\t=========================\n\t=== EDIÇÃO DE CONTATO ===\n\t=========================\n");
                printf("Digite o código do contato a ser editado: ");
                scanf("%d", &cod);
                x = edita_contato(li, cod);
                if(x){
                    printf("\n\n");
                }else{
                    printf("\nErro ao editar, código inválido.\n\n");
                }
                system("pause");
                system("cls");
            break;
            case 7: system("cls");
                printf("\t==========================\n\t=== REMOÇÃO DE CONTATO ===\n\t==========================\n");
                printf("Digite o código do contato a ser removido: ");
                scanf("%d", &cod);
                x = remove_contato(li,cod);
                if(x){
                    printf("\nContato removido com sucesso !\n\n");
                }else{
                    printf("\nErro ao remover contato.\n\n");
                }
                system("pause");
                system("cls");
            break;
            case 8: //o arquivo é aberto em modo escrita binaria para que os elementos da lista sejam salvos nele
                    f = fopen("Clientes.bin", "wb");
                    grava_arquivo(li, f);
                    fclose(f);
            break;
        default: ;
        }
    }while(opcao != 8 && opcao != 9);
    apaga_lista(li);
    return 0;
}
