#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ITENS 100;
FILE* fptr;
typedef struct contactInfo
{

    char name[100];
    char email[100];
    char numero[15];


}info;

info list[MAX_ITENS];

int totalContatos = 0;

/*Concluido*/

void removerContato(){
    
    int found = 0;
    char removerNome[100];

    printf("Qual e o nome do contato que voce deseja remover? ");
    scanf(" %[^\n]", removerNome);

    for(int i = 0; i < totalContatos; i++)
    {

        if(strcmp(removeNome, list[i].name) == 0){
            found = 1;

            for(int j = i; j<totalContatos -1; j++){

                list[j] = list[j+1];
                totalContatos--;
                printf("Contato removido!\n");
                break;

            }
        }else
        {
            found = 0;
            printf("Contato nao encontrado!\n");
        }
    }
}



void ordenarLista(){

}

void addContato(){

}

/*Concluido*/

void editar(){
    int choice = 0;
    printf("Como voce deseja procurar pelo contato que voce deseja editar? Digite: 1 - NOME | 2 - EMAIL | 3 - NUMERO");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        char nome[100];
        printf("Digite o nome do contato: ");
        scanf(" %[^\n]", nome);
        for(i = 0; i < totalContatos; i++)
        {
            if(strcmp(nome, list[i].name) == 0)
            {
                printf("%s\n%d\n%s\n", list[i].name, list[i].numero, list[i].email);
                printf("Qual voce deseja editar? 1 -> NOME | 2 -> NUMERO | 3 -> EMAIL: ");
                int escolha = 0;
                scanf("%d", &escolha);
                if(escolha == 1)
                {
                    char nomeVar[100];
                    printf("Como sera o novo nome? ");
                    scanf(" %[^\n]", nomeVar);
                    strcpy(list[i].name, nomeVar);
                    printf("\nNome alterado com sucesso!\n");
                    break;
                }
                else if(escolha == 2)
                {
                    char numeroVar[15];
                    printf("Como sera o novo numero? ");
                    scanf(" %[^\n]", numeroVar);
                    strcpy(list[i].numero, numeroVar);
                    printf("Numero alterado com sucesso!\n");
                    break;
                }
                else if(escolha == 3)
                { 
                    char emailVar[100];
                    printf("Como sera o novo e-mail? ")
                    scanf(" %[^\n]", emailVar);
                    strcpy(list[i].email, emailVar);
                    printf("E-mail alterado com sucesso!\n");
                    break;
                }
                else
                {
                    printf("Opcao invalida!\n");
                    break;
                }
            }
        }
        break;
    
    default:
        break;
    }
}

void carregaNoTxt(){

}

void listaCompleta(){

}

/*Concluido*/

void buscaContato(){
    char searchName[100];
    int found = 0;
    printf("Qual o nome do contato que voce procura informacoes? ");
    scanf(" %[^\n]", searchName);
    for(i = 0; i<totalContatos; i++){
        if(strcmp(searchName, list[i].name) == 0){
            found = 1;
            printf("Nome: %s\nNumero: %s\nEmail: %s\n", list[i].name, list[i].numero, list[i].email);
            break;
        }else{
            printf("Nao encontramos este contato!");
            break;
        }
    }
}


int main(){
    return 0;
}
