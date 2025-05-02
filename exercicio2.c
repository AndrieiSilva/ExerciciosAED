#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int menu(void);
char * adicionar_nome(char * lista,int * tamanho_string, int *contador);
void remover_nome(char * lista,int * tamanho_string);
void listar_nome(char * lista,int * tamanho_string);
void encontrar_nome(char nome[20], int * tamanho_string, char * lista, int * rec, int * local);
void excluir_nome(int * tamanho_string, char * lista, int * local, int * tam);

int main(){
    int c, contador = 0;
    char * lista;
    int tamanho_string = 0;
    

    for (;;){

        c = menu();
        switch(c){
            case 1:
                lista = adicionar_nome(lista,&tamanho_string, &contador);
                break;
            case 2:
                remover_nome(lista,&tamanho_string);
                break;
            case 3:
                listar_nome(lista,&tamanho_string);
                break;
            case 4:
                exit(0);
                break;
        }
    }

    return 0;
}

int menu(void){
    int c;
    do{
        printf("\n-----MENU-----\n");

        printf("1.Adicionar nome: \n");
        printf("2.Remover nome: \n");
        printf("3.Listar nome: \n");
        printf("4.Sair\n");
        scanf("%d", &c);
    } while (c < 1 || c > 4);

    return c;
}

char * adicionar_nome(char * lista,int * tamanho_string, int *contador){
    char nome[20];
    int i,cont, flag;
    scanf("%s", nome);

    flag = * contador;

    for (i = 0; nome[i] != '\0';i++);

    cont = *tamanho_string;

    *tamanho_string = *tamanho_string + i;
    i = *tamanho_string;

    if (flag == 0){
    lista = (char *)malloc((sizeof(char) * i)+1);
    flag++;
    }
    else
    {
        if (flag == 1){
            lista = (char *)realloc(lista,(sizeof(char) * i)+1);
        }
    }
    for (i=0;cont <= *tamanho_string;i++){
        lista[cont] = nome[i];
        cont++;
    }

    *contador = flag;

    return lista;
}

void remover_nome(char * lista,int * tamanho_string){
    char nome[20];
    int rec = 0, local = 0;
    printf("Escreva o nome a ser removido: ");
    scanf("%s", nome);
    
    encontrar_nome(nome, tamanho_string, lista, &rec, &local);
}

void encontrar_nome(char nome[20], int * tamanho_string, char * lista, int * rec, int * local){
    int tam,i,j=0,c=0,istore,jstore;
    int t=0;

    for (tam=0;nome[tam] != '\0';tam++);
    char nome_sem_espaco[tam];
    for (i=0;i <= (tam);i++){
        nome_sem_espaco[i] = nome[i];
    }

    j = *tamanho_string;
    i=tam-1;

    while(i >= 0){
        while(lista[j] != nome_sem_espaco[i]){
            j--;
        }
        istore = i;
        jstore = j;
        for(c=tam-2;c >= 0;c--){
            if(lista[j-1] == nome_sem_espaco[i-1]){
                i--;
                j--;
            }else{
                c = -1;
                i = istore;
                j = jstore;
                j--;
            }
            
    }
    if(lista[j-1] == nome_sem_espaco[i-1]);
        i--;    
    }
    *local = j;
    excluir_nome(tamanho_string,lista,local,&tam);
}

void excluir_nome(int * tamanho_string, char * lista, int * local, int * tam){
    int i = 0;

    i = *local;

    while ((lista[i+*tam]) != '\0'){
        lista[i] = lista[i+*tam];
        i++;
    }

    lista[*tamanho_string - *tam] = '\0';
    *tamanho_string = *tamanho_string - *tam;
    lista = (char *)realloc(lista,(sizeof(char) * (*tamanho_string))+1);

}

void listar_nome(char * lista,int * tamanho_string){
    int i;

    for (i=0;i < *tamanho_string;i++){
        printf("%c", lista[i]);
    }


}