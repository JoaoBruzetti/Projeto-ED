#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "proj.h"

struct elemento{
    CAD dados;
    struct elemento *prox, *ant;
};

typedef struct elemento ELEM;

Lista cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

CAD cadastro(Lista *li){
    CAD cl;
    int codigo =1;
    while(cria_codigo(li, codigo) == 1){
        codigo++;
    }
    cl.cod = codigo;
    printf("Seu codigo é: %d\n", cl.cod);
    fflush(stdin);
    printf("Digite seu nome: ");
    gets(cl.nome);
    fflush(stdin);
    printf("Digite o nome da sua empresa: ");
    gets(cl.emp);
    fflush(stdin);
    printf("Digite o nome do departamento a que pertence: ");
    gets(cl.dep);
    fflush(stdin);
    printf("Digite seu número de telefone: ");
    gets(cl.tel);
    fflush(stdin);
    printf("Digite seu número de celular: ");
    gets(cl.cel);
    return cl;
}

int cria_codigo(Lista *li, int cod){
    ELEM *no= *li;
    while(no != NULL && no->dados.cod != cod){
        no=no->prox;
    }
    if(no != NULL){
        return 1;
    }else{
    return 0;
    }
}

int insere_contato(Lista *li, CAD cl){
    if(li == NULL){
            return 0;
        }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }
    no->dados = cl;
    if(*li == NULL){
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return 1;
    }else{
        ELEM *anterior, *atual=*li;
        while(atual != NULL && atual->dados.cod < cl.cod){
            anterior = atual;
            atual= atual->prox;
        }
        if(atual == *li){
            no->ant = NULL;
            (*li)->ant=no;
            no->prox=(*li);
            *li = no;
        }else{
            no->prox = anterior->prox;
            no->ant = anterior;
            anterior->prox = no;
            if(atual != NULL){
                atual->ant = no;
            }
        }
    }
    return 1;
}

int exibe_relatorio_cres(Lista *li){
    int cont =0;
    if(li == NULL || *li == NULL){
        return 0;
    }
    ELEM *no = *li;
    while(no != NULL){
        printf("======================\n\n");
        printf("Codigo: %d\nNome: %s\nEmpresa: %s\nDepartamento: %s\nTelefone: %s\nCelular: %s\n\n", no->dados.cod, no->dados.nome, no->dados.emp, no->dados.dep, no->dados.tel, no->dados.cel );
        no = no->prox;
        cont++;
        system("pause");
    }
    if(cont != 0){
    return 1;
    }else{
     return 0;
    }
}

int exibe_relatorio_decres(Lista *li){
    int cont=0;
    if(li == NULL || *li == NULL){
        return 0;
    }
    ELEM *no = *li;
    while(no->prox != NULL){
        no=no->prox;
    }
    while(no != NULL){
        printf("======================\n\n");
        printf("Codigo: %d\nNome: %s\nEmpresa: %s\nDepartamento: %s\nTelefone: %s\nCelular: %s\n\n", no->dados.cod, no->dados.nome, no->dados.emp, no->dados.dep, no->dados.tel, no->dados.cel );
        cont++;
        system("pause");
        no = no->ant;
    }
    if(cont !=0){
    return 1;
    }else{
     return 0;
    }
}

int  busca_codigo(Lista *li, int cod){
    if(li == NULL){
        return 0;
    }
    ELEM *no = *li;
    while(no != NULL && no->dados.cod != cod){
        no=no->prox;
    }
    if(no == NULL){
        return 0;
    }else{
        printf("======================\n\n");
        printf("Codigo: %d\nNome: %s\nEmpresa: %s\nDepartamento: %s\nTelefone: %s\nCelular: %s", no->dados.cod, no->dados.nome, no->dados.emp, no->dados.dep, no->dados.tel, no->dados.cel );
     return 1;
    }
}

int busca_nome(Lista *li, char nome[50]){
    int cont=0;
     if(li == NULL || *li == NULL){
        return 0;
    }
    ELEM *no = *li;
    while(no != NULL ){
            if(strncmp(no->dados.nome, nome, strlen(nome)) == 0){
            printf("======================\n\n");
            printf("Codigo: %d\nNome: %s\nEmpresa: %s\nDepartamento: %s\nTelefone: %s\nCelular: %s\n\n", no->dados.cod, no->dados.nome, no->dados.emp, no->dados.dep, no->dados.tel, no->dados.cel );
            system("pause");
            cont++;
            }
        no=no->prox;
    }
    if(cont != 0){
        return 1;
    }else{
        return 0;
    }
}

int tamanho_lista(Lista *li){
    if(li == NULL){
        return 0;
    }
    int cont=0;
    ELEM *no = *li;
    while(no != NULL){
        cont++;
        no= no->prox;
    }
    return cont;
}

