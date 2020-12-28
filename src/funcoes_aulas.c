
#include <stdio.h>
#include <stdlib.h>

#include "../headers/funcoes_aulas.h"
#include "../headers/funcoes_uc.h"
#include "../headers/funcoes_ficheiros.h"
#include "../headers/funcoes_auxiliares.h"


int quantidadeAulasTipo(tipoUnidadeCurricular uniCurricular, int tipoAula)
{

    /*
    Esta função tem a responsabilidade de verificar quantas aulas do tipo "tipoAula"
    existem na unidade curriular a que a aula vai ser associada
    */

    int i,quantidade=0, numAulas;
    tipoAulaOnline aulasOnline[MAX_AULAS];

    lerFiheiroBinarioAulasOnline(aulasOnline, &numAulas);

    for(i=0; i<numAulas; i++)
    {
        if(aulasOnline[i].codigoUC == uniCurricular.codigo && aulasOnline[i].tipoAula == tipoAula)
        {

            quantidade++;

        }

    }

    return quantidade;
}

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
    int codigoUC,quantidadeAulas;
    float minutos,hora, horaCompleta;

    codigoUC = lerInteiro("\n\nIntroduza o codigo da unidade curricular a que esta aula pertence ",1000,9999);
    codigoUC = procurarUC(&uniCurricular,codigoUC,1);


    /*
    Se a uc não existir o utilizador volta ao menu das aulas
    */

    if(codigoUC != -1)
    {
        aulaOnline.codigoUC = codigoUC;

        /*
        Antes de associarmos o tipo de aula à aula primeiro temos de verificar
        se a UC a que esta aula vai pertener tem "espaço", ou seja numero de aulas
        deste tipo na uc > 0, para mais uma aula deste tipo
        */

        do
        {

            aulaOnline.tipoAula = lerInteiro("\n\nTipo de aula\n\n0 - T\n\n1 - TP\n\n2 - PL  ",0,2);
            quantidadeAulas = quantidadeAulasTipo(uniCurricular,aulaOnline.tipoAula);


            if(uniCurricular.aulasOnline[aulaOnline.tipoAula].quantidade == 0)
            {
                printf("\n\nEsta unidade curricular nao tem este tipo de aulas");

            }
            else if((uniCurricular.aulasOnline[aulaOnline.tipoAula].quantidade - quantidadeAulas) == 0)
            {
                printf("\n\nEsta unidade curricular ja tem todas as aulas deste tipo agendadas");

            }
        }


        while((uniCurricular.aulasOnline[aulaOnline.tipoAula].quantidade - quantidadeAulas) == 0);


        /*
        A hora de inicio de uma aula pode ser desde a hora minima de começo atá à hora final
        menos o tempo de duração do tipo de uma aula da UC
        */

        if(uniCurricular.regime == 0)
        {

            hora=((18*60)- (float) uniCurricular.aulasOnline[aulaOnline.tipoAula].duracao)/60;
            minutos = (hora - (int) hora)*0.6;
            horaCompleta = (int) hora+minutos;

            aulaOnline.horaInicio = lerFloat("\n\nIntroduza o horario da aula:\n\tInicio ",8,horaCompleta);
            aulaOnline.horaFim = lerFloat("\n\tFim ",aulaOnline.horaInicio,18);

        }
        else
        {
            hora=((24*60)-uniCurricular.aulasOnline[aulaOnline.tipoAula].duracao)/60;

            minutos = (hora - (int) hora)*0.6;
            horaCompleta = (int) hora+minutos;

            aulaOnline.horaInicio = lerFloat("\n\nIntroduza o horario da aula:\n\tInicio ",18,horaCompleta);
            aulaOnline.horaFim = lerFloat("\n\tFim ",aulaOnline.horaInicio,24);
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

