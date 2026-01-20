#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ITENS 100
FILE* fptr;
typedef struct contactInfo
{

    char name[100];
    char email[100];
    char numero[15];


}info;

info list[MAX_ITENS];
struct contactInfo info_tmp, *ptr_infos;

int totalContatos = 0;

/*Concluido*/

int info_cmp(const void *ptr1, const void *ptr2) {
    const info *info1 = ptr1;
    const info *info2 = ptr2;
    return strcmp(info1->name, info2->name);
}

/*Funcao criada para remover contato de dentro da struct*/

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
        }
    }
    if(found == 0)
    {
        printf("Contato nao encontrado!\n");
    }
}

/*Ordena a lista em ordem alfabetica*/

void ordenarLista(){
    qsort(list, totalContatos, sizeof(info), info_cmp);
    printf("Lista ordenada com sucesso!\n");
}

/*ADD: Para lista de Contatos / Coleta Infos*/

void addContato(){
    if(totalContatos>=MAX_ITENS)
    {
        printf("A lista de contatos ja esta cheia!\n");
        return;
    }
    
    ptr_infos = &list[totalContatos];

    printf("Qual sera o nome do seu contato? ");
    scanf(" %[^\n]", list[totalContatos].name);

    printf("Qual sera o numero do seu contato? ");
    scanf(" %[^\n]", list[totalContatos].numero);

    printf("Qual sera o email do seu contato? ");
    scanf(" %[^\n]", list[totalContatos].email);

    totalContatos++;
}

/*Edit: Contato realizando busca. Com busca no nome.*/
/*Proximo passo: add -> as functions de busca tel, busca email*/

bool editar(){
    int choice = 0;
    printf("Como voce deseja procurar pelo contato que voce deseja editar? Digite: 1 - NOME | 2 - EMAIL | 3 - NUMERO");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        char nome[100];
        printf("Digite o nome do contato: ");
        scanf(" %[^\n]", nome);
        info *foundContact = buscaContatoPorNome(nome);
        if(foundContact == NULL)
        {
            printf("Nao encontramos o seu usuario.\n");
            return false;
        }
        else
        {
            printf("Contato encontrado: %s\n%s\n%s\n", foundContact->name, foundContact->numero, foundContact->email);
            printf("Qual voce deseja editar? 1 -> NOME | 2 -> NUMERO | 3 -> EMAIL: ");
            int escolha = 0;
            scanf("%d", &escolha);
            if(escolha == 1)
            {
                char nomeVar[100];
                printf("Como sera o novo nome? ");
                scanf(" %[^\n]", nomeVar);
                if(strlen(nomeVar) == 0 ) return false;
                strcpy(foundContact->name, nomeVar);
                printf("\nNome alterado com sucesso!\n");
                return true;
            }
            else if(escolha == 2)
            {
                char numeroVar[15];
                printf("Como sera o novo numero? ");
                scanf(" %[^\n]", numeroVar);
                if(strlen(numeroVar) == 0 ) return false;
                strcpy(foundContact->numero, numeroVar);
                printf("Numero alterado com sucesso!\n");
                return true;
            }
            else if(escolha == 3)
            { 
                char emailVar[100];
                printf("Como sera o novo e-mail? ");
                scanf(" %[^\n]", emailVar);
                if(strlen(emailVar) == 0 ) return false;
                strcpy(foundContact->email, emailVar);
                printf("E-mail alterado com sucesso!\n");
                return true;
            }
            else
            {
                printf("Opcao invalida!\n");
                return false;
            }
        }
        case 2:
            char email[24];
            printf("Digite o email de busca: ");
            scanf(" %[^\n]", email);
            info* contato = buscaContatoPorEmail(email);
            if(contato == null){return false;}
            printf("Contato encontrado: %s\n%s\n%s\n", foundContact->name, foundContact->numero, foundContact->email);
            printf("Qual voce deseja editar? 1 -> NOME | 2 -> NUMERO | 3 -> EMAIL: ");
            int escolha = 0;
            scanf("%d", &escolha);
            if(escolha == 1)
                {
                    char nomeVar[100];
                    printf("Como sera o novo nome? ");
                    scanf(" %[^\n]", nomeVar);
                    if(strlen(nomeVar) == 0 ) return false;
                    strcpy(foundContact->name, nomeVar);
                    printf("\nNome alterado com sucesso!\n");
                    return true;
                }
            else if(escolha == 2)
                {
                    char numeroVar[15];
                    printf("Como sera o novo numero? ");
                    scanf(" %[^\n]", numeroVar);
                    if(strlen(numeroVar) == 0 ) return false;
                    strcpy(foundContact->numero, numeroVar);
                    printf("Numero alterado com sucesso!\n");
                    return true;
                }
            else if(escolha == 3)
                { 
                    char emailVar[100];
                    printf("Como sera o novo e-mail? ");
                    scanf(" %[^\n]", emailVar);
                    if(strlen(emailVar) == 0 ) return false;
                    strcpy(foundContact->email, emailVar);
                    printf("E-mail alterado com sucesso!\n");
                    return true;
                }
            else
                {
                    printf("Opcao invalida!\n");
                    return false;
                }
        case 3:
            char telefone[24];
            printf("Digite o telefone de busca: ");
            scanf(" %[^\n]", telefone);
            info* contato = buscaContatoPorTel(telefone);
            if(contato == null){return false;}
            printf("Contato encontrado: %s\n%s\n%s\n", foundContact->name, foundContact->numero, foundContact->email);
            printf("Qual voce deseja editar? 1 -> NOME | 2 -> NUMERO | 3 -> EMAIL: ");
            int escolha = 0;
            scanf("%d", &escolha);
            if(escolha == 1)
                {
                    char nomeVar[100];
                    printf("Como sera o novo nome? ");
                    scanf(" %[^\n]", nomeVar);
                    if(strlen(nomeVar) == 0 ) return false;
                    strcpy(foundContact->name, nomeVar);
                    printf("\nNome alterado com sucesso!\n");
                    return true;
                }
                else if(escolha == 2)
                {
                    char numeroVar[15];
                    printf("Como sera o novo numero? ");
                    scanf(" %[^\n]", numeroVar);
                    if(strlen(numeroVar) == 0 ) return false;
                    strcpy(foundContact->numero, numeroVar);
                    printf("Numero alterado com sucesso!\n");
                    return true;
                }
                else if(escolha == 3)
                { 
                    char emailVar[100];
                    printf("Como sera o novo e-mail? ");
                    scanf(" %[^\n]", emailVar);
                    if(strlen(emailVar) == 0 ) return false;
                    strcpy(foundContact->email, emailVar);
                    printf("E-mail alterado com sucesso!\n");
                    return true;
                }
                else
                {
                    printf("Opcao invalida!\n");
                    return false;
                }
    
    default:
        break;
    }
    return false;
}