int edita_contato(Lista *li, int cod){
    if(li == NULL){
            return 0;
        }
    int opc, opc2;
    char novo[50];
    ELEM *no = *li;
    while(no != NULL && no->dados.cod != cod){
            no=no->prox;
        }
    if(no == NULL){
        return 0;
    }
    CAD cl;
    do{
        printf("\n\n======== INFORMAÇOES DO CONTATO =============\n\n");
        printf("Codigo: %d\nNome: %s\nEmpresa: %s\nDepartamento: %s\nTelefone: %s\nCelular: %s\n\n", no->dados.cod, no->dados.nome, no->dados.emp, no->dados.dep, no->dados.tel, no->dados.cel );
        printf("[1] - Alterar nome\n[2] - Alterar empresa\n[3] - Alterar departamento\n[4] - Alterar telefone\n[5] - Alterar celular\n[6] - Voltar\nDigite a opção: ");
        scanf("%d", &opc);
        switch(opc){
          case 1:system("cls");
            printf("Digite o novo nome: ");
            fflush(stdin);
            gets(novo);
            printf("\nAntigo nome: %s\n\nNovo nome: %s\n",no->dados.nome, novo );
            printf("\t\t\n=================== OPÇÕES ======================\n[1] - Efetuar troca de dados \n[2] - Cancelar troca de dados\nDigite a opção: ");
            scanf("%d", &opc2);
           if(opc2 == 1){
            strcpy(no->dados.nome, novo);
            }
            system("pause");
            system("cls");
            break;
         case 2:system("cls");
            printf("Digite o novo nome da empresa: ");
            fflush(stdin);
            gets(novo);
            printf("\nAntigo nome da empresa: %s\n\nNovo nome da empresa: %s\n",no->dados.emp, novo );
            printf("\t\t\n=================== OPÇÕES ======================\n[1] - Efetuar troca de dados \n[2] - Cancelar troca de dados\nDigite a opção: ");
            scanf("%d", &opc2);
           if(opc2 == 1){
            strcpy(no->dados.emp, novo);
            }
            system("pause");
            system("cls");
            break;
            case 3:system("cls");
            printf("Digite o novo nome do departamento: ");
            fflush(stdin);
            gets(novo);
            printf("\nAntigo nome do departamento: %s\n\nNovo nome do departamento: %s\n",no->dados.dep, novo );
            printf("\t\t\n=================== OPÇÕES ======================\n[1] - Efetuar troca de dados \n[2] - Cancelar troca de dados\nDigite a opção: ");
            scanf("%d", &opc2);
           if(opc2 == 1){
            strcpy(no->dados.dep, novo);
            }
            system("pause");
            system("cls");
            break;
            case 4:system("cls");
            printf("Digite o novo número de telefone: ");
            fflush(stdin);
            gets(novo);
            printf("\nAntigo número de telefone: %s\n\nNovo número de telefone: %s\n",no->dados.tel, novo );
            printf("\t\t\n=================== OPÇÕES ======================\n[1] - Efetuar troca de dados \n[2] - Cancelar troca de dados\nDigite a opção: ");
            scanf("%d", &opc2);
           if(opc2 == 1){
            strncpy(no->dados.tel,  novo,10);
            }
            system("pause");
            system("cls");
            break;
            case 5:system("cls");
            printf("Digite o novo celular: ");
            fflush(stdin);
            gets(novo);
            printf("\nAntigo número de celular: %s\n\nNovo número de celular: %s\n",no->dados.cel, novo );
            printf("\t\t\n=================== OPÇÕES ======================\n[1] - Efetuar troca de dados \n[2] - Cancelar troca de dados\nDigite a opção: ");
            scanf("%d", &opc2);
           if(opc2 == 1){
            strncpy(no->dados.cel, novo, 10);
            }
            system("pause");
            system("cls");
            break;
        }
    }while(opc != 6);
    return 1;
}

int remove_contato(Lista *li, int cod){
    if(li == NULL){
        return 0;
    }
    ELEM *no = *li;
    int opc;
    while(no!= NULL && no->dados.cod != cod){
        no=no->prox;
    }
    if(no == NULL){
        return 0;
    }
    printf("\n\n======== INFORMAÇOES DO CONTATO =============\n\n");
    printf("Codigo: %d\nNome: %s\nEmpresa: %s\nDepartamento: %s\nTelefone: %s\nCelular: %s\n\n", no->dados.cod, no->dados.nome, no->dados.emp, no->dados.dep, no->dados.tel, no->dados.cel );
    printf("\t\t\n=================== OPÇÕES ======================\n[1] - Excluir Contato \n[2] - Cancelar exclusão do contato \nDigite a opção: ");
    scanf("%d", &opc);
    if( opc == 1){
    if(no->ant == NULL){
        *li = no->prox;
    }else{
     no->ant->prox = no->prox;
    }
    if(no->prox != NULL){
        no->prox->ant = no->ant;
    }
    free(no);
    return 1;
    }else{
        return 0;
    }
}

void grava_arquivo(Lista *li, FILE *f){
    ELEM *no= *li;
     while(no !=NULL){
        fwrite(&no->dados, sizeof(CAD),1,f);
        no = no->prox;
    }
}

void apaga_lista(Lista *li){
    if(li != NULL){
        ELEM *no;
        while((*li)!=NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}
