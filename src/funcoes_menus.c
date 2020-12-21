
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#include "../headers/funcoes_menus.h"
#include "../headers/funcoes_auxiliares.h"


char menuPrincipal()
{
    char op;

    printf("\n************************ Menu Principal ************************");



    printf("\n\nU - Inserir, Alterar ou Listar informacoes de UCs");
    printf("\n\nA - Agendar, Alterar, Listar aulas online ou Registar estado de aulas");
    printf("\n\nE - Inserir, Alterar, Listar informacoes de estudantes ou entrar em aula");
    printf("\n\nF - Fim\n\nOpcao--> ");

    scanf("%c", &op);
    op=toupper(op);
    limpaBufferStdin();


    return op;

}

void menuUC()
{
    char op;

    do
    {
        printf("\n************************ Menu Principal ************************");



        printf("\n\nI - Inserir UCs");
        printf("\n\nA - Alterar UC");
        printf("\n\nE - Listar UC");
        printf("\n\nF - Fim\n\nOpcao--> ");

        scanf("%c", &op);
        op=toupper(op);
        limpaBufferStdin();

        switch(op)
        {
        case 'U':

            break;
        case 'A':

            break;
        case 'E':
            break;
        case 'F':
            break;
        default:
            system("@cls||clear");
            printf("\n\n\n\t\tOpcao invalida\n\n\n");
        }
    }
    while(op!='F');



}


