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
    //O arquivo � aberto em modo leitura binaria se houver conteudo nele este conteudo � inserido na lista se n�o o arquivo � apenas fechado
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
        // O menu consiste em 9 op�oes sendo as 7 primeiras para exibir ou alterar a lista e as 2 ultimas para encerrar o progama salvando ou n�o as altera��es feitas
        printf("[1] - Inserir novo cliente\n[2] - Gerar relat�rio total\n[3] - Gerar relat�rio individual\n[4] - Gerar relat�rio por nome\n\[5] - Tamanho da lista\n[6] - Editar dados do contato\n[7] - Remo��o de contato\n[8] - Salvar altera��es e sair\n[9] - Sair sem salvar alterac�es\nDigite a op��o: ");
        scanf ("%d", &opcao);
        system("cls");
        switch (opcao){
            case 1:
                system("cls");
                printf("\t================================\n\t=== INSER��O DE NOVO CONTATO ===\n\t================================\n");
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
                printf("\t============================\n\t=== GERA��O DE RELAT�RIO ===\n\t============================\n");
                printf("[1] - Exibir em ordem crescente\n[2] - Exibir em ordem decrescente\n[3] - Voltar\nDigite a op��o: ");
                scanf("%d", &ordem);
                switch(ordem){
                    case 1:
                    x = exibe_relatorio_cres(li);
                    if(x){
                        printf("\n\n");
                    }else{
                        printf("\nA lista est� vazia\n");
                    }
                    system("pause");
                    system("cls");
                    break;
                    case 2:
                    x =exibe_relatorio_decres(li);
                    if(x){
                        printf("\n\n");
                    }else{
                        printf("\nA lista est� vazia\n");
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
                printf("\t=======================================\n\t=== GERA��O DE RELAT�RIO INDIVIDUAL ===\n\t=======================================\n");
                printf("Digite o c�digo a ser buscado: ");
                scanf("%d", &cod);
                x = busca_codigo(li, cod);
                if(x){
                    printf("\n\n");
                }else{
                    printf("\nErro ao consultar, c�digo inv�lido.\n\n");
                }
                system("pause");
                system("cls");
            break;
            case 4:
                system("cls");
                printf("\t=====================================\n\t=== GERA��O DE RELAT�RIO POR NOME ===\n\t=====================================\n");
                printf("Digite o nome a ser buscado: ");
                fflush(stdin);
                gets(nome);
                x = busca_nome(li,nome);
                if(x){
                    printf("\n\n");
                }else{
                    printf("\nErro ao consultar, nome inv�lido.\n\n");
                }
                system("pause");
                system("cls");
            break;
            case 5: system("cls");
                printf("\t========================\n\t=== TAMANHO DA LISTA ===\n\t========================\n");
                x = tamanho_lista(li);
                printf("Tamanho da lista �: %d\n", x);
                system("pause");
                system("cls");
            break;
            case 6: system("cls");
                printf("\t=========================\n\t=== EDI��O DE CONTATO ===\n\t=========================\n");
                printf("Digite o c�digo do contato a ser editado: ");
                scanf("%d", &cod);
                x = edita_contato(li, cod);
                if(x){
                    printf("\n\n");
                }else{
                    printf("\nErro ao editar, c�digo inv�lido.\n\n");
                }
                system("pause");
                system("cls");
            break;
            case 7: system("cls");
                printf("\t==========================\n\t=== REMO��O DE CONTATO ===\n\t==========================\n");
                printf("Digite o c�digo do contato a ser removido: ");
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
            case 8: //o arquivo � aberto em modo escrita binaria para que os elementos da lista sejam salvos nele
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
