
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#include "../headers/funcoes_menus.h"
#include "../headers/funcoes_uc.h"
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

void menuUC(tipoUnidadeCurricular uniCurriculares[],int *numUCs)
{

    char op;
    //int i,j;

    do
    {
        lerFiheiroBinarioUC(uniCurriculares, numUCs);


        /*DEBUG MOSTARR DADOS LIDOS

        printf("\n\nQuantidade de UC: %d", *numUCs);


        for(i=0; i<*numUCs; i++)
        {
            printf("\ndesignacao %s", uniCurriculares[i].designacao);
            printf("\ntipo %d", uniCurriculares[i].tipoUC);
            printf("\nsemestre %d", uniCurriculares[i].semestre);
            printf("\nregime %d", uniCurriculares[i].regime);
            for(j=0; j<3; j++)
            {
                printf("\ndesignacao %s",  uniCurriculares[i].aulasOnline[j].designacao);
                printf("\nquantidade %d",  uniCurriculares[i].aulasOnline[j].quantidade );
                printf("\nduracao %d",  uniCurriculares[i].aulasOnline[j].duracao );


            }
        }
        */


        printf("\n************************ Menu Unidade Curriular ************************");



        printf("\n\nI - Inserir UCs");
        printf("\n\nA - Alterar UC");
        printf("\n\nE - Listar UC");
        printf("\n\nF - Voltar atras\n\nOpcao--> ");

        scanf("%c", &op);
        op=toupper(op);
        limpaBufferStdin();

        switch(op)
        {

        case 'I':

            if(*numUCs<MAX_UC)
            {
                *numUCs=inserirUc( uniCurriculares, *numUCs);

            }
            else
            {
                system("@cls||clear");
                printf("\n\n\n\t\tO numero maximo de UCs foi alcancado\n\n\n");
            }

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
