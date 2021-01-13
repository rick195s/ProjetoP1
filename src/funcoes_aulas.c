
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/funcoes_aulas.h"
#include "../headers/funcoes_uc.h"
#include "../headers/funcoes_ficheiros.h"
#include "../headers/funcoes_auxiliares.h"
#include "../headers/funcoes_menus.h"


void gravarAulaOnline(tipoAulaOnline *aulaOnline)
{

    if(aulaOnline->estado == 1)
    {
        aulaOnline->gravada = 1;
        printf("\n\nA aula %s esta a ser gravada\n\n", aulaOnline->designacao);
    }
    else
    {
        printf("\n\nA aula ainda nao foi iniciada ou jfekwhfwea terminou");
    }
}

void terminarAulaOnline(tipoAulaOnline *aulaOnline)
{

    if(aulaOnline->estado == 1)
    {
        aulaOnline->estado = 2;
        printf("\n\nA aula %s foi terminada\n\n", aulaOnline->designacao);

    }
    else
    {
        printf("\n\nA aula ainda nao foi iniciada ou ja terminou");
    }

}

void iniciarAulaOnline(tipoAulaOnline *aulaOnline)
{
    if(aulaOnline->estado == 0 && aulaOnline->horaInicio != 0 && aulaOnline->horaFim != 0)
    {
        aulaOnline->estado = 1;
        printf("\n\nA aula %s foi iniciada\n\n", aulaOnline->designacao);
    }
    else
    {
        if(aulaOnline->estado == 1){
            printf("\n\nA aula esta a decorrer");
        }else if(aulaOnline->estado == 2){
            printf("\n\nA aula ja terminou");
        }else if(aulaOnline->horaInicio && aulaOnline->horaFim){

        }
    }

}

void administradorAulaOnline(tipoAulaOnline aulasOnline[], int numAulas)
{

    char designacao[MAX_STRING],opcao;
    int posicaoAula;

    lerString("\n\nInsira a designacao da aula que pretende alterar o estado: ", designacao, MAX_STRING);

    posicaoAula=procurarDesignacaoAula(aulasOnline, numAulas, designacao);

    if(posicaoAula == -1 || aulasOnline[posicaoAula].estado != 0 )
    {
        if(posicaoAula == -1){
            printf("\n\nNao existe nenhuma aula com a designacao que inseriu");
        }else{
            printf("\n\nNao pode alterar uma aula que esta a decorrer ou ja terminou");
        }

    }
    else
    {
           do
        {
            opcao = menuAdministradorAula();

            switch(opcao)
            {
            case 'I':
                iniciarAulaOnline(&aulasOnline[posicaoAula]);
                break;
            case 'T':
                terminarAulaOnline(&aulasOnline[posicaoAula]);
                break;
            case 'G':
                gravarAulaOnline(&aulasOnline[posicaoAula]);
                break;
            case 'V':
                break;
            default:
                break;

            }
        }
        while(opcao != 'V');


    }
}

