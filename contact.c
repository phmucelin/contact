#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "xlsxio_write.h"
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

// Prototypes
info* buscaContatoPorNome(char *searchName);
info* buscaContatoPorTel(char *searchTel);
info* buscaContatoPorEmail(char *searchEmail);
bool editar();
void buscarContato();
int WriteSheets();

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

        if(strcmp(removerNome, list[i].name) == 0){
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
    case 1: {
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
    } break;
    case 2: {
        char email[24];
        printf("Digite o email de busca: ");
        scanf(" %[^\n]", email);
        info* contato = buscaContatoPorEmail(email);
        if(contato == NULL){return false;}
        printf("Contato encontrado: %s\n%s\n%s\n", contato->name, contato->numero, contato->email);
        printf("Qual voce deseja editar? 1 -> NOME | 2 -> NUMERO | 3 -> EMAIL: ");
        int escolha = 0;
        scanf("%d", &escolha);
        if(escolha == 1)
        {
            char nomeVar[100];
            printf("Como sera o novo nome? ");
            scanf(" %[^\n]", nomeVar);
            if(strlen(nomeVar) == 0 ) return false;
            strcpy(contato->name, nomeVar);
            printf("\nNome alterado com sucesso!\n");
            return true;
        }
        else if(escolha == 2)
        {
            char numeroVar[15];
            printf("Como sera o novo numero? ");
            scanf(" %[^\n]", numeroVar);
            if(strlen(numeroVar) == 0 ) return false;
            strcpy(contato->numero, numeroVar);
            printf("Numero alterado com sucesso!\n");
            return true;
        }
        else if(escolha == 3)
        { 
            char emailVar[100];
            printf("Como sera o novo e-mail? ");
            scanf(" %[^\n]", emailVar);
            if(strlen(emailVar) == 0 ) return false;
            strcpy(contato->email, emailVar);
            printf("E-mail alterado com sucesso!\n");
            return true;
        }
        else
        {
            printf("Opcao invalida!\n");
            return false;
        }
    } break;
    case 3: {
        char telefone[24];
        printf("Digite o telefone de busca: ");
        scanf(" %[^\n]", telefone);
        info* contato = buscaContatoPorTel(telefone);
        if(contato == NULL){return false;}
        printf("Contato encontrado: %s\n%s\n%s\n", contato->name, contato->numero, contato->email);
        printf("Qual voce deseja editar? 1 -> NOME | 2 -> NUMERO | 3 -> EMAIL: ");
        int escolha = 0;
        scanf("%d", &escolha);
        if(escolha == 1)
        {
            char nomeVar[100];
            printf("Como sera o novo nome? ");
            scanf(" %[^\n]", nomeVar);
            if(strlen(nomeVar) == 0 ) return false;
            strcpy(contato->name, nomeVar);
            printf("\nNome alterado com sucesso!\n");
            return true;
        }
        else if(escolha == 2)
        {
            char numeroVar[15];
            printf("Como sera o novo numero? ");
            scanf(" %[^\n]", numeroVar);
            if(strlen(numeroVar) == 0 ) return false;
            strcpy(contato->numero, numeroVar);
            printf("Numero alterado com sucesso!\n");
            return true;
        }
        else if(escolha == 3)
        { 
            char emailVar[100];
            printf("Como sera o novo e-mail? ");
            scanf(" %[^\n]", emailVar);
            if(strlen(emailVar) == 0 ) return false;
            strcpy(contato->email, emailVar);
            printf("E-mail alterado com sucesso!\n");
            return true;
        }
        else
        {
            printf("Opcao invalida!\n");
            return false;
        }
    } break;
    default:
        break;
    }
    return false;
}

bool carregaNoTxt(){
    fptr = fopen("contatos.txt", "w");
    if(fptr == NULL)
    {
        return false;
    }
    for(int i = 0; i<totalContatos; i++)
    {
        fprintf(fptr, "%s, %s, %s\n", list[i].name, list[i].numero, list[i].email);
    }
    fclose(fptr);
    return true;
}

/*Funcao que cria um arquivo .xlsx ( Excel )*/
/*Escreve todos os dados que estao salvos previamente na struct*/
/*Otima biblioteca OPEN Source*/
int WriteSheets()
{
    xlsxiowriter handle;
    char *filename = "tabela_contatos.xlsx";
    if ((handle = xlsxiowrite_open(filename, "Tabela de Contatos")) == NULL) {
        fprintf(stderr, "Error ao criar arquivo .xlsx\n");
        return 1;
    }
    xlsxiowrite_set_row_height(handle, 2);
    xlsxiowrite_set_detection_rows(handle, 10);
    xlsxiowrite_add_column(handle, "Nome", 20);
    xlsxiowrite_add_column(handle, "Email", 30);
    xlsxiowrite_add_column(handle, "Telefone", 15);
    xlsxiowrite_next_row(handle);
    int i;
    for(i = 0; i < totalContatos; i++)
    {
        xlsxiowrite_add_cell_string(handle, list[i].name);
        xlsxiowrite_add_cell_string(handle, list[i].email);
        xlsxiowrite_add_cell_string(handle, list[i].numero);
        xlsxiowrite_next_row(handle);
    }
    xlsxiowrite_close(handle);
    return 0;
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

/* Função para buscar contato com submenu */
void buscarContato() {
    printf("Deseja buscar por 1 -> Nome | 2 -> Email | 3 -> Telefone? ");
    int choice = 0;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Digite o nome: ");
        char nome[100];
        scanf(" %[^\n]", nome);
        info* contato = buscaContatoPorNome(nome);
        if (contato) {
            printf("Encontrado: %s, %s, %s\n", contato->name, contato->email, contato->numero);
        } else {
            printf("Contato não encontrado.\n");
        }
    } else if (choice == 2) {
        printf("Digite o email: ");
        char email[100];
        scanf(" %[^\n]", email);
        info* contato = buscaContatoPorEmail(email);
        if (contato) {
            printf("Encontrado: %s, %s, %s\n", contato->name, contato->email, contato->numero);
        } else {
            printf("Contato não encontrado.\n");
        }
    } else if (choice == 3) {
        printf("Digite o telefone: ");
        char telefone[100];
        scanf(" %[^\n]", telefone);
        info* contato = buscaContatoPorTel(telefone);
        if (contato) {
            printf("Encontrado: %s, %s, %s\n", contato->name, contato->email, contato->numero);
        } else {
            printf("Contato não encontrado.\n");
        }
    } else {
        printf("Opção inválida!\n");
    }
}

/*Concluido*/

int main(){
    int escolhas = 0;
    while(escolhas != 8){
    printf("\n---------------------BEM-VINDO---------------------\n");
    printf("Essa eh uma aplicacao totalmente feita em C, para organizar uma lista de contatos!\n");
    printf("1 --> Adicionar um Contato\n");
    printf("2 --> Remover um Contato\n");
    printf("3 --> Buscar um Contato\n");
    printf("4 --> Editar contatos\n");
    printf("5 --> Salvar e carregar\n");
    printf("6 --> Ordenar Lista\n");
    printf("7 --> Exportar para Excel\n");
    printf("8 --> Sair\n");
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
            buscarContato();
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
        case 7:
            WriteSheets();
            break;
        case 8:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    }      

    return 0;
}
