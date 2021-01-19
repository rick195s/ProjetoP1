
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/funcoes_aulas.h"
#include "../headers/funcoes_uc.h"
#include "../headers/funcoes_ficheiros.h"
#include "../headers/funcoes_auxiliares.h"
#include "../headers/funcoes_menus.h"
#include "../headers/funcoes_acessos.h"

void gravarAulaOnline(tipoAulaOnline *aulaOnline, int *numAulasTerminadas)
{

    if(aulaOnline->estado == 1)
    {
        aulaOnline->gravada = 1;
        mostrarMensagem("A aula esta a ser gravda",1);
        (*numAulasTerminadas)++;
    }
    else
    {
        mostrarMensagem("A aula ainda nao foi iniciada",0);
    }
}

void terminarAulaOnline(tipoAulaOnline *aulaOnline,int *numAulasTerminadas)
{

    if(aulaOnline->estado == 1)
    {
        aulaOnline->estado = 2;
        mostrarMensagem("A aula foi terminada",1);
        (*numAulasTerminadas)++;
    }
    else
    {
        mostrarMensagem("A aula ainda nao foi iniciada",0);
    }

}

void iniciarAulaOnline(tipoAulaOnline *aulaOnline)
{
    if(aulaOnline->estado == 0)
    {
        aulaOnline->estado = 1;
        mostrarMensagem("A aula foi iniciada",1);
    }
    else
    {
        if(aulaOnline->estado == 1)
        {
            mostrarMensagem("A aula ja esta a decorrer",0);
        }

    }

}