/*refactor atualized: type return bool*/

bool carregaNoTxt(){
    fptr = fopen("contatos.txt", "w")
    if(fptr == NULL)
    {
        return false;
    }
    for(int i = 0; i<totalContatos; i++)
    {
        fprintf(fptr, "%s, %s, %s\n", list[i].nome, list[i].numero, list[i].email);
    }
    fclose(fptr);
    return true;
}

/*add: busca por nome*/

info* buscaContatoPorNome(char *searchName){
    for(int i = 0; i<totalContatos; i++){
        if(strcmp(searchName, list[i].name) == 0){
            return &list[i];
        }
    }
    return NULL;
}

/*add: function busca por telefone*/

info* buscaContatoPorTel(char *searchTel){
    for(int i = 0; i<totalContatos; i++){
        if(strcmp(searchTel, list[i].numero) == 0){
            return &list[i];
        }
    }
    return NULL;
}

/*add: function busca por email*/

info* buscaContatoPorEmail(char *searchEmail){
    for(int i = 0; i<totalContatos; i++){
        if(strcmp(searchEmail, list[i].email) == 0){
            return &list[i];
        }
    }
    return NULL;
}

/*Concluido*/

int main(){
    int escolhas = 0;
    while(escolhas != 6){
    printf("\n---------------------BEM-VINDO---------------------\n");
    printf("Essa eh uma aplicacao totalmente feita em C, para organizar uma lista de contatos!\n");
    printf("1 --> Adicionar um Contato\n");
    printf("2 --> Remover um Contato\n");
    printf("3 --> Buscar um Contato\n");
    printf("4 --> Editar contatos\n");
    printf("5 --> Salvar e carregar\n");
    printf("6 --> Ordenar Lista\n");
    printf("Qual e a sua escolha? ");
    scanf("%d", &escolhas);
        switch (escolhas)
        {
        case 1:
            addContato();
            
            break;
        case 2:
            removerContato();
            break;

        case 3:
            buscaContato();
            break;

        case 4:
            editar();
            break;

        case 5:
            carregaNoTxt();
            break;
        case 6:
            ordenarLista();
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }
    }      

    return 0;
}
