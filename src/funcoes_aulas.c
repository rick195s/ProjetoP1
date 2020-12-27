
#include <stdio.h>
#include <stdlib.h>

#include "../headers/funcoes_aulas.h"
#include "../headers/funcoes_uc.h"
#include "../headers/funcoes_ficheiros.h"
#include "../headers/funcoes_auxiliares.h"

tipoData lerData()
{

    tipoData data;

    printf("\n\nIntroduza a data da aula:");
    data.dia = lerInteiro("\n\tDia ", 1,31);
    data.mes = lerInteiro("\n\tMes ", 1,12);
    data.ano = lerInteiro("\n\tDia ", 2020,2021);

    return data;
}

tipoAulaOnline lerDadosAulaOnline()
{

    tipoAulaOnline aulaOnline;
    tipoUnidadeCurricular uniCurricular;
    int codigoUC;

    codigoUC = lerInteiro("\n\nIntroduza o codigo da unidade curricular a que esta aula pertence ",1000,9999);
    codigoUC = procurarUC(&uniCurricular,codigoUC,1);

    if(codigoUC != -1)
    {
        aulaOnline.codigoUC = codigoUC;

        /*
        Antes de associarmos o tipo de aula à aula primeiro temos de verificar
        se a UC a que esta aula vai pertener tem "espaço", ou seja numero de aulas
        deste tipo na uc > 0, para mais uma aula deste tipo
        */


        aulaOnline.tipoAula = lerInteiro("\n\nTipo de aula\n\n0 - T\n\n1 - TP\n\n2 - PL  ",0,2);

        if(uniCurricular.regime == 0)
        {

            aulaOnline.horaInicio = lerInteiro("\n\nIntroduza o horario da aula:\n\tInicio ",8,18);
            aulaOnline.horaFim = lerInteiro("\n\tFim ",aulaOnline.horaInicio,18);

        }else{
            aulaOnline.horaInicio = lerInteiro("\n\nIntroduza o horario da aula:\n\tInicio ",18,24);
            aulaOnline.horaFim = lerInteiro("\n\tFim ",aulaOnline.horaInicio,24);
        }


        lerString("\n\nNome do Docente: ", aulaOnline.nomeDocente, MAX_STRING);
        aulaOnline.data = lerData();

        aulaOnline.estado = 0;
        aulaOnline.gravada = 0;

        return aulaOnline;

    }
    else
    {

        aulaOnline.codigoUC = codigoUC;
        return aulaOnline;

    }

}


int agendarAulaOnline(tipoAulaOnline aulasOnline[], int numAulas)
{

    int up_numAulas;

    up_numAulas = numAulas;

    system("@cls||clear");

    aulasOnline[up_numAulas] = lerDadosAulaOnline();

    if(aulasOnline[up_numAulas].codigoUC == -1 )
    {

        printf("\n\nA unidade curricular que introduziu nao existe");

    }
    else
    {

        up_numAulas++;
        escreverFiheiroBinarioAulasOnline(aulasOnline, up_numAulas);
    }

    return up_numAulas;

}

