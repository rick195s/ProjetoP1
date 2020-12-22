
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "../headers/funcoes_uc.h"
#include "../headers/funcoes_auxiliares.h"

int inserirUc(tipoUnidadeCurricular UCs[], int numUCs)
{

    int up_numUCs, quantidadeUCs,i,j;

    up_numUCs = numUCs;

    system("@cls||clear");

    quantidadeUCs=lerInteiro("\n\nIndique quantas unidades curiulares pretende inserir", 1, MAX_UC-numUCs);


    for(i=0; i<quantidadeUCs; i++)
    {
        printf("\n\nUC numero %d", i+1 );
        lerString("\n\nInsira a designacao da UC: ", UCs[up_numUCs].designacao, MAX_STRING);
        UCs[up_numUCs].tipoUC = lerInteiro("\n\nIndique o tipo de UC\n\n0- Opcional\n\n1- Obrigatoria\n\n ",0,1);
        UCs[up_numUCs].semestre = lerInteiro("\n\nIndique o semestre a que esta UC pertence ",1,6);
        UCs[up_numUCs].regime = lerInteiro("\n\nIndique o requime da UC\n\n0- diurno\n\n1- pos-laboral\n\n ",0,1);


        strcpy(UCs[up_numUCs].aulasOnline[0].designacao, "T");
        strcpy(UCs[up_numUCs].aulasOnline[1].designacao, "TP");
        strcpy(UCs[up_numUCs].aulasOnline[2].designacao, "PL");


        for(j=0; j<TIPOS_AULA; j++)
        {

            printf("\n\nIndique a quantidade de aulas de %s da UC", UCs[up_numUCs].aulasOnline[j].designacao );
            UCs[up_numUCs].aulasOnline[j].quantidade = lerInteiro("",0,200);

            if(UCs[up_numUCs].aulasOnline[j].quantidade > 0)
            {

                printf("\n\nIndique a duracao das aulas de %s da UC em minutos", UCs[up_numUCs].aulasOnline[j].designacao );
                UCs[up_numUCs].aulasOnline[j].duracao = lerInteiro("",0,200);

            }

        }




        up_numUCs++;
        system("@cls||clear");

    }

    for(i=0; i<up_numUCs; i++)
    {
        printf("\ndesignacao %s", UCs[i].designacao);
        printf("\ntipo %d", UCs[i].tipoUC);
        printf("\nsemestre %d", UCs[i].semestre);
        printf("\nregime %d", UCs[i].regime);
        for(j=0; j<3; j++)
        {
            printf("\ndesignacao %s",  UCs[i].aulasOnline[j].designacao);
            printf("\nquantidade %d",  UCs[i].aulasOnline[j].quantidade );
            printf("\nduracao %d",  UCs[i].aulasOnline[j].duracao );


        }
    }


    return up_numUCs;
}
