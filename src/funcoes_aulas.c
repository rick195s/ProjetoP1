
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/funcoes_aulas.h"
#include "../headers/funcoes_uc.h"
#include "../headers/funcoes_ficheiros.h"
#include "../headers/funcoes_auxiliares.h"


int verificarHorarioAula(tipoAulaOnline aulasOnline[], int numAulas, tipoAulaOnline aulaOnline)
{

    int i,unica=1;

    for(i=0; i<numAulas; i++)
    {
        /*

            FALTA VERIFICAR SE HA AULAS CCOMEÇAM ENQUANTO OUTROS ESTÃO A DECORRER

        */
        if( aulaOnline.codigoUC == aulasOnline[i].codigoUC && aulaOnline.data.ano == aulasOnline[i].data.ano && aulaOnline.data.mes == aulasOnline[i].data.mes && aulaOnline.data.dia == aulasOnline[i].data.dia && aulaOnline.horaInicio >= aulasOnline[i].horaInicio && aulaOnline.horaInicio <= aulasOnline[i].horaFim )
        {

            unica = 0;

            return unica;
        }

    }

    return unica;

}

int verificarDesignacaoAula(tipoAulaOnline aulasOnline[], int numAulas, char designacao[MAX_STRING])
{

    int unica=1,i;

    for(i=0; i<numAulas; i++)
    {

        if(strcmp(aulasOnline[i].designacao, designacao) == 0)
        {
            unica = 0;

            return unica;
        }

    }


    return unica;
}

void listarAulasOnline(tipoAulaOnline aulaOnline)
{

    printf("\n\ncodigo: %d", aulaOnline.codigoUC);
    printf("\n\ndesignacao: %s", aulaOnline.designacao);
    printf("\n\ndocente: %s", aulaOnline.nomeDocente);
    printf("\n\ninicio: %.2f", aulaOnline.horaInicio);
    printf("\n\nfim: %.2f", aulaOnline.horaFim);
    printf("\n\ndia: %d", aulaOnline.data.dia);
    printf("\n\nmes: %d", aulaOnline.data.mes);
    printf("\n\nano: %d", aulaOnline.data.ano);


}

int verificarQuantidadeAulasTipo(tipoUnidadeCurricular uniCurricular, int tipoAula, tipoAulaOnline aulasOnline[], int numAulas, int todosTipo)
{


    /*
    Esta função tem a responsabilidade de verificar quantas aulas do tipo "tipoAula"
    existem na unidade curriular a que a aula vai ser associada, mas se o argumento
    "todosTipo" estiver a 1 esta função vai devolver a quantidade total de todo o tipo
    de aulas existentes na uc que faltam agendar
    */


    int i,quantidade=0,tipos=0;

    if(todosTipo == 1)
    {
        for(i=0; i<numAulas; i++)
        {
            if(aulasOnline[i].codigoUC == uniCurricular.codigo && (aulasOnline[i].tipoAula >= 0 || aulasOnline[i].tipoAula < TIPOS_AULA))
            {

                quantidade++;

            }
        }
        for(i=0; i<TIPOS_AULA; i++)
        {
            tipos+=uniCurricular.aulasOnline[i].quantidade;
        }
        quantidade = tipos - quantidade;
    }
    else
    {
        for(i=0; i<numAulas; i++)
        {
            if(aulasOnline[i].codigoUC == uniCurricular.codigo && aulasOnline[i].tipoAula == tipoAula)
            {

                quantidade++;

            }
        }
    }

    return quantidade;
}

float formatarHoraComDuracaoAula(int duracao, float hora, int sinal)
{
    float horaCompleta, minutos,horas;

    if(sinal == 0)
    {
        horas=(((int)hora* 60)+(hora-(int)hora)*100 + duracao)/60.0;

    }
    else
    {
        horas=(((int)hora* 60)+(hora-(int)hora)*100 - duracao)/60.0;
    }

    hora=horas;
    horas=(int)horas;
    minutos=(hora-horas)*0.6;
    horaCompleta=horas+minutos;

    return horaCompleta;
}

