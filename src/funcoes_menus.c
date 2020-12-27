
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#include "../headers/funcoes_menus.h"
#include "../headers/funcoes_uc.h"
#include "../headers/funcoes_aulas.h"
#include "../headers/funcoes_auxiliares.h"
#include "../headers/funcoes_ficheiros.h"


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

void menuAulas(tipoAulaOnline aulasOnline[], int *numAulas)
{

    char op;


    do
    {


        printf("\n************************ Menu das Aulas Online ************************");



        printf("\n\nA - Agendar Aulas Online");
        printf("\n\nI - Iniciar Aula Online");
        printf("\n\nT - Terminar Aula Online");
        printf("\n\nL - Listar Aulas Online");
        printf("\n\nF - Voltar atras\n\nOpcao--> ");

        scanf("%c", &op);
        op=toupper(op);
        limpaBufferStdin();

        switch(op)
        {
        case 'A':
            *numAulas=agendarAulaOnline(aulasOnline, *numAulas);
            break;
        case 'I':

            break;
        case 'T':

            break;

        case 'L':

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

void menuUC(tipoUnidadeCurricular uniCurriculares[],int *numUCs)
{

    char op;
    int i;

    do
    {

        printf("\n************************ Menu Unidade Curriular ************************");



        printf("\n\nI - Inserir UCs");
        printf("\n\nA - Alterar UC");
        printf("\n\nL - Listar UC");
        printf("\n\nF - Voltar atras\n\nOpcao--> ");

        scanf("%c", &op);
        op=toupper(op);
        limpaBufferStdin();

        switch(op)
        {

        case 'I':

            if(*numUCs<MAX_UC)
            {
                *numUCs=inserirUCs( uniCurriculares, *numUCs);

            }
            else
            {
                system("@cls||clear");
                printf("\n\n\n\t\tO numero maximo de UCs foi alcancado\n\n\n");
            }

            break;
        case 'A':
            if(*numUCs == 0)
            {
                system("@cls||clear");
                printf("\n\n\n\t\tNao existem unidades curriculares\n\n\n");

            }
            else
            {
                system("@cls||clear");
                alterarUC(uniCurriculares, *numUCs);
            }
            break;
        case 'L':
            if(*numUCs == 0)
            {
                system("@cls||clear");
                printf("\n\n\n\t\tNao existem unidades curriculares\n\n\n");

            }
            else
            {
                system("@cls||clear");
                for(i=0; i<*numUCs; i++)
                {
                    listarUC(uniCurriculares[i],1);
                }


            }
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