tipoAulaOnline *editarAulaOnline(tipoAulaOnline aulasOnline[],int *numAulas,tipoUnidadeCurricular uniCurriculares[],int numUCs)
{

    tipoAulaOnline *aux;
    int opcao,posicaoAula,posicaoUC,i;
    char designacaoAula[MAX_STRING];

    aux=aulasOnline;

    lerString("\n\nIndique a designacao da aula que pretende alterar: ", designacaoAula, MAX_STRING);
    posicaoAula=procurarDesignacaoAula(aulasOnline,*numAulas,designacaoAula);

    if(posicaoAula == -1)
    {
        printf("\n\nNao existem aulas com a desginacao igual a que introduziu");
    }
    else
    {
        opcao=lerInteiro("\n\nOpcoes:\n\t0 - Alterar Agendamento\n\t1 - Eliminar Aula",0,1);

        if(opcao == 0)
        {
            posicaoUC=procurarUC(aulasOnline[posicaoAula].codigoUC, uniCurriculares, numUCs);
            if(posicaoUC == -1)
            {
                printf("\n\nOcorreu um erro ao procurar a unidade curricular correspondente a aula que pretende alterar");
            }
            else
            {
                if(aulasOnline[posicaoAula].estado != 0)
                {
                    printf("\n\nO agendamento da aula nao pode ser alterado pois a aula esta a decorrer ou ja foi realizada");
                }
                else
                {
                    lerHorarioCompletoAula(uniCurriculares[posicaoUC], &aulasOnline[posicaoAula], aulasOnline, *numAulas);
                }

            }
        }
        else
        {
            for(i=posicaoAula; i<(*numAulas)-1; i++)
            {
                aulasOnline[i]=aulasOnline[i+1];
            }

            aulasOnline=realloc(aulasOnline,((*numAulas)-1)*sizeof(tipoAulaOnline));

            if(aulasOnline == NULL)
            {
                printf("\n\nOcorreu um erro a reservar mais memoria ao eliminar aula online");
                aulasOnline=aux;

            }
            else
            {
                (*numAulas)--;
            }

        }
    }

    return aulasOnline;
}

void listarInformacoesUCdaAula(tipoAulaOnline aulasOnline[], int numAulas, tipoUnidadeCurricular uniCurriculares[], int numUCs){

    int posicaoUC, posicaoAula;
    char desginacao[MAX_STRING];

    lerString("\n\nInsira a designacao da aula: ", desginacao, MAX_STRING);
    posicaoAula=procurarDesignacaoAula(aulasOnline, numAulas, desginacao);
    if(posicaoAula == -1){
        printf("\n\nNao existe nenhuma aula com a desgnacao que inseriu");
    }else{
        posicaoUC=procurarUC(aulasOnline[posicaoAula].codigoUC,uniCurriculares,numUCs);
        listarAulasOnline(aulasOnline[posicaoAula]);
        printf("\n\nInformacoes da UC:");
        printf("\n\n\tDesginacao: %s", uniCurriculares[posicaoUC].designacao);
        printf("\n\n\tQuantidade de Aulas por agendar: ");
        printf("\n\n\t\t%s: %d", uniCurriculares[posicaoUC].aulasOnline[0].designacao, (uniCurriculares[posicaoUC].aulasOnline[0].quantidade-verificarQuantidadeAulasTipo(uniCurriculares[posicaoUC],0,aulasOnline,numAulas,0)));
        printf("\n\n\t\t%s: %d", uniCurriculares[posicaoUC].aulasOnline[1].designacao, (uniCurriculares[posicaoUC].aulasOnline[1].quantidade-verificarQuantidadeAulasTipo(uniCurriculares[posicaoUC],1,aulasOnline,numAulas,0)));
        printf("\n\n\t\t%s: %d", uniCurriculares[posicaoUC].aulasOnline[2].designacao, (uniCurriculares[posicaoUC].aulasOnline[2].quantidade-verificarQuantidadeAulasTipo(uniCurriculares[posicaoUC],2,aulasOnline,numAulas,0)));

}

}

void listarAulasOnline(tipoAulaOnline aulaOnline)
{

    printf("\n\nDesignacao da Aula: %s", aulaOnline.designacao);
    printf("\n\n\tCodigo da UC: %d", aulaOnline.codigoUC);
    printf("\n\n\tNome do Docente: %s", aulaOnline.nomeDocente);
    printf("\n\n\tData:\n\t\tHora de Inicio: %.2f", aulaOnline.horaInicio);
    printf("\n\n\t\tHora de Fim: %.2f", aulaOnline.horaFim);
    printf("\n\n\t\t%d/%d/%d", aulaOnline.data.dia, aulaOnline.data.mes, aulaOnline.data.ano);
    if(aulaOnline.estado == 0){
        printf("\n\n\tEstado: Agendada");
    }else if(aulaOnline.estado == 1){
        printf("\n\n\tEstado: A decorrer");
    }else{
        printf("\n\n\tEstado: Terminada");
    }
    if(aulaOnline.gravada == 0){
        printf("\n\n\tGravada: Nao");
    }else{
        printf("\n\n\tGravada: Sim");
    }

}