void administradorAulaOnline(tipoAulaOnline aulasOnline[], int numAulas, int *numAulasTerminadas,int *numAulasGravadas)
{

    char designacao[MAX_STRING],opcao;
    int posicaoAula;

    lerString("\n\nInsira a designacao da aula que pretende alterar o estado: ", designacao, MAX_STRING);

    posicaoAula=procurarDesignacaoAula(aulasOnline, numAulas, designacao);

    if(posicaoAula == -1 || aulasOnline[posicaoAula].estado == 2 )
    {
        if(posicaoAula == -1)
        {
            mostrarMensagem("Nao existe nenhuma aula com a designacao que inseriu",0);
        }
        else
        {
            mostrarMensagem("Nao pode alterar uma aula que ja terminou",0);
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
                terminarAulaOnline(&aulasOnline[posicaoAula],&(*numAulasTerminadas));
                break;
            case 'G':
                gravarAulaOnline(&aulasOnline[posicaoAula],&(*numAulasGravadas));
                break;
            case 'V':
                break;
            default:
                mostrarMensagem("Opcao invalida",0);
                break;

            }
        }
        while(opcao != 'V' && aulasOnline[posicaoAula].estado != 2);


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
        mostrarMensagem("Nao existem aulas com a desginacao igual a que introduziu",0);
    }
    else
    {
        opcao=lerInteiro("\n\nOpcoes:\n\t0 - Alterar Agendamento\n\t1 - Eliminar Aula",0,1);

        if(opcao == 0)
        {
            posicaoUC=procurarUC(aulasOnline[posicaoAula].codigoUC, uniCurriculares, numUCs);
            if(posicaoUC == -1)
            {
                mostrarMensagem("Ocorreu um erro ao procurar a unidade curricular correspondente a aula que pretende alterar",0);
            }
            else
            {
                if(aulasOnline[posicaoAula].estado != 0)
                {
                    mostrarMensagem("O agendamento da aula nao pode ser alterado pois a aula esta a decorrer ou ja foi realizada",0);
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
                mostrarMensagem("Ocorreu um erro a reservar mais memoria ao eliminar aula online",0);
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

void listarInformacoesUCdaAula(tipoAulaOnline aulasOnline[], int numAulas, tipoUnidadeCurricular uniCurriculares[], int numUCs, tipoAcessoAula acessosAula[], int numAcessos)
{

    int posicaoUC, posicaoAula,i;
    char desginacao[MAX_STRING];

    lerString("\n\nInsira a designacao da aula: ", desginacao, MAX_STRING);
    posicaoAula=procurarDesignacaoAula(aulasOnline, numAulas, desginacao);
    if(posicaoAula == -1)
    {
        mostrarMensagem("Nao existe nenhuma aula com a desgnacao que inseriu",0);
    }
    else
    {
        posicaoUC=procurarUC(aulasOnline[posicaoAula].codigoUC,uniCurriculares,numUCs);
        listarAulaOnline(aulasOnline[posicaoAula],acessosAula, numAcessos);

        printf("\n\nInformacoes da UC:");
        printf("\n\n\tDesginacao: %s", uniCurriculares[posicaoUC].designacao);
        printf("\n\n\tQuantidade de Aulas por agendar: ");
        for(i=0; i<TIPOS_AULA; i++)
        {
            printf("\n\n\t\t%s: %d", uniCurriculares[posicaoUC].aulasOnline[i].designacao, (uniCurriculares[posicaoUC].aulasOnline[i].quantidade-quantidadeAulasTipo(uniCurriculares[posicaoUC],i,aulasOnline,numAulas,0)));
        }
    }

}

void listarAulaOnline(tipoAulaOnline aulaOnline, tipoAcessoAula acessosAula[], int numAcessos)
{
    int i, acessoGravacoes=0, estudantesPresent=0;

    printf("\n\nDesignacao da Aula: %s", aulaOnline.designacao);
    printf("\n\n\tCodigo da UC: %d", aulaOnline.codigoUC);
    printf("\n\n\tNome do Docente: %s", aulaOnline.nomeDocente);
    printf("\n\n\tData:\n\t\tHora de Inicio: %.2f", aulaOnline.horaInicio);
    printf("\n\n\t\tHora de Fim: %.2f", aulaOnline.horaFim);
    printf("\n\n\t\t%d/%d/%d", aulaOnline.data.dia, aulaOnline.data.mes, aulaOnline.data.ano);
    if(aulaOnline.estado == 0)
    {
        printf("\n\n\tEstado: Agendada");
    }
    else if(aulaOnline.estado == 1)
    {
        printf("\n\n\tEstado: A decorrer");
    }
    else
    {
        printf("\n\n\tEstado: Terminada");

        for(i=0;i<numAcessos;i++){

            if(strcmp(acessosAula[i].designacaoAula,aulaOnline.designacao)==0){
                if(acessosAula[i].tipoAcesso == 0){
                    estudantesPresent++;
                }else{
                    acessoGravacoes++;
                }
            }
        }
        printf("\n\n\tQuantidade de alunos presentes: %d", estudantesPresent);
        printf("\n\n\tQuantidade de acessos as gravacoes: %d", acessoGravacoes);
    }


    if(aulaOnline.gravada == 0)
    {
        printf("\n\n\tGravada: Nao");
    }
    else
    {
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

            i=numAulas;
        }

    }


    return posicaoAula;
}

int quantidadeAulasTipo(tipoUnidadeCurricular uniCurricular, int tipoAula, tipoAulaOnline aulasOnline[], int numAulas, int op)
{


    /*

    op:
        0-quantidade de aulas realizadas por tipo
        1-quantidade de aulas agendadas por tipo
        2-quantidade de aulas que existem na uc por tipo

    */


    int i,quantidade=0;

    for(i=0; i<numAulas; i++)
    {
        if(aulasOnline[i].codigoUC == uniCurricular.codigo && aulasOnline[i].tipoAula == tipoAula)
        {
            if(op == 0 && aulasOnline[i].estado == 2)
            {
                quantidade++;
            }

            if(op == 1 && aulasOnline[i].estado == 0)
            {
                quantidade++;
            }

            if(op == 2){
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
            mostrarMensagem("Ja existe uma aula da mesma UC marcada para esta data",0);
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

            i=numAulas;
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
        quantidadeAulas = quantidadeAulasTipo(uniCurricular, aulaOnline.tipoAula, aulasOnline, numAulas,2);

        if(uniCurricular.aulasOnline[aulaOnline.tipoAula].quantidade == 0)
        {
            mostrarMensagem("Esta unidade curricular nao tem este tipo de aulas",0);
        }
        else if((uniCurricular.aulasOnline[aulaOnline.tipoAula].quantidade-quantidadeAulas) <= 0)
        {
            mostrarMensagem("Esta unidade curricular ja tem todas as aulas deste tipo agendadas",0);
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
            mostrarMensagem("A designacao da aula tem de ser unica",0);
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
        mostrarMensagem("A unidade curricular que introduziu nao existe",0);

    }
    else
    {
        aulasOnline = realloc(aulasOnline, (*numAulas+1)*sizeof(tipoAulaOnline));

        if(aulasOnline == NULL)
        {
            mostrarMensagem("Nao foi possivel reservar memoria para as aulas online ao agendar aula",0);
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
