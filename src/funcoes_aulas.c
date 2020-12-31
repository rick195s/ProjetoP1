
#include <stdio.h>
#include <stdlib.h>

#include "../headers/funcoes_aulas.h"
#include "../headers/funcoes_uc.h"
#include "../headers/funcoes_ficheiros.h"
#include "../headers/funcoes_auxiliares.h"



void listarAulasOnline(tipoAulaOnline aulaOnline)
{

    printf("\n\ncodigo: %d", aulaOnline.codigoUC);
    printf("\n\ndesignacao: %s", aulaOnline.designacao);
    printf("\n\ndoente: %s", aulaOnline.nomeDocente);
    printf("\n\ninicio: %.2f", aulaOnline.horaInicio);
    printf("\n\nfim: %.2f", aulaOnline.horaFim);
}

int quantidadeAulasTipo(tipoUnidadeCurricular uniCurricular, int tipoAula, tipoAulaOnline aulasOnline[], int numAulas)
{


    /*
    Esta função tem a responsabilidade de verificar quantas aulas do tipo "tipoAula"
    existem na unidade curriular a que a aula vai ser associada
    */


    int i,quantidade=0;


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
    data.dia = lerInteiro("\n\tDia", 1,31);
    data.mes = lerInteiro("\n\tMes", 1,12);
    data.ano = lerInteiro("\n\tAno", 2020,2021);

    return data;
}

tipoAulaOnline lerDadosAulaOnline(tipoUnidadeCurricular uniCurricular, tipoAulaOnline aulasOnline[], int numAulas)
{

    tipoAulaOnline aulaOnline;
    int quantidadeAulas;


    /*
    Se a uc não existir o utilizador volta ao menu das aulas
    */


    aulaOnline.codigoUC = uniCurricular.codigo;

    /*
    Antes de associarmos o tipo de aula à aula primeiro temos de verificar
    se a UC a que esta aula vai pertener tem "espaço", ou seja numero de aulas
    deste tipo na uc > 0, para mais uma aula deste tipo
    */

    do
    {

        aulaOnline.tipoAula = lerInteiro("\n\nTipo de aula\n\n0 - T\n\n1 - TP\n\n2 - PL  ",0,2);
        quantidadeAulas = quantidadeAulasTipo(uniCurricular,aulaOnline.tipoAula, aulasOnline, numAulas);


        if(uniCurricular.aulasOnline[aulaOnline.tipoAula].quantidade == 0)
        {
            printf("\n\nEsta unidade curricular nao tem este tipo de aulas");

        }
        else if((uniCurricular.aulasOnline[aulaOnline.tipoAula].quantidade-quantidadeAulas) == 0)
        {
            printf("\n\nEsta unidade curricular ja tem todas as aulas deste tipo agendadas");

        }
    }


    while((uniCurricular.aulasOnline[aulaOnline.tipoAula].quantidade-quantidadeAulas) == 0);


    /*
    A hora de inicio de uma aula pode ser desde a hora minima de começo atá à hora final
    menos o tempo de duração do tipo de uma aula da UC
    */

    if(uniCurricular.regime == 0)
    {

        /*
        Para conseguir converter as horas ccom formato correto implementamos uma função que
        recebe por parametros a duracao do tipo de aula em minutos, a hora a que essa alteração
        vai ser efetuada e o sinal, ou seja 0 para positivo e 1 para negativo, pois assim
        a mesma função consegue converter a hora de inicio ou a hora de fim
        */

        aulaOnline.horaInicio = lerFloat("\n\nIntroduza o horario da aula:\n\tInicio ",8,formatarHoraComDuracaoAula(uniCurricular.aulasOnline[aulaOnline.tipoAula].duracao,18,1));

        aulaOnline.horaFim = formatarHoraComDuracaoAula(uniCurricular.aulasOnline[aulaOnline.tipoAula].duracao,aulaOnline.horaInicio,0);


    }
    else
    {


        aulaOnline.horaInicio = lerFloat("\n\nIntroduza o horario da aula:\n\tInicio ",18,formatarHoraComDuracaoAula(uniCurricular.aulasOnline[aulaOnline.tipoAula].duracao,24,1));

        aulaOnline.horaFim = formatarHoraComDuracaoAula(uniCurricular.aulasOnline[aulaOnline.tipoAula].duracao,aulaOnline.horaInicio,0);

    }


    lerString("\n\nNome do Docente: ", aulaOnline.nomeDocente, MAX_STRING);

    /*
    Verificar se a desginação da é única
    */
    lerString("\n\nDesignacao da aula: ", aulaOnline.designacao, MAX_STRING);
    aulaOnline.data = lerData();

    aulaOnline.estado = 0;
    aulaOnline.gravada = 0;

    return aulaOnline;




}


int agendarAulaOnline(tipoAulaOnline aulasOnline[], int numAulas, tipoUnidadeCurricular uniCurriculares[], int numUCs)
{

    int up_numAulas, codigoUC, posicao;

    up_numAulas = numAulas;

    system("@cls||clear");


    codigoUC = lerInteiro("\n\nIntroduza o codigo da unidade curricular a que esta aula pertence ",1000,9999);
    posicao = procurarUC(codigoUC, uniCurriculares, numUCs);


    if(posicao == -1 )
    {

        printf("\n\nA unidade curricular que introduziu nao existe");

    }
    else
    {

        up_numAulas++;
        aulasOnline = realloc(aulasOnline, up_numAulas*sizeof(tipoAulaOnline));

        if(aulasOnline == NULL)
        {
            printf("\n\nNao foi possivel agendar reservar memoria para as aulas online");
        }
        else
        {
            aulasOnline[numAulas] = lerDadosAulaOnline(uniCurriculares[posicao],aulasOnline, numAulas);

            escreverFiheiroBinarioAulasOnline(aulasOnline, up_numAulas);
        }


    }


    return up_numAulas;

}