int procurarDesignacaoAula(tipoAulaOnline aulasOnline[], int numAulas, char designacao[MAX_STRING])
{

    int posicaoAula=-1,i;

    for(i=0; i<numAulas; i++)
    {

        if(strcmp(aulasOnline[i].designacao, designacao) == 0)
        {
            posicaoAula = i;

            return posicaoAula;
        }

    }


    return posicaoAula;
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

void lerHorarioCompletoAula(tipoUnidadeCurricular uniCurricular, tipoAulaOnline *aulaOnline, tipoAulaOnline aulasOnline[], int numAulas)
{

    int horarioAula;
    /*
    Esta variavel tipoAulaOnline auxiliar serve para verificar primeiro o horario da aula e so
    depois alterar os dados do ponteiro da aulaOnline na memoria, porque se altera-se logo
    os dados quando são pedidos ao executar a função verificarHorarioAula iria estar sempre
    a receber um valor da função como se já existisse uma aula com aquele horario
    */
    tipoAulaOnline aulaOnlineAux;

    aulaOnlineAux = *aulaOnline;

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
            aulaOnlineAux.horaInicio = lerHoraAula(8, formatarHoraComDuracaoAula(uniCurricular.aulasOnline[aulaOnlineAux.tipoAula].duracao,18,1));
        }
        else
        {
            aulaOnlineAux.horaInicio = lerHoraAula(18, formatarHoraComDuracaoAula(uniCurricular.aulasOnline[aulaOnlineAux.tipoAula].duracao,24,1));
        }


        aulaOnlineAux.horaFim = formatarHoraComDuracaoAula(uniCurricular.aulasOnline[aulaOnlineAux.tipoAula].duracao,aulaOnlineAux.horaInicio,0);

        aulaOnlineAux.data = lerData();
        horarioAula=verificarHorarioAula(aulasOnline, numAulas, aulaOnlineAux);

        if(horarioAula != 1)
        {
            printf("\n\nJa existe uma aula da mesma UC marcada para esta data");
        }
        else
        {

            aulaOnline->horaInicio=aulaOnlineAux.horaInicio;
            aulaOnline->horaFim=aulaOnlineAux.horaFim;
            aulaOnline->data=aulaOnlineAux.data;

        }

    }
    while(horarioAula != 1);

}

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

float lerHoraAula(float inicio, float fim)
{

    /*
    Le a hora e os minutos devolvendo depois um float com a hora nas unidades e os minutos na parte decimal
    */
    float horaCompleta;
    int hora,minutos;

    hora=lerInteiro("\n\nInsire o inicio da aula\n\nhora", inicio, fim);

    if(hora<(int)fim)
    {
        minutos=lerInteiro("\n\nminutos", 0,59);
    }
    else
    {

        minutos=lerInteiro("\n\nminutos", 0,((fim-(int) fim)*100));
    }

    horaCompleta=hora+(minutos*0.01);

    return horaCompleta;
}

tipoAulaOnline lerDadosAulaOnline(tipoUnidadeCurricular uniCurricular, tipoAulaOnline aulasOnline[], int numAulas)
{

    tipoAulaOnline aulaOnline;
    int designacao,quantidadeAulas;
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
    lerHorarioCompletoAula(uniCurricular,&aulaOnline,aulasOnline, numAulas);

    lerString("\n\nNome do Docente: ", aulaOnline.nomeDocente, MAX_STRING);

    /*
    Verificar se a desginação da aula é única
    */
    do
    {
        lerString("\n\nDesignacao da aula: ", aulaOnline.designacao, MAX_STRING);
        designacao = procurarDesignacaoAula(aulasOnline, numAulas, aulaOnline.designacao);

        if(designacao != -1)
        {
            printf("\n\nA designacao da aula tem de ser unica");
        }
    }
    while( designacao != -1);

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
        }


    }


    return aulasOnline;

}