/*
Le a hora e os minutos devolvendo depois um float com a hora nas unidades e os minutos na parte decimal
*/
float lerHoraAula(float inicio, float fim){

    float horaCompleta;
    int hora,minutos;

    hora=lerInteiro("\n\nInsire o inicio da aula\n\nhora", inicio, fim);

    if(hora<(int)fim){
         minutos=lerInteiro("\n\nminutos", 0,59);
    }else{

         minutos=lerInteiro("\n\nminutos", 0,((fim-(int) fim)*100));
    }

    horaCompleta=hora+(minutos*0.01);

    return horaCompleta;
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
    int designacao,quantidadeAulas, horarioAula;
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
        quantidadeAulas = verificarQuantidadeAulasTipo(uniCurricular, aulaOnline.tipoAula, aulasOnline, numAulas,0);

        if(uniCurricular.aulasOnline[aulaOnline.tipoAula].quantidade == 0)
        {
            system("@cls||clear");
            printf("\n\nEsta unidade curricular nao tem este tipo de aulas");
        }
        else if((uniCurricular.aulasOnline[ aulaOnline.tipoAula].quantidade-quantidadeAulas) <= 0)
        {
            system("@cls||clear");
            printf("\n\nEsta unidade curricular ja tem todas as aulas deste tipo agendadas");
        }

    }
    while((uniCurricular.aulasOnline[ aulaOnline.tipoAula].quantidade-quantidadeAulas) <= 0);
    /*
    A hora de inicio de uma aula pode ser desde a hora minima de começo atá à hora final
    menos o tempo de duração do tipo de uma aula da UC
    */
    do
    {
        if(uniCurricular.regime == 0)
        {
            /*
            Para conseguir converter as horas ccom formato correto implementamos uma função que
            recebe por parametros a duracao do tipo de aula em minutos, a hora a que essa alteração
            vai ser efetuada e o sinal, ou seja 0 para positivo e 1 para negativo, pois assim
            a mesma função consegue converter a hora de inicio ou a hora de fim
            */
            aulaOnline.horaInicio = lerHoraAula(8, formatarHoraComDuracaoAula(uniCurricular.aulasOnline[aulaOnline.tipoAula].duracao,18,1));
        }
        else
        {
            aulaOnline.horaInicio = lerHoraAula(18, formatarHoraComDuracaoAula(uniCurricular.aulasOnline[aulaOnline.tipoAula].duracao,24,1));
        }


        aulaOnline.horaFim = formatarHoraComDuracaoAula(uniCurricular.aulasOnline[aulaOnline.tipoAula].duracao,aulaOnline.horaInicio,0);

        aulaOnline.data = lerData();
        horarioAula=verificarHorarioAula(aulasOnline, numAulas, aulaOnline);

        if(horarioAula != 1){
            printf("\n\nJa existe uma aula da mesma UC marcada para esta data");
        }

    }
    while(horarioAula != 1);

    lerString("\n\nNome do Docente: ", aulaOnline.nomeDocente, MAX_STRING);

    /*
    Verificar se a desginação da aula é única
    */
    do
    {
        lerString("\n\nDesignacao da aula: ", aulaOnline.designacao, MAX_STRING);
        designacao = verificarDesignacaoAula(aulasOnline, numAulas, aulaOnline.designacao);

        if(designacao != 1)
        {
            printf("\n\nA designacao da aula tem de ser unica");
        }
    }
    while( designacao != 1);

    aulaOnline.estado = 0;
    aulaOnline.gravada = 0;

    return aulaOnline;

}


tipoAulaOnline *agendarAulaOnline(tipoAulaOnline aulasOnline[], int *numAulas, tipoUnidadeCurricular uniCurriculares[], int numUCs)
{

    tipoAulaOnline *aux;
    int codigoUC, posicao;

    aux = aulasOnline;
    system("@cls||clear");
    codigoUC = lerInteiro("\n\nIntroduza o codigo da unidade curricular a que esta aula pertence ",1000,9999);
    posicao = procurarUC(codigoUC, uniCurriculares, numUCs);



    if(posicao == -1 )
    {

        system("@cls||clear");
        printf("\n\n\tA unidade curricular que introduziu nao existe\n\n");

    }
    else
    {


        aulasOnline = realloc(aulasOnline, (*numAulas+1)*sizeof(tipoAulaOnline));

        if(aulasOnline == NULL)
        {
            system("@cls||clear");

            printf("\n\n\tNao foi possivel reservar memoria para as aulas online ao agendar aula\n\n");
            aulasOnline = aux;

        }
        else
        {

            aulasOnline[*numAulas] = lerDadosAulaOnline(uniCurriculares[posicao],aulasOnline, *numAulas);
            (*numAulas)++;
            escreverFiheiroBinarioAulasOnline(aulasOnline, *numAulas);
        }


    }


    return aulasOnline;

}

